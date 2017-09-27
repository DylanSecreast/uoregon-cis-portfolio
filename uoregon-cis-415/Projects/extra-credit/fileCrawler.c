/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Spring 2016 Prov. Sventek
 * Extra-credit Project: fileCrawler.c
 * 5/23/16
*/

#include "iterator.h"
#include "linkedlist.h"
#include "treeset.h"
#include "re.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

static char *NUM_THREADS;
static char *PATTERN;
static char *DIRECTORY;

int main(int argc, char *argv[]) {

  /* Get CRAWLER_THREADS environment variable if exists */
  if (getenv("CRAWLER_THREADS") != NULL) {
    NUM_THREADS = getenv("CRAWLER_THREADS");
  }
  else {
    NUM_THREADS = "2";
  }

  /* Get args */
  if (argc == 2) {
    PATTERN = argv[1];
    DIRECTORY = ".";
  } else if (argc == 3) {
    PATTERN = argv[1];
    DIRECTORY = argv[2];
  } else {
    fprintf(stderr, "Usage: %s 'pattern' directory\n", argv[0]);
    return -1;
  }

  





  return 0;
}
