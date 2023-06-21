#include "App.h"



void pwm_G (uint16 freq ,uint16 duty ) ;

uint16 onPeriod =150 ,offPeriod=350, WaveTime=500 ;


void app_start (void)
{
		
 uint8 duty_c = 30 ,flag=0 ,state=1,b_flag=0;
	if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{	      
	   flag=1;
			pwm_G (2,30);  
	}   

	
  while(flag==1)
	{	
		
		
		Blink_Start2(BLINKING_GPTM, WaveTime , onPeriod, offPeriod);	
		
			 				if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{	      
		           b_flag=1;
	
	}   
	if ( b_flag==1)
	{ 
		state++;  
					switch (state)
	{ 
		case 1 :
	 duty_c =30;
		break;
		case 2 :
  duty_c =60;
		break;
		case 3 :
   duty_c =90;
		break;
		case 4 :
    Blink_Stop(BLINKING_GPTM,LED_3);
		flag=0; 
		state=1;
		break;
	} 	
	
		pwm_G (2,duty_c);          
		  
    	b_flag=0;
	}

	
	  
	}
}
void pwm_G (uint16 freq ,uint16 duty ) 
{
    WaveTime=(1000/freq);                   //in ms   
	  onPeriod= (duty * WaveTime)/100 ; 
    offPeriod= WaveTime-onPeriod;

} 
void app_init(void)
{
	
			Led_Init();
	  Button_Init();
	  blink_init(BLINKING_GPTM,LED_3);
}
