/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Project 1 - Part 1
 * 4/26/16
 *
 * This is my own work except for the following:
 *    - p1fxns.h and p1fxns.c provided by Prof. Sventek
 *    - Proc struct and addProc() modeled after: piazza.com/class/il1f5y5z5ru6kw?cid=61
*/

#include <stdio.h>    // stdin, BUFSIZ
#include <unistd.h>   // STDIN_FILENO
#include <stdlib.h>   // malloc, remalloc
#include "p1fxns.h"   // Subroutines for Project 1 by Prof. Sventek

#define DEFAULT_PROCS 25

int nProcs = 0;
typedef struct proc {
  int pid;
  char commandLine;
} Proc;
Proc *procs = NULL;
int sProcs = -1;

static void addProc(int pid, char commandLine) {
  if (sProcs < 0) {
    // initial allocation of array of Proc structures of size DEFAULT_PROCS
    procs = malloc(DEFAULT_PROCS * sizeof(procs));
    sProcs = DEFAULT_PROCS;
  } else if (sProcs <= nProcs) {
      // realloc array of Proc structures of size sProcs + DEFAULT_PROCS
      procs = realloc(procs, (sProcs + DEFAULT_PROCS) * sizeof(procs));
      sProcs += DEFAULT_PROCS;
  }
  // fill in procs[nProcs]
  procs[nProcs].pid = pid;
  procs[nProcs].commandLine = commandLine;
  nProcs++;
}

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
}

static void freeMem() {
  if (procs != NULL)
    free(procs);
  if (returnArray != NULL)
    free(returnArray);
  if (temp != NULL)
    free(temp);
}

int main(int argc, char *argv[]) {
  char buf[BUFSIZ];
  int endLine;
  char *execute = NULL;
  int pid;

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

  int i;
  for (i = 0; i < nProcs; i++) {
    wait(&procs[i].pid);
  }
  


  freeMem();
  
} // end main()
