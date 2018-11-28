/*
 * APRSBase91.h
 *
 *  Created on: 2018-10-21
 *      Author: vilisas
 */

#ifndef APRSBASE91_H_
#define APRSBASE91_H_

namespace std {

class APRS_Base91 {
public:
	const unsigned char _riba = 10;
	const unsigned char _base = 91;
	const unsigned char _shift = 33;
	APRS_Base91();
	virtual ~APRS_Base91();
	unsigned int encode(char*, unsigned int);
	unsigned int decode(char*);
};

} /* namespace std */

#endif /* APRSBASE91_H_ */
