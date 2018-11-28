/*
 * APRSBase91.cpp
 *
 *  Created on: 2018-10-21
 *      Author: vilisas
 */

#include "APRSBase91.h"
#include <cmath>
#include <iostream>

namespace std {

APRS_Base91::APRS_Base91() {
	// TODO Auto-generated constructor stub

}

APRS_Base91::~APRS_Base91() {
	// TODO Auto-generated destructor stub
}
/**
 * takes unsigned integer
 * returns byte count, puts base91 encoded bytes (+ null terminator) in buffer string.
 */
unsigned int APRS_Base91::encode(char* buffer, unsigned int skaicius) {

	//static char buffer[8];
	unsigned int i = 0;
	unsigned int powered = 1;
	while (skaicius >= powered) {
		powered *= 91;
		i++;
	}
	for (unsigned int j = 0; j < i; j++) {
		powered /= 91;
		char byte = (skaicius / powered) % this->_base;
		byte += this->_shift;
		buffer[j] = byte;
//		cout << (int) byte << endl;
	}
	buffer[i] = 0;
	return i;
}

/**
 * takes null terminated base91 string
 * returns decoded integer
 */
unsigned int APRS_Base91::decode(char * buffer){

	int i = 0;
	unsigned int output = 0;
	// randam ilgi, null terminated arba paieskos riba
	while (buffer[i] != 0 && i < this->_riba) {
		i++;
	}
	if (i == this->_riba) return 0; 	// = kazkas nepavyko

	unsigned int daugiklis = 1;
	for (int j = i-1; j>= 0; j--){
		output += (buffer[j]-this->_shift) * daugiklis;
//		cout << (buffer[j]-this->_shift) << endl;
		daugiklis *= this->_base;
	}
	return output;

}

} /* namespace std */
