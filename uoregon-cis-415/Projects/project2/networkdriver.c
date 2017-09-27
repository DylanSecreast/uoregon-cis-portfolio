/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Spring 2016 - Prof. Sventek
 * Project 2 - networkdriver.c
 * 5/23/16
 *
 * This is my own work except for the
 * base code provided by Prov. Sventek
*/

#include "BoundedBuffer.h"
#include "destination.h"
#include "diagnostics.h"
#include "freepacketdescriptorstore.h"
#include "freepacketdescriptorstore__full.h"
#include "networkdevice.h"
#include "networkdriver.h"
#include "packetdescriptor.h"
#include "packetdescriptorcreator.h"
#include "pid.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


/* Global Variables */
static BoundedBuffer *in_BB[MAX_PID + 1];
static BoundedBuffer *out_BB;
static FreePacketDescriptorStore *fpds;
static NetworkDevice *net_dev;

/* Helper functions */
static void *in_thread();
static void *out_thread();


/* Initialize network driver for network device */
void init_network_driver(NetworkDevice			*nd,
			 void	 	 		*mem_start,
			 unsigned long 	 		mem_length,
			 FreePacketDescriptorStore	**fpds_ptr)
{
  /* Declare local variables */
  int i, in_create_result, out_create_result;
  pthread_t in_net_t, out_net_t;

  /* Initialize network device */
  net_dev = nd;

  /* Create and initialize FreePacketDescriptorStore */
  *fpds_ptr = create_fpds();
  fpds = *fpds_ptr;
  create_free_packet_descriptors(fpds, mem_start, mem_length);

  /* Create array of BB for incoming packets */
  for (i = 0; i <= MAX_PID; i++) {
    in_BB[i] = createBB(4);
  }

  /* Create BB for outgoing packets */
  out_BB = createBB(MAX_PID);

  /* Create incoming and outgoing threads */
  in_create_result = pthread_create(&in_net_t, NULL, in_thread, NULL);
  out_create_result = pthread_create(&out_net_t, NULL, out_thread, NULL);

  /* Verify successful thread creation */
  if (in_create_result != 0) {
    DIAGNOSTICS("ERROR: Unable to create in_net_t pthread");
  }
  else if (out_create_result != 0) {
    DIAGNOSTICS("ERROR: Unable to create out_net_t pthread");
  }

} 


void blocking_get_packet(PacketDescriptor **pd, PID pid)
{
  *pd = blockingReadBB(in_BB[pid]);
} 


int nonblocking_get_packet(PacketDescriptor **pd, PID pid)
{
  return nonblockingReadBB(in_BB[pid], pd);
}


void blocking_send_packet(PacketDescriptor *pd)
{
  blockingWriteBB(out_BB, pd);
} 


int nonblocking_send_packet(PacketDescriptor *pd)
{
  return nonblockingWriteBB(out_BB, pd);
}


/* Helper function used in creation of new incoming thread(s) */
static void *in_thread() {
  /* Declare local variables */
  PacketDescriptor *pd;
  PID pid;

  while(1) {
    /* If packet descriptor is available... */
    if (nonblocking_get_pd(fpds, &pd) == 1) {
      /* Initialize and register packet descriptor to network device */
      init_packet_descriptor(&pd);
      register_receiving_packetdescriptor(net_dev, &pd);
      /* Blocking wait for network device to receive packet */
      await_incoming_packet(net_dev);
      /* Get PID of application from packet descriptor */
      pid = packet_descriptor_get_pid(&pd);

      /* Attempt non-blocking write until successful */
      while(1) {
        if (nonblockingWriteBB(in_BB[pid], &pd) == 1) break;
      }

      /* Return packet descriptor to free packet descriptor store, first attempting non-blocking, then blocking if unsuccessful */
      if (nonblocking_put_pd(fpds, &pd) == 0) {
        blocking_put_pd(fpds, &pd);
      }
    }
  }

  return NULL; /* Required to supress compiler warning */
}


/* Helper function used in creation of new outgoing thread(s) */
static void *out_thread() {
  /* Initialize local variables */
  int i;
  PacketDescriptor *pd;
  
  while(1) {
    /* Get packet descriptor from outgoing BB */
    if (nonblockingReadBB(out_BB, &pd) == 0) {
      pd = blockingReadBB(out_BB);
    }

    /* Only attempt to send packet up to 4 times, if necessary */
    for (i = 0; i <= 3; i++) {
      /* Attempt to send packet */
      if (send_packet(net_dev, pd) == 1) {
        /* If successful, stop trying */
        break;
      }
      /* Else, if failed, wait and try again if under 4 tries total */
      else {
        /* Non-busy wait in linearly increasing time for consecutive fails */
        usleep(10 * i);
      }
    }

    /* Return packet descriptor to free packet descriptor store if successful, or after failing to send 4 times */
    if (nonblocking_put_pd(fpds, &pd) == 0) {
      blocking_put_pd(fpds, &pd);
    }
  }
  return NULL; /* Required to supress compiler warning */
}

