#include "star.h"
//just checking the testing this isn't final submission

// function you may want to use to help debugging
//   taken from https://en.wikipedia.org/wiki/Bitwise_operations_in_C
// goal: prints a binary representation of an (unsigned) int
// param x: variable to print the value of
void showbits(unsigned int x) {
  for (int i = (8 * sizeof(unsigned int)) - 1; i >= 0; i--) {
    putchar(x & (1u << i) ? '1' : '0');
  }
  printf("\n");
}

// goal: packs an azimuth, elevation, and brightness into a "star"
// param azimuth: desired value of the star's azimuth
//   legal range: 0 to 359 (inclusive)
// param elevation: desired value of the star's elevation
//   legal range: -90 to 90 (inclusive)
// param brightness: desired value of the star's brightness
//   legal range: 0 to 2^15 - 1 (32767) (inclusive)
// return: value representing associated star, 0 if any field outside valid
// range
//   9 most significant bits hold the azimuth
//   8 middle bits hold the elevation (in two's complement form)
//   15 least significant bits hold the brightness
//
// TODO: Complete the function

unsigned int star(int azimuth, int elevation, int brightness) {
  unsigned int elev = elevation;
  elev = elev << 8;
  elev = elev >> 8;
  if(azimuth < 0 || azimuth > 359){
    return 0;
  }
  else if(elevation < -90 || elevation > 90){
    return 0;
  }
  else if(brightness < 0 || brightness > 32767){
    return 0;
  }
unsigned int u = azimuth<<23 | ((elev <<24)>>9) | brightness<<0;

  return u;
}

// goal: sets the azimuth of a "star"
// param azimuth: desired value of the star's azimuth
//   legal range: 0 to 359 (inclusive)
// param star: value of star to update
//   9 most significant bits hold the azimuth
//   rest should remain as-is
// return: value representing updated star, param star if azimuth outside legal
// range
//
// TODO: Complete the functions
unsigned int set_azimuth(unsigned int star, int azimuth) {
  if(azimuth < 0 || azimuth > 359){
    return star;
  }
  else{
    int mask = 0b00000000011111111111111111111111;
    int newField = (star & mask); 
    int newFull = ((azimuth << 23) & (~mask)); 
    int result = ((newField) | (newFull));
    return result;

  }
}

// goal: sets the elevation of a "star"
// param elevation: desired value of the star's elevation
//   legal range: -90 to 90 (inclusive)
// param star: value of star to update
//   8 middle bits hold the elevation (in two's complement form)
//   rest should remain as-is
// return: value representing updated star, param star if elevation outside
// legal range
//
// TODO: Complete the function
unsigned int set_elevation(unsigned int star, int elevation) {
  if(elevation < -90 || elevation > 90){
    return star;
  }
  unsigned int mask = 0b11111111100000000111111111111111;
  int newField = star & mask;
  int newFull = ((elevation << 24) >> 9) & (~mask);
  int result = newField | newFull;
  return result;
  
}

// goal: sets the brightness of a "star"
// param brightness: desired value of the star's brightness
//   legal range: 0 to 2^15 - 1 (32767) (inclusive)
// param star: value of star to update
//   15 least significant bits hold the brightness
//   rest should remain as-is
// return: value representing updated star, param star if brightness outside
// legal range
//
// TODO: Complete the function
unsigned int set_brightness(unsigned int star, int brightness) {
  if(brightness < 0 || brightness > 32767){
    return star;
  }
  int mask = 0b11111111111111111000000000000000;
  int newField = star & mask;
  int newFull = brightness & (~mask);
  int result = newField | newFull;
  return result;
}

// goal: gets the azimuth of a "star"
// param star: unsigned integer representing star
// return: value representing azimuth of star
//
// TODO: Complete the function
int get_azimuth(unsigned int star) {
  return (star >> 23);

}

// goal: gets the elevation of a "star"
// param star: unsigned integer representing star
// return: value representing elevation of star
//
// TODO: Complete the function
int get_elevation(unsigned int star) {
  int result = star << 9;
  result = result >> 24;
  return result;
}

// goal: gets the brightness of a "star"
// param star: unsigned integer representing star
// return: value representing brightness of star
//
// TODO: Complete the function
int get_brightness(unsigned int star) {
  int mask = (1 << 15) - 1;
  int result = star & mask;
  return result;
}

