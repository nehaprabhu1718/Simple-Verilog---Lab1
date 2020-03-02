/**
 * @file
 * Contains an implementation of the extractMessage function.
 */

#include <iostream> // might be useful for debugging
#include <assert.h>
#include "extractMessage.h"

using namespace std;

char *extractMessage(const char *message_in, int length) {
   // Length must be a multiple of 8
   assert((length % 8) == 0);

   // allocates an array for the output
   char *message_out = new char[length];
   for (int i=0; i<length; i++) {
   		message_out[i] = 0;    // Initialize all elements to zero.
	}

	// TODO: write your code here

  /* steps for ecryption : think of it as a rotated 2D array except you have to
  access bits using bit shifting/masking operations instead of being able to
  point index 1,j

  - basically input array is [210, 203, 222, ...] this is from Hello World
  - transform every bit at pos(i,j) to pos (7-j, 7-i) in output
  */
  int totalLength = 8;
  unsigned tempBit1;
  unsigned tempBit2;
  unsigned leastSigBit;
  unsigned tempBit;
  int index;

  //for each of the binary numbers

  for (int i = 0; i < length/totalLength; i++) {
    index = 0;
    tempBit = 0b0;
    leastSigBit = 0b1;


    while (index < totalLength) {
      for (int j = i*totalLength; j < (i+1)*totalLength; j++) {

        for (int k = 0; k < totalLength; k++) {

        }
        unsigned currentBit = message_in[j];


        tempBit1 = (currentBit & leastSigBit) << (j % totalLength);
        tempBit2 = tempBit1 >> index;
        tempBit = tempBit | tempBit2;
      }
      message_out[index + totalLength*i] = tempBit;
      //increment index counter
      index++;
      //initializing tempBit back
      tempBit = 0b0;
      //shifting lsb left
      leastSigBit <<= 1;

    }
  }
	return message_out;
}
