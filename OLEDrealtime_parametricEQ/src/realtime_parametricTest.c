 /*
 * realtime_parmetricTest.c
 *
 *  Created on: Nov 3, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"
#include "i2s.h"
#include "dma.h"
#include "dmaBuff.h"
#include "Peak.h"
#include "Low.h"
#include "High.h"
#include "oled.h"
#include "pushbuttons.h"
#include "sar.h"


#define SAMPLES_PER_SECOND 48000L

unsigned long int i = 0;
unsigned int Step = 1;
unsigned int LastStep = 99;
unsigned int delay = 0, lobo = 0;


extern void AIC3204_init(Uint32, Int16, Int16);
extern void equalizer_init(void);
extern void equalizer(Int16* coeffs);//change arg to Int16*

#define IER0        *(volatile unsigned *)0x0000

#define SF48KHz			48000
#define DAC_GAIN		6		// 6dB range: -6dB to 29dB
#define ADC_GAIN		3		// 3dB range: 0dB to 46dB



void main(void)
{
	setDMA_address();		// DMA address setup for each buffer

    asm(" BCLR ST1_INTM");	// Disable all interrupts
    IER0 = 0x0110;      	// Enable DMA interrupt

    set_i2s0_slave();		// Set I2S
    AIC3204_init(SF48KHz, DAC_GAIN, (Uint16)ADC_GAIN);  // Set AIC3204
	enable_i2s0();

	enable_dma_int();		// Set up and enable DMA
    set_dma0_ch0_i2s0_Lout(XMIT_BUFF_SIZE);
    set_dma0_ch1_i2s0_Rout(XMIT_BUFF_SIZE);
    set_dma0_ch2_i2s0_Lin(XMIT_BUFF_SIZE);
	set_dma0_ch3_i2s0_Rin(XMIT_BUFF_SIZE);

	printf("Exp --- Equalizer experiment\n");
	//oled_display_message("                 ", "                   ");
	oled_display_message("Semester    Project", "ParametricEqualizer");
	equalizer_init();		// Initialize EQ

	for ( i = 0  ; i < SAMPLES_PER_SECOND * 600  ;i++  )
	{
			lobo = 0;
	 		Step = pushbuttons_read(40,Step);
	 		if ( Step == 1 )
	        {
	 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nFirst Step -> No Signal Processing\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 		      //oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 				oled_display_message("   SW12   ", "Choose HighLOwShelf");
	 			 				LastStep = Step;
	 			 			}

	        }
	 		else if(Step == 2)
	 		{

	 			if ( Step != LastStep )
	 			{

	 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 				printf("\n\nHigh 2500Hz -3Db Cutting\n");
	 				printf("SW1+SW2 -> Next Step");
	 			  //oled_display_message("Semester    Project", "ParametricEqualizer");
	 				oled_display_message("   High  2500Hz    ", "    3db   Cutting  ");
	 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 				LastStep = Step;
	 			}


	 			equalizer(&high_2500Hz_3dB_cut[0]);			// EQ loop


	 		}
	 		else if(Step == 3)
	 		{

	 			if ( Step != LastStep )
	 			{

	 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 				printf("\n\nHigh 12500Hz -3Db Cutting\n");
	 				printf("SW1+SW2 -> Next Step");
	 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 				  oled_display_message("   High 12500Hz    ", "    3db   Cutting  ");
	 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 				LastStep = Step;
	 			}


	 			equalizer(&high_12500Hz_3dB_cut[0]);			// EQ loop


	 		}
	 		else if(Step == 4)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 20Hz -3Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 					 				oled_display_message("   High    20Hz    ", "    3db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&high_20Hz_3dB_cut[0]);			// EQ loop


	 			 		}

	 		else if(Step == 5)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 12500Hz -9Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 					 				oled_display_message("   High 12500Hz    ", "    9db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&high_12500Hz_9dB_cut[0]);			// EQ loop


	 			 		}

	 		else if(Step == 6)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 2500Hz -9Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High  2500Hz    ", "    9db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&high_2500Hz_9dB_cut[0]);			// EQ loop


	 			 		}
	 		else if(Step == 7)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 500Hz -9Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High   500Hz    ", "    9db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&high_500Hz_9dB_cut[0]);			// EQ loop


	 			 		}


	 		else if(Step == 8)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 12500Hz 9Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High 12500Hz    ", "    9db    Boost   ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&high_12500Hz_9dB_boost[0]);			// EQ loop


	 			 		}

	 		else if(Step == 9)
	 		{
	 			if ( Step != LastStep )
	 			{

	 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 				printf("\n\nHigh 2500Hz 9Db Boost\n");
	 				printf("SW1+SW2 -> Next Step");
	 				oled_display_message("   High  2500Hz    ", "    9db    Boost   ");
                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 	LastStep = Step;
	 			}


	 			equalizer(&high_2500Hz_9dB_boost[0]);			// EQ loop


	 		}
	 		else if(Step == 10)
	 			 		{
	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 500Hz 9Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High   500Hz    ", "    9db    Boost   ");
	 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 	LastStep = Step;
	 			 			}


	 			 			equalizer(&high_500Hz_9dB_boost[0]);			// EQ loop


	 			 		}

	 		else if(Step == 11)
	 			 		{
	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh  500Hz 9Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High   500Hz    ", "    9db    Boost   ");
	 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 	LastStep = Step;
	 			 			}


	 			 			equalizer(&high_500Hz_9dB_boost[0]);			// EQ loop


	 			 		}

	 		else if(Step == 12)
	 			 		{
	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 2500Hz 3Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High  2500Hz    ", "    3db    Boost   ");
	 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 	LastStep = Step;
	 			 			}


	 			 			equalizer(&high_2500Hz_3dB_boost[0]);			// EQ loop


	 			 		}
	 		else if(Step == 13)
	 			 		{
	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nHigh 12500Hz 3Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   High 12500Hz    ", "    3db    Boost   ");
	 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 	LastStep = Step;
	 			 			}


	 			 			equalizer(&high_12500Hz_3dB_boost[0]);			// EQ loop


	 			 		}
	 		else if(Step == 14)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nHigh 12500Hz 0Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   High 12500Hz    ", "    0db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&high_12500Hz_0dB[0]);			// EQ loop


	 			 			 		}

	 		else if(Step == 15)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nLow 2500Hz -3Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 			  //oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 				oled_display_message("   Loww   2500Hz    ", "    3db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&low_2500Hz_3dB_cut[0]);			// EQ loop


	 			 		}
	 			 		else if(Step == 16)
	 			 		{

	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nLow 12500Hz -3Db Cutting\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 				  oled_display_message("   Low  12500Hz    ", "    3db   Cutting  ");
	 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 				LastStep = Step;
	 			 			}


	 			 			equalizer(&low_12500Hz_3dB_cut[0]);			// EQ loop


	 			 		}
	 			 		else if(Step == 17)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 20Hz -3Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 					 				oled_display_message("   Low     20Hz    ", "    3db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_20Hz_3dB_cut[0]);			// EQ loop


	 			 			 		}

	 			 		else if(Step == 18)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 12500Hz -9Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 					 				oled_display_message("   Low  12500Hz    ", "    9db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_12500Hz_9dB_cut[0]);			// EQ loop


	 			 			 		}

	 			 		else if(Step == 19)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 2500Hz -9Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low   2500Hz    ", "    9db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_2500Hz_9dB_cut[0]);			// EQ loop


	 			 			 		}
	 			 		else if(Step == 20)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 500Hz -9Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low    500Hz    ", "    9db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_500Hz_9dB_cut[0]);			// EQ loop


	 			 			 		}


	 			 		else if(Step == 21)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 12500Hz 9Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low  12500Hz    ", "    9db    Boost   ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_12500Hz_9dB_boost[0]);			// EQ loop


	 			 			 		}

	 			 		else if(Step == 22)
	 			 		{
	 			 			if ( Step != LastStep )
	 			 			{

	 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 				printf("\n\nLow 2500Hz 9Db Boost\n");
	 			 				printf("SW1+SW2 -> Next Step");
	 			 				oled_display_message("   Low   2500Hz    ", "    9db    Boost   ");
	 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 	LastStep = Step;
	 			 			}


	 			 			equalizer(&low_2500Hz_9dB_boost[0]);			// EQ loop


	 			 		}
	 			 		else if(Step == 23)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 500Hz 9Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low    500Hz    ", "    9db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_500Hz_9dB_boost[0]);			// EQ loop


	 			 			 		}

	 			 		else if(Step == 24)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow  500Hz 9Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low   500Hz    ", "    9db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_500Hz_9dB_boost[0]);			// EQ loop


	 			 			 		}

	 			 		else if(Step == 25)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 2500Hz 3Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low   2500Hz    ", "    3db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_2500Hz_3dB_boost[0]);			// EQ loop


	 			 			 		}
	 			 		else if(Step == 26)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nLow 12500Hz 3Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Low 12500Hz    ", "    3db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&low_12500Hz_3dB_boost[0]);			// EQ loop


	 			 			 		}
	 			 		else if(Step == 27)
	 			 			 			 		{
	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nLow 12500Hz 0Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Low  12500Hz    ", "    0db    Boost   ");
	 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 	LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&low_12500Hz_0dB[0]);			// EQ loop


	 			 			 			 		}

	 			 		else if(Step == 28)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nPeak 2500Hz -3Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			  //oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 				oled_display_message("   Peak  2500Hz    ", "    3db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&peak_2500Hz_3dB_cut[0]);			// EQ loop


	 			 			 		}
	 			 			 		else if(Step == 29)
	 			 			 		{

	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nPeak 12500Hz -3Db Cutting\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 				  oled_display_message("   Peak 12500Hz    ", "    3db   Cutting  ");
	 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 				LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&peak_12500Hz_3dB_cut[0]);			// EQ loop


	 			 			 		}
	 			 			 		else if(Step == 30)
	 			 			 			 		{

	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 20Hz -3Db Cutting\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 			 				oled_display_message("   Peak    20Hz    ", "    3db   Cutting  ");
	 			 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 				LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_20Hz_3dB_cut[0]);			// EQ loop


	 			 			 			 		}

	 			 			 		else if(Step == 31)
	 			 			 			 		{

	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 12500Hz -9Db Cutting\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				//oled_display_message("Semester    Project", "ParametricEqualizer");
	 			 			 			 				  oled_display_message("   Peak 12500Hz    ", "    9db   Cutting  ");
	 			 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 				LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_12500Hz_9dB_cut[0]);			// EQ loop


	 			 			 			 		}

	 			 			 		else if(Step == 32)
	 			 			 			 		{

	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 2500Hz -9Db Cutting\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak  2500Hz    ", "    9db   Cutting  ");
	 			 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 				LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_2500Hz_9dB_cut[0]);			// EQ loop


	 			 			 			 		}
	 			 			 		else if(Step == 33)
	 			 			 			 		{

	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 500Hz -9Db Cutting\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak   500Hz    ", "    9db   Cutting  ");
	 			 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 				LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_500Hz_9dB_cut[0]);			// EQ loop


	 			 			 			 		}


	 			 			 		else if(Step == 34)
	 			 			 			 		{

	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 12500Hz 9Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak 12500Hz    ", "    9db    Boost   ");
	 			 			 			 				//oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 				LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_12500Hz_9dB_boost[0]);			// EQ loop


	 			 			 			 		}

	 			 			 		else if(Step == 35)
	 			 			 		{
	 			 			 			if ( Step != LastStep )
	 			 			 			{

	 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 				printf("\n\nPeak 2500Hz 9Db Boost\n");
	 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 				oled_display_message("   Peak  2500Hz    ", "    9db    Boost   ");
	 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 	LastStep = Step;
	 			 			 			}


	 			 			 			equalizer(&peak_2500Hz_9dB_boost[0]);			// EQ loop


	 			 			 		}
	 			 			 		else if(Step == 36)
	 			 			 			 		{
	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 500Hz 9Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak   500Hz    ", "    9db    Boost   ");
	 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 	LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_500Hz_9dB_boost[0]);			// EQ loop


	 			 			 			 		}

	 			 			 		else if(Step == 37)
	 			 			 			 		{
	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak  500Hz 9Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak   500Hz    ", "    9db    Boost   ");
	 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 	LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_500Hz_9dB_boost[0]);			// EQ loop


	 			 			 			 		}

	 			 			 		else if(Step == 38)
	 			 			 			 		{
	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 2500Hz 3Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak  2500Hz    ", "    3db    Boost   ");
	 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 	LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_2500Hz_3dB_boost[0]);			// EQ loop


	 			 			 			 		}
	 			 			 		else if(Step == 39)
	 			 			 			 		{
	 			 			 			 			if ( Step != LastStep )
	 			 			 			 			{

	 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 				printf("\n\nPeak 12500Hz 3Db Boost\n");
	 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 				oled_display_message("   Peak 12500Hz    ", "    3db    Boost   ");
	 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 	LastStep = Step;
	 			 			 			 			}


	 			 			 			 			equalizer(&peak_12500Hz_3dB_boost[0]);			// EQ loop


	 			 			 			 		}
	 			 			 		else if(Step == 40)
	 			 			 			 			 		{
	 			 			 			 			 			if ( Step != LastStep )
	 			 			 			 			 			{

	 			 			 			 			 				//oled_display_message("STEP1 No Processing", "      Set Levels   ");
	 			 			 			 			 				printf("\n\nPeak 12500Hz 0Db Boost\n");
	 			 			 			 			 				printf("SW1+SW2 -> Next Step");
	 			 			 			 			 				oled_display_message("   Peak 12500Hz    ", "    0db    Boost   ");
	 			 			 			 		                  //oled_display_message(" NO SIG Processing ", " Parametric Cal ");
	 			 			 			 			 			 	LastStep = Step;
	 			 			 			 			 			}


	 			 			 			 			 			equalizer(&peak_12500Hz_0dB[0]);			// EQ loop


	 			 			 			 			 		}


	 		for(delay =0;delay <= 1000;delay++)
	 		{

	 			if(pushbuttons_press() == SW1 && lobo == 0)
	 			{
	 					lobo = 1;
	 					Step+=13;
	 			}
	 			else if(pushbuttons_press() == SW2 && lobo == 0)
	 			{
	 					lobo = 1;
	 					Step-=13;
	 			}

	 		}
	 		i--;
	}


}






