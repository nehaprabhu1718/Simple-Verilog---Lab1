/**
 * @file
 * Contains an implementation of the countOnes function.
 */

unsigned countOnes(unsigned input) {
	// TODO: write your code here

	//step 1 of algorithm - shifting by 1
	unsigned rightMask1 = 0xAAAAAAAA;
	unsigned leftMask1 = 0x55555555;

	unsigned number1 = input & rightMask1;
	unsigned number2 = input & leftMask1;
	number1 = number1 >> 1;
	input = number1 + number2;


  //step 2 of algorithm - shifting by 2
	unsigned rightMask2 = 0xCCCCCCCC;
	unsigned leftMask2 = 0x33333333;

	number1 = input & rightMask2;
	number2 = input & leftMask2;
	number1 = number1 >> 2;
	input = number1 + number2;


  //step 3 of algorithm - shifting by 4
	unsigned rightMask3 = 0xF0F0F0F0;
	unsigned leftMask3 = 0x0F0F0F0F ;


	number1 = input & rightMask3;
	number2 = input & leftMask3;
	number1 = number1 >> 4;
	input = number1 + number2;

//step 5?
unsigned rightMask4 = 0xFF00FF00;
unsigned leftMask4 = 0x00FF00FF;

	number1 = input & rightMask4;
	number2 = input & leftMask4;
	number1 = number1 >> 8;
	input = number1 + number2;

//step 4
	unsigned rightMask5 = 0xFFFF0000;
	unsigned leftMask5 = 0x0000FFFF;

	number1 = input & rightMask5;
	number2 = input & leftMask5;
	number1 = number1 >> 16;
	input = number1 + number2;


	return input;
}
