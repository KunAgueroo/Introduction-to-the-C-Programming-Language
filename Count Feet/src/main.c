#include "countfeet.h"

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  printf("The total number of animals is %i (should be 99) %s\n", ENOUGH,
         ENOUGH == 99 ? "ok" : "INCORRECT");

  int num_chickens = 28;
  int num_rabbits = ENOUGH - 28;
  int num_legs = 2 * num_chickens + 4 * num_rabbits;
  printf("Given %i legs, there are %i chickens (should be 28) %s\n", num_legs,
         get_chickens(num_legs),
         get_chickens(num_legs) == 28 ? "ok" : "INCORRECT");
  printf("Given %i legs, there are %i rabbits (should be 71) %s\n", num_legs,
         get_rabbits(num_legs),
         get_rabbits(num_legs) == 71 ? "ok" : "INCORRECT");

  num_chickens = 53;
  num_rabbits = ENOUGH - 53;
  num_legs = 2 * num_chickens + 4 * num_rabbits;
  printf("Given %i legs, there are %i chickens (should be 53) %s\n", num_legs,
         get_chickens(num_legs),
         get_chickens(num_legs) == 53 ? "ok" : "INCORRECT");
  printf("Given %i legs, there are %i rabbits (should be 46) %s\n", num_legs,
         get_rabbits(num_legs),
         get_rabbits(num_legs) == 46 ? "ok" : "INCORRECT");
}
