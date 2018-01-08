/*
 * Peak.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Slade
 */

#ifndef INC_PEAK_H_
#define INC_PEAK_H_


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"


#define SECTIONS    3  // Number of 2nd order sections
#define UNIT 16384.0
#define SCALE 1.5
#define RDA (0.5/UNIT)			// Rounding
#define RDB (0.5*SCALE/UNIT)	// Rounding

Int16   Peak_0dB[5]= // c[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
{
		// Fs = 48000 Hz
		// Peak filter, from PeakFilter.m;
		(Int16)(-1.994770854193204*UNIT),(Int16)(0.994777690184672*UNIT+RDA),
		(Int16)(0.994777690184672*UNIT/SCALE+RDB), (Int16)(1.000000000000000*UNIT/SCALE+RDB), (Int16)(-1.994770854193204*UNIT/SCALE)
};




Int16  Peak_20Hz_9dB_boost[5]= // c[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
{
		// Fs = 48000 Hz
		// Peak filter, from PeakFilter.m;
		(Int16)(-1.996879136777393*UNIT),(Int16)(0.996885979993851*UNIT+RDA),
		(Int16)(0.994054739580453*UNIT/SCALE+RDB), (Int16)(1.002831240413399*UNIT/SCALE+RDB), (Int16)(-1.996879136777393*UNIT/SCALE)
};


Int16   Peak_12500Hz_9dB_boost[5]= // c[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
{
		// Fs = 48000 Hz
		// Peak filter, from PeakFilter.m;
		(Int16)(0.082041735216401*UNIT),(Int16)(0.254400763115014*UNIT+RDA),
		(Int16)(-0.423491699842717*UNIT/SCALE+RDB), (Int16)(1.677892462957731*UNIT/SCALE+RDB), (Int16)(0.082041735216401*UNIT/SCALE)
};








#endif /* INC_PEAK_H_ */
