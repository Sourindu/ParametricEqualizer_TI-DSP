/*
 * High.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Slade
 */

#ifndef INC_HIGH_H_
#define INC_HIGH_H_




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"


#define SECTIONS    3  // Number of 2nd order sections
#define UNIT 16384.0
#define SCALE 1.5
#define RDA (0.5/UNIT)			// Rounding
#define RDB (0.5*SCALE/UNIT)	// Rounding

//Int16  High_0dB[5]= {(Int16)(-1.997378586642692*UNIT+RDA), (Int16)(0.997385431570743*UNIT+RDA),(Int16)(0.997385431570743*UNIT/SCALE+RDB), (Int16)(1.000000000000000*UNIT/SCALE+RDB), (Int16)(-1.997378586642692*UNIT/SCALE+RDB)};


//Int16  High_500Hz_9dB_cut[5]= {(Int16)(-1.948255278995970*UNIT+RDA), (Int16)(0.950744254390572*UNIT+RDA),(Int16)(0.331806662108487*UNIT/SCALE+RDB), (Int16)(0.361146445119318*UNIT/SCALE+RDB), (Int16)(-0.690464131833203*UNIT/SCALE+RDB)};

//-1.948255278995970   0.950744254390572   0.331806662108487   0.361146445119318  -0.690464131833203

#endif /* INC_HIGH_H_ */
