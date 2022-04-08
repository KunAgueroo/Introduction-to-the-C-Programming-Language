#include "star.h"

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  unsigned int zenith = star(359, 90, 32767);
  unsigned int nadir = star(0, -90, 0);

  printf("zenith in binary is: 0b");
  showbits(zenith);
  printf("binary should be:    0b10110011101011010111111111111111 %s\n",
         zenith == 0b10110011101011010111111111111111 ? "ok" : "INCORRECT");

  printf("nadir in binary is:  0b");
  showbits(nadir);
  printf("binary should be:    0b00000000010100110000000000000000 %s\n",
         nadir == 0b00000000010100110000000000000000 ? "ok" : "INCORRECT");

  unsigned int hoshi = zenith;

  hoshi = set_azimuth(hoshi, 153);
  printf("hoshi in binary is:  0b");
  showbits(hoshi);
  printf("binary should be:    0b01001100101011010111111111111111 %s\n",
         hoshi == 0b01001100101011010111111111111111 ? "ok" : "INCORRECT");

  hoshi = set_elevation(hoshi, -60);
  printf("hoshi in binary is:  0b");
  showbits(hoshi);
  printf("binary should be:    0b01001100111000100111111111111111 %s\n",
         hoshi == 0b01001100111000100111111111111111 ? "ok" : "INCORRECT");

  hoshi = set_brightness(hoshi, 31415);
  printf("hoshi in binary is:  0b");
  showbits(hoshi);
  printf("binary should be:    0b01001100111000100111101010110111 %s\n",
         hoshi == 0b01001100111000100111101010110111 ? "ok" : "INCORRECT");

  int azi = get_azimuth(hoshi), ele = get_elevation(hoshi),
      bri = get_brightness(hoshi);
  printf("Azimuth: %i (should be 153) %s\n", azi,
         azi == 153 ? "ok" : "INCORRECT");
  printf("Elevation: %i (should be -60) %s\n", ele,
         ele == -60 ? "ok" : "INCORRECT");
  printf("Brightness: %i (should be 31415) %s\n", bri,
         bri == 31415 ? "ok" : "INCORRECT");
}
