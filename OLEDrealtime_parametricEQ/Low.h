/*
 * Low.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Slade
 */

#ifndef INC_LOW_H_
#define INC_LOW_H_



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"


#define SECTIONS    3  // Number of 2nd order sections
#define UNIT 16384.0
#define SCALE 1.5
#define RDA (0.5/UNIT)			// Rounding
#define RDB (0.5*SCALE/UNIT)	// Rounding

Int16   Low_0dB[5]= // c[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
{
		// Fs = 48000 Hz
		// low-Shelf filter, from ShelfFilter.m;
		(Int16)(-1.997378586642692*UNIT-RDA),(Int16)(0.997385431570743*UNIT+RDA),
		(Int16)(0.997385431570743*UNIT/SCALE+RDB), (Int16)(1.000000000000000*UNIT/SCALE+RDB), (Int16)(-1.997378586642692*UNIT/SCALE-RDB)
};





#endif /* INC_LOW_H_ */
