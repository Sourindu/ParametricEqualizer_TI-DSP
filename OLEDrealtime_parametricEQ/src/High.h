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
#include "units.h"

//
//#define SECTIONS    3  // Number of 2nd order sections
//#define UNIT 16384
//#define SCALE 3
//#define RDA (0.5/UNIT)			// Rounding
//#define RDB (0.5*SCALE/UNIT)	// Rounding



Int16   filt[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-0.974907258577634*UNIT-RDA),(Int16)(0.457963619249591*UNIT+RDA),
	(Int16)(0.493590742909751*UNIT/SCALE+RDB),(Int16)(1.403563596882147*UNIT/SCALE+RDB),(Int16)(-0.535716538035328*UNIT/SCALE-RDB),

//Peak Filter
(Int16)(-0.000000000000000*UNIT-RDA),(Int16)(0.541032607025535*UNIT+RDA),
(Int16)(0.123743370329679*UNIT/SCALE+RDB),(Int16)(1.417289236695856*UNIT/SCALE+RDB),(Int16)(-0.000000000000000*UNIT/SCALE-RDB),

//High Shelf Filter
(Int16)(0.974907258577634*UNIT+RDA),(Int16)(0.457963619249591*UNIT+RDA),
(Int16)(0.493590742909750*UNIT/SCALE+RDB),(Int16)(1.403563596882147*UNIT/SCALE+RDB),(Int16)(0.535716538035328*UNIT/SCALE+RDB),
};


/*--------------------------------------------------------------------------------------------------------------------------------
														-9dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_9dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.997977416201211*UNIT-RDA),(Int16)(0.997981494685296*UNIT+RDA),
	(Int16)(0.353854777122218*UNIT/SCALE+RDB),(Int16)(0.355057124324699*UNIT/SCALE+RDB),(Int16)(-0.708907822962832*UNIT/SCALE-RDB),
};


Int16   high_100Hz_9dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.989846608701099*UNIT-RDA),(Int16)(0.989948161138194*UNIT+RDA),
	(Int16)(0.350052755853042*UNIT/SCALE+RDB),(Int16)(0.356040255735874*UNIT/SCALE+RDB),(Int16)(-0.705991459151821*UNIT/SCALE-RDB),
};


Int16   high_500Hz_9dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.948255278995970*UNIT-RDA),(Int16)(0.950744254390572*UNIT+RDA),
	(Int16)(0.331806662108487*UNIT/SCALE+RDB),(Int16)(0.361146445119318*UNIT/SCALE+RDB),(Int16)(-0.690464131833203*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_9dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.720377230357687*UNIT-RDA),(Int16)(0.777165773168868*UNIT+RDA),
	(Int16)(0.258073950867723*UNIT/SCALE+RDB),(Int16)(0.390807864073585*UNIT/SCALE+RDB),(Int16)(-0.592093272130128*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_9dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-0.256460777404069*UNIT-RDA),(Int16)(0.341580354636813*UNIT+RDA),
	(Int16)(0.216933663207384*UNIT/SCALE+RDB),(Int16)(0.609129320506031*UNIT/SCALE+RDB),(Int16)(0.259056593519329*UNIT/SCALE+RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														-6dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_6dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.997794810658526*UNIT-RDA),(Int16)(0.997799657503859*UNIT+RDA),
	(Int16)(0.499857584662846*UNIT/SCALE+RDB),(Int16)(0.501415307857190*UNIT/SCALE+RDB),(Int16)(-1.001268045674702*UNIT/SCALE-RDB),
};


Int16   high_100Hz_6dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.988926018245026*UNIT-RDA),(Int16)(0.989046658284063*UNIT+RDA),
	(Int16)(0.494580254262024*UNIT/SCALE+RDB),(Int16)(0.502334626354740*UNIT/SCALE+RDB),(Int16)(-0.996794240577727*UNIT/SCALE-RDB),
};


Int16   high_500Hz_6dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.943476169479807*UNIT-RDA),(Int16)(0.946427421230950*UNIT+RDA),
	(Int16)(0.469167077214997*UNIT/SCALE+RDB),(Int16)(0.507093558513133*UNIT/SCALE+RDB),(Int16)(-0.973309383976987*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_6dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.693476564240183*UNIT-RDA),(Int16)(0.760121859959611*UNIT+RDA),
	(Int16)(0.364475824997157*UNIT/SCALE+RDB),(Int16)(0.534296543004658*UNIT/SCALE+RDB),(Int16)(-0.832127072282387*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_6dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-0.142656615895498*UNIT-RDA),(Int16)(0.335879628447731*UNIT+RDA),
	(Int16)(0.248481016986040*UNIT/SCALE+RDB),(Int16)(0.718642234350096*UNIT/SCALE+RDB),(Int16)(0.226099761216097*UNIT/SCALE+RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														-3dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_3dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.997595699346293*UNIT-RDA),(Int16)(0.997601459259962*UNIT+RDA),
	(Int16)(0.706088126270261*UNIT/SCALE+RDB),(Int16)(0.708106246795966*UNIT/SCALE+RDB),(Int16)(-1.414188613152557*UNIT/SCALE-RDB),
};


Int16   high_100Hz_3dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.987921490141713*UNIT-RDA),(Int16)(0.988064799500043*UNIT+RDA),
	(Int16)(0.698710400612223*UNIT/SCALE+RDB),(Int16)(0.708752620327448*UNIT/SCALE+RDB),(Int16)(-1.407319711581341*UNIT/SCALE-RDB),
};


Int16   high_500Hz_3dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.938246203942416*UNIT-RDA),(Int16)(0.941744834964300*UNIT+RDA),
	(Int16)(0.663072676197642*UNIT/SCALE+RDB),(Int16)(0.712088289034420*UNIT/SCALE+RDB),(Int16)(-1.371662334210179*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_3dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.663970566582711*UNIT-RDA),(Int16)(0.742088332707569*UNIT+RDA),
	(Int16)(0.513852889393640*UNIT/SCALE+RDB),(Int16)(0.730858513227104*UNIT/SCALE+RDB),(Int16)(-1.166593636495887*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_3dB_cut[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-0.027798407492476*UNIT-RDA),(Int16)(0.333429930764872*UNIT+RDA),
	(Int16)(0.286902437821209*UNIT/SCALE+RDB),(Int16)(0.847751255641747*UNIT/SCALE+RDB),(Int16)(0.170977829809440*UNIT/SCALE+RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														0dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_0dB[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.997378586642692*UNIT-RDA),(Int16)(0.997385431570743*UNIT+RDA),
	(Int16)(0.997385431570743*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.997378586642692*UNIT/SCALE-RDB),
};


Int16   high_100Hz_0dB[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),
};


Int16   high_500Hz_0dB[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_0dB[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_0dB[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(0.087266453698878*UNIT+RDA),(Int16)(0.334285602632287*UNIT+RDA),
	(Int16)(0.334285602632287*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(0.087266453698878*UNIT/SCALE+RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														3dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_3dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.997141840721597*UNIT-RDA),(Int16)(0.997149974972206*UNIT+RDA),
	(Int16)(1.408830191477482*UNIT/SCALE+RDB),(Int16)(1.412217452571267*UNIT/SCALE+RDB),(Int16)(-2.821039509798139*UNIT/SCALE-RDB),
};


Int16   high_100Hz_3dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.985628936272787*UNIT-RDA),(Int16)(0.985831135678079*UNIT+RDA),
	(Int16)(1.394089801098092*UNIT/SCALE+RDB),(Int16)(1.410929527904947*UNIT/SCALE+RDB),(Int16)(-2.804817129597745*UNIT/SCALE-RDB),
};


Int16   high_500Hz_3dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.926253184236650*UNIT-RDA),(Int16)(0.931166382607918*UNIT+RDA),
	(Int16)(1.322511336678897*UNIT/SCALE+RDB),(Int16)(1.404320244271934*UNIT/SCALE+RDB),(Int16)(-2.721918382579564*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_3dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.596196275178893*UNIT-RDA),(Int16)(0.703081212155174*UNIT+RDA),
	(Int16)(1.015365244130330*UNIT/SCALE+RDB),(Int16)(1.368253884851806*UNIT/SCALE+RDB),(Int16)(-2.276734192005856*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_3dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(0.201683959382650*UNIT+RDA),(Int16)(0.338427617667194*UNIT+RDA),
	(Int16)(0.393311043240468*UNIT/SCALE+RDB),(Int16)(1.179591293253823*UNIT/SCALE+RDB),(Int16)(-0.032790759444447*UNIT/SCALE-RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														6dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_6dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.996883681022115*UNIT-RDA),(Int16)(0.996893347351118*UNIT+RDA),
	(Int16)(1.989966484605305*UNIT/SCALE+RDB),(Int16)(1.994354748109952*UNIT/SCALE+RDB),(Int16)(-3.984311566386254*UNIT/SCALE-RDB),
};


Int16   high_100Hz_6dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.984323174795058*UNIT-RDA),(Int16)(0.984563333511395*UNIT+RDA),
	(Int16)(1.968900024792669*UNIT/SCALE+RDB),(Int16)(1.990704895771643*UNIT/SCALE+RDB),(Int16)(-3.959364761847975*UNIT/SCALE-RDB),
};


Int16   high_500Hz_6dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.919388183180362*UNIT-RDA),(Int16)(0.925208118578076*UNIT+RDA),
	(Int16)(1.866376342870542*UNIT/SCALE+RDB),(Int16)(1.972022683411983*UNIT/SCALE+RDB),(Int16)(-3.832579090884810*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_6dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.557425521795173*UNIT-RDA),(Int16)(0.682160178217697*UNIT+RDA),
	(Int16)(1.422659139220716*UNIT/SCALE+RDB),(Int16)(1.871619820664425*UNIT/SCALE+RDB),(Int16)(-3.169544303462617*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_6dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(0.314620753427566*UNIT+RDA),(Int16)(0.345764561431258*UNIT+RDA),
	(Int16)(0.467380864069983*UNIT/SCALE+RDB),(Int16)(1.391512984071065*UNIT/SCALE+RDB),(Int16)(-0.198508533282224*UNIT/SCALE-RDB),
};



/*--------------------------------------------------------------------------------------------------------------------------------
														9dB HIGH
--------------------------------------------------------------------------------------------------------------------------------*/
Int16   high_20Hz_9dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.996602164542225*UNIT-RDA),(Int16)(0.996613651381399*UNIT+RDA),
	(Int16)(2.810763187989558*UNIT/SCALE+RDB),(Int16)(2.816448203657228*UNIT/SCALE+RDB),(Int16)(-5.627199904807613*UNIT/SCALE-RDB),
};


Int16   high_100Hz_9dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.982897854324530*UNIT-RDA),(Int16)(0.983183081726372*UNIT+RDA),
	(Int16)(2.780438855410160*UNIT/SCALE+RDB),(Int16)(2.808671165380366*UNIT/SCALE+RDB),(Int16)(-5.588824793388683*UNIT/SCALE-RDB),
};


Int16   high_500Hz_9dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.999083282662227*UNIT-RDA),(Int16)(0.999084121879445*UNIT+RDA),
	(Int16)(0.999084121879445*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.999083282662227*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.998165727643948*UNIT-RDA),(Int16)(0.998169082975580*UNIT+RDA),
	(Int16)(0.998169082975580*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.998165727643948*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.911867446473362*UNIT-RDA),(Int16)(0.918759319363816*UNIT+RDA),
	(Int16)(2.632572650899160*UNIT/SCALE+RDB),(Int16)(2.768959831986197*UNIT/SCALE+RDB),(Int16)(-5.394640609994903*UNIT/SCALE-RDB),
};


Int16   high_2500Hz_9dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.986825285419483*UNIT-RDA),(Int16)(0.986995516145789*UNIT+RDA),
	(Int16)(0.986995516145789*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.986825285419483*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(-1.515049533441943*UNIT-RDA),(Int16)(0.660360178471563*UNIT+RDA),
	(Int16)(1.988613445666322*UNIT/SCALE+RDB),(Int16)(2.558802142762690*UNIT/SCALE+RDB),(Int16)(-4.402104943399391*UNIT/SCALE-RDB),
};


Int16   high_12500Hz_9dB_boost[SECTIONS*5]=
{
		//Low Shelf Filter
	(Int16)(-1.932521373898654*UNIT-RDA),(Int16)(0.936667928595110*UNIT+RDA),
	(Int16)(0.936667928595110*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.932521373898654*UNIT/SCALE-RDB),

		//Peak Filter
	(Int16)(-1.631625797093863*UNIT-RDA),(Int16)(0.723068837152569*UNIT+RDA),
	(Int16)(0.723068837152569*UNIT/SCALE+RDB),(Int16)(1.000000000000000*UNIT/SCALE+RDB),(Int16)(-1.631625797093863*UNIT/SCALE-RDB),

		//High Shelf Filter
	(Int16)(0.425289975048516*UNIT+RDA),(Int16)(0.356137286294424*UNIT+RDA),
	(Int16)(0.560768203298845*UNIT/SCALE+RDB),(Int16)(1.641687514187062*UNIT/SCALE+RDB),(Int16)(-0.421028456142968*UNIT/SCALE-RDB),
};




#endif /* INC_HIGH_H_ */
