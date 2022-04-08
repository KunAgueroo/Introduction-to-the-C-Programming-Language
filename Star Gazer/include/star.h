#include <stdio.h>

#ifndef STAR_H
#define STAR_H

// function you may want to use to help debugging
//   taken from https://en.wikipedia.org/wiki/Bitwise_operations_in_C
// goal: prints a binary representation of an (unsigned) int
// param x: variable to print the value of
void showbits(unsigned int x);

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
unsigned int star(int azimuth, int elevation, int brightness);

// goal: sets the azimuth of a "star"
// param azimuth: desired value of the star's azimuth
//   legal range: 0 to 359 (inclusive)
// param star: value of star to update
//   9 most significant bits hold the azimuth
//   rest should remain as-is
// return: value representing updated star, param star if azimuth outside legal
// range
unsigned int set_azimuth(unsigned int star, int azimuth);

// goal: sets the elevation of a "star"
// param elevation: desired value of the star's elevation
//   legal range: -90 to 90 (inclusive)
// param star: value of star to update
//   8 middle bits hold the elevation (in two's complement form)
//   rest should remain as-is
// return: value representing updated star, param star if elevation outside
// legal range
unsigned int set_elevation(unsigned int star, int elevation);

// goal: sets the brightness of a "star"
// param brightness: desired value of the star's brightness
//   legal range: 0 to 2^15 - 1 (32767) (inclusive)
// param star: value of star to update
//   15 least significant bits hold the brightness
//   rest should remain as-is
// return: value representing updated star, param star if brightness outside
// legal range
unsigned int set_brightness(unsigned int star, int brightness);

// goal: gets the azimuth of a "star"
// param star: unsigned integer representing star
// return: value representing azimuth of star
int get_azimuth(unsigned int star);

// goal: gets the elevation of a "star"
// param star: unsigned integer representing star
// return: value representing elevation of star
int get_elevation(unsigned int star);

// goal: gets the brightness of a "star"
// param star: unsigned integer representing star
// return: value representing brightness of star
int get_brightness(unsigned int star);

#endif