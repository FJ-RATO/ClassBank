/*
 * Joaquim Madeira - February 22, 2020
 */

#include <stdio.h>

#include "elapsed_time.h"

/* definition of the 64-bit unsigned integer type */
typedef unsigned long long u64;

int main(void) {
  /* Large CONSTANT values */

  const u64 SMALLER = 100;  // 10^1

  const u64 LARGER = 1000;  // 10^3

  const u64 VLARGER = 10000; //10⁴

  /* FIRST TEST */

  (void)elapsed_time();

  for (u64 i = 0; i < SMALLER; i++) {
    for (u64 j = 0; j< SMALLER; j++){
      /* DO NOTHING !! */
    }
  }

  double smallerRunningTime = elapsed_time();

  printf("\n");

  printf("Time spent for %20llu iterations : %12.9f\n", SMALLER,
         smallerRunningTime);

  printf("\n");

  /* SECOND TEST */

  (void)elapsed_time();

  for (u64 i = 0; i < LARGER; i++) {
    for(u64 j = 0; j < LARGER; j++){
      /* DO NOTHING !! */
    }
  }

  double largerRunningTime = elapsed_time();

  printf("\n");

  printf("Time spent for %20llu iterations : %12.9f\n", LARGER,
         largerRunningTime);

  printf("\n");


  // THIRD TEST

  (void)elapsed_time();

  for (u64 i = 0; i < VLARGER; i++) {
    for(u64 j = 0; j < VLARGER; j++){
      /* DO NOTHING !! */
    }
  }

  double vlargerRunningTime = elapsed_time();

  printf("\n");

  printf("Time spent for %20llu iterations : %12.9f\n", VLARGER,
         vlargerRunningTime);

  printf("\n");

  return 0;
}
