/*
 * parmetricEQ.c
 *
 *  Created on: Feb 18, 2013
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "units.h"
//#include "Low.h"
//#include "Peak.h"
//#include "High.h"


void equalizer_init(void);
void equalizer(Int16* coeffs);//change
//void coefGen(double (*gainTbl)[2], Int16 gain, Int16 *c, float freq);


/* Define DSP system memory map */
#pragma DATA_ALIGN(XmitL1,2);	// Alignment is needed for dual accumulator store
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

// IIR filter related variables
#include "asmIIR.h"

//#define SECTIONS    3  // Number of 2nd order sections
//#define UNIT1 16384
//#define SCALE 1.5
//#define RDA (0.5/UNIT)			// Rounding
//#define RDB (0.5*SCALE/UNIT)	// Rounding
//Int16   c[SECTIONS*5]= // c[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
//{
//		// Fs = 48000 Hz
//		// low-Shelf filter, from ShelfFilter(8000,9,1,Fs,'L');
//		(Int16)(-0.97490725857763*UNIT-RDA),(Int16)(0.45796361924959*UNIT+RDA),
//		(Int16)(0.49359074290975*UNIT/SCALE+RDB), (Int16)(1.40356359688215*UNIT/SCALE+RDB), (Int16)(-0.53571653803533*UNIT/SCALE-RDB),
//		// Peak filer, from PeakFilter(12000,9,1,Fs);
//		(Int16)(0*UNIT),(Int16)(0.54103260702554*UNIT+RDA),
//		(Int16)(0.12374337032968*UNIT/SCALE+RDB), (Int16)(1.41728923669586*UNIT/SCALE+RDB), (Int16)(0*UNIT/SCALE),
//		// high-Shelf filter, from ShelfFilter(16000,9,1,Fs,'H');
//		(Int16)(0.97490725857763*UNIT+RDA), (Int16)(0.45796361924959*UNIT+RDA),
//		(Int16)(0.49359074290975*UNIT/SCALE+RDB), (Int16)(1.40356359688215*UNIT/SCALE+RDB), (Int16)(0.53571653803533*UNIT/SCALE+RDB)
//};






Int16   wl1[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wl2[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wr1[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wr2[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...







void equalizer_init(void)
{
	Int16 i;

	for (i=0; i<XMIT_BUFF_SIZE; i++)
	{
		XmitL1[i]=XmitR1[i]=XmitL2[i]=XmitR2[i]=0;
	}
    // Initialize IIR filter delay line
    for (i=0; i<SECTIONS*2;i++)
	{
        wl1[i] = wl2[i] = wr1[i] = wr2[i] = 0;
	}
}


void equalizer(Int16* coeffs)
{
	//Int32 n=0;
	Int16 j=1;
	//Int16 i;
	//printf("EQ status: \n");
	//printf("EQ off\n");
    /*
	while (1)			// Forever loop for the demo if status is set
    {
    	if (n++ == 0x2000000)
    	{
    		n = 0;
    		j=1;

    		if (j&1)
    		{
    			printf("EQ on\n");
    		}
    		else
    		{
    			printf("EQ off\n");
    		}
    	}
     */
        if((leftChannel == 1)&&(rightChannel == 1))
        {
        	leftChannel = 0;
        	rightChannel= 0;
            if((CurrentRxL_DMAChannel == 2)&&(CurrentRxR_DMAChannel == 2))
            {
            	if (j==1) // Apply EQ filter to the input audio data and send to output
            	{
            		asmIIR(RcvL1,XMIT_BUFF_SIZE,XmitL1,coeffs,SECTIONS,wl1);
            		asmIIR(RcvR1,XMIT_BUFF_SIZE,XmitR1,coeffs,SECTIONS,wr1);
            	}
            	/*
            	else  // Without EQ filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{

            			XmitL1[i] = RcvL1[i]>>1;
            			XmitR1[i] = RcvR1[i]>>1;
            		}
            	}
            	*/
            }
            else
            {
            	if (j==1) // Apply EQ filter to the input audio data and send to output
            	{

            		asmIIR(RcvL2,XMIT_BUFF_SIZE,XmitL2,coeffs,SECTIONS,wl2);
            		asmIIR(RcvR2,XMIT_BUFF_SIZE,XmitR2,coeffs,SECTIONS,wr2);
            	}
            	/*
            	else  // Without EQ filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{

            			XmitL2[i] = RcvL2[i]>>1;
            			XmitR2[i] = RcvR2[i]>>1;
            		}
            	}
            	*/
            }
        //}
    }
}






















