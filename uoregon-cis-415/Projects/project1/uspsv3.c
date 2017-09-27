/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Project 1 - Part 3
 * 5/1/16
 *
 * This is my own work except for the following:
 *    - p1fxns.h and p1fxns.c provided by Prof. Sventek
 *    - Proc struct and addProc() modeled after piazza #61
 *    - sigHandler() and SIG_ERR check modeled after piazza #63
 *    - SIGCHLD termination catch modeled after piazza #86
*/

#include <stdio.h>    // stdin, BUFSIZ
#include <unistd.h>   // STDIN_FILENO, alarm
#include <stdlib.h>   // malloc, remalloc
#include <signal.h>   // SIGUSR1, SIGSTOP, SIGCONT, SIGCHLD
#include "p1fxns.h"   // Subroutines for Project 1 by Prof. Sventek

#define DEFAULT_PROCS 25

int nProcs = 0;
int sProcs = -1;
int dProcs = 0;

typedef struct proc {
  int pid;
  char commandLine;
  int status;
} Proc;
Proc *procs = NULL;

static void addProc(int pid, char commandLine) {
  if (sProcs < 0) {
    procs = malloc(DEFAULT_PROCS * sizeof(procs));
    sProcs = DEFAULT_PROCS;
  } else if (sProcs <= nProcs) {
      procs = realloc(procs, (sProcs + DEFAULT_PROCS) * sizeof(procs));
      sProcs += DEFAULT_PROCS;
  }
  procs[nProcs].pid = pid;
  procs[nProcs].commandLine = commandLine;
  procs[nProcs].status = 0;
  nProcs++;
}  // end addProc()

char **returnArray = NULL;
char *temp = NULL;
static char **getArguments(char *execute) {
  returnArray = malloc(DEFAULT_PROCS * sizeof(char*));
  temp = (char*)malloc(DEFAULT_PROCS * sizeof(char));

  int i;
  for (i = 0; i < DEFAULT_PROCS; i++) {
    returnArray[i] = NULL;
  }

  i = 0;
  int j = 0;
  while (j > -1) {
    j = p1getword(execute, j, temp);
    if (j > -1) {
      returnArray[i] = p1strdup(temp);
    }
    i++;
  }

  free(temp);
  return returnArray;
}  // end getArguments()

static void freeMem() {
  if (procs != NULL)
    free(procs);
  if (returnArray != NULL)
    free(returnArray);
}  // end freeMem()

int sigusrReceived = 0;
int i = 0;
static void sigHandler(int sig) {
  if (sig == SIGUSR1) {
    sigusrReceived++;
  }
  else if (sig == SIGALRM) {
    if (procs[i--].status == 1) {	// If previous proc is running
      kill(procs[i--].pid, SIGSTOP);	// Stop proc
    }

    if (procs[i].status == 0) {		// If next proc is waiting
      procs[i].status = 1;		// Set status to running (1)
      kill(procs[i].pid, SIGUSR1);	// Run proc
    }
    else if (procs[i].status == 1) {	// If next proc is stopped
      kill(procs[i].pid, SIGCONT);	// Continue proc
    }

    if (i == nProcs) {			// If reached end of procs[]
      i = 0;				// Start from beginning
    }
    else {
      i++;
    }

    alarm(2);				// Reset alarm
  }
  else if (sig == SIGCHLD) {
    pid_t pid;
    int status;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
      dProcs++;
    }
  }

}  // end sigHandler()

int main(int argc, char *argv[]) {
  char buf[2048];
  int endLine;
  char *execute = NULL;
  int pid;

  if (signal(SIGUSR1, sigHandler) == SIG_ERR) {
    p1perror(1, "SIGUSR1 error");
    return 1;
  }
  if (signal(SIGCONT, sigHandler) == SIG_ERR) {
    p1perror(1, "SIGCONT error");
    return 1;
  }
  if (signal(SIGALRM, sigHandler) == SIG_ERR) {
    p1perror(1, "SIGALRM error");
    return 1;
  }
  if (signal(SIGCHLD, sigHandler) == SIG_ERR) {
    p1perror(1, "SIGCHLD error");
    return 1;
  }

  while (p1getline(STDIN_FILENO, buf, BUFSIZ) != 0) {
    endLine = p1strchr(buf, '\n');
    buf[endLine] = '\0';
    execute = p1strdup(buf);
    pid = fork();

    if (pid < 0) {
      p1perror(1, "fork error");
      freeMem();
      free(execute);
      return 1;

    } else if (pid == 0) {	// Child Process
       
        while (sigusrReceived < 1) {
          sleep(1);
        }
        sigusrReceived = 0;

        char **arguments = getArguments(execute);
        if (execvp(arguments[0], arguments) == -1) {
          p1perror(1, "execute error");
          freeMem();
          free(execute);
          free(arguments);
          return 1;
        }
        free(arguments);

    } else if (pid > 0) {	// Parent Process
        addProc(pid, *execute);
    }

    free(execute);
  }
  
  alarm(2);
  while (dProcs < nProcs) {
    sleep(1);
  }

  //freeMem();
  
} // end main()
