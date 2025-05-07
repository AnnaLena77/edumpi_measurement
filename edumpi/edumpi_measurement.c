#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <math.h>
#include <sys/queue.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/mman.h>
//#include <libpq-fe.h>
#include <pthread.h>
#include <sched.h>
#include <hwloc.h>

#include "edumpi_measurement.h"

void test_function(void){
    printf("test from edumpi_measurement.c\n");
}
