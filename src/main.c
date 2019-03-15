/** 
 ** Entrega realizada por:
 **  - Giulia Passarelli
 **  - Alessandra Blucher
 ** 
 **  - url vídeo
 **/

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

const int songspeed = 1.5; //Change to 2 for a slower version of the song, the bigger the number the slower the song
//*****************************************
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define c  261
#define d  294
#define e  329
#define f  349
#define g  391
#define gS  415
#define a  440
#define aS  455
#define b  466
#define cH  523
#define cSH  554
#define dH  587
#define dSH  622
#define eH  659
#define fH  698
#define fSH  740
#define gH  784
#define gSH  830
#define aH  880
//*****************************************
int melody[] = {
	NOTE_E7, NOTE_E7, 0, NOTE_E7,
	0, NOTE_C7, NOTE_E7, 0,
	NOTE_G7, 0, 0,  0,
	NOTE_G6, 0, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	9, 9, 9,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
	
	9, 9, 9,
	12, 12, 12, 12,
	12, 12, 12, 12,
	12, 12, 12, 12,
};

//marcha imperial
int imperial_melody[] = {
	a,a,a,f,cH,a,f,cH,a,0,eH,eH,eH,fH,cH,gS,f,cH,a,0
};

int imperial_tempo[] = {
	500,500,500,350,150,500,350,150,650,500,500,500,500,350,150,500,350,150,650,500
};

#define BUZZER_PIO           PIOA
#define BUZZER_PIO_ID        ID_PIOA
#define BUZZER_PIO_IDX       4u
#define BUZZER_PIO_IDX_MASK  (1u << BUZZER_PIO_IDX)

#define PAUSE_PIO           PIOA
#define PAUSE_PIO_ID        ID_PIOA
#define PAUSE_PIO_IDX       3u
#define PAUSE_PIO_IDX_MASK  (1u << PAUSE_PIO_IDX)

#define CHANGE_PIO           PIOA
#define CHANGE_PIO_ID        ID_PIOA
#define CHANGE_PIO_IDX       19u
#define CHANGE_PIO_IDX_MASK  (1u << CHANGE_PIO_IDX)

#define	GREEN_PIO            PIOA
#define GREEN_PIO_ID         ID_PIOA
#define GREEN_PIO_IDX        0u
#define GREEN_PIO_IDX_MASK   (1u << GREEN_PIO_IDX)

#define	BLUE_PIO           PIOB
#define BLUE_PIO_ID        ID_PIOB
#define BLUE_PIO_IDX       1u
#define BLUE_PIO_IDX_MASK  (1u << BLUE_PIO_IDX)


void init(void);

// Função de inicialização do uC
void init(void){
	// Initialize the board clock
	sysclk_init();
	
	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// Ativa o PIO na qual o BUZZER foi conectado
	// para que possamos controlar o BUZZER.
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	
	// Ativa o PIO na qual o BLUE foi conectado
	// para que possamos controlar o BUZZER.
	pmc_enable_periph_clk(BLUE_PIO_ID);
	
	//Inicializa PA4 como saída
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	//Inicializa PAUSE como saída
	pio_set_input(PAUSE_PIO, PAUSE_PIO_IDX_MASK, PIO_PULLUP);
	pio_pull_up(PAUSE_PIO, PAUSE_PIO_IDX_MASK, 1);
	
	//Inicializa CHANGE como saída
	pio_set_input(CHANGE_PIO, CHANGE_PIO_IDX_MASK, PIO_PULLUP);
	pio_pull_up(CHANGE_PIO, CHANGE_PIO_IDX_MASK, 1);
	
	//Inicializa PA0 como saída
	pio_set_output(GREEN_PIO, GREEN_PIO_IDX_MASK, 0, 0, 0);
	
	//Inicializa PB0 como saída
	pio_set_output(BLUE_PIO, BLUE_PIO_IDX_MASK, 0, 0, 0);
}

void buzz(long frequency, long length) {
	
	long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
	//// 1 second's worth of microseconds, divided by the frequency, then split in half since
	//// there are two phases to each cycle
	
	long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
	//// multiply frequency, which is really cycles per second, by the number of seconds to
	//// get the total number of cycles to produce
	
	for (long i = 0; i < numCycles; i++) {       // for the calculated length of time...
		pio_set(PIOA, BUZZER_PIO_IDX_MASK);      // Coloca 1 no pino BUZZER
		delay_us(delayValue);                    // wait for the calculated delay value
		pio_clear(PIOA, BUZZER_PIO_IDX_MASK);    // Coloca 0 no pino do BUZZER
		delay_us(delayValue);                    // wait again or the calculated delay value
	}
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
  init();
  int pause_flag = 0;
  int note_paused = 0;
  int note_paused2 = 0;
  int song = 0;
  
  // super loop
  // aplicacoes embarcadas não devem sair do while(1).
  while (1)
  {		
	    if(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK)))
	    {
		    while(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK)))
		    {
			    delay_ms(100);
		    }
		    pause_flag = !pause_flag;
	    }
		
		if(!(pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK)))
		{
			delay_ms(100);
			if (pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK) == 0){
				song = !song;
				pause_flag = 0;
			}
		}
		
		if(pause_flag == 0){
			if (song == 0){
				int size = sizeof(melody) / sizeof(int);
				pio_set(GREEN_PIO, GREEN_PIO_IDX_MASK);
				for (int note = note_paused; note < size; note++){
				
					if(note == size-1){
						note = 0;
					}
 
					// to calculate the note duration, take one second
					// divided by the note type.
					//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
					int noteDuration =  1000 / tempo[note];
			
					buzz(melody[note], noteDuration);
				
					if(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK))){
						while(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK))){
							delay_ms(100);
						}
						note_paused = note + 1; 
						pause_flag = 1; 
						pio_clear(GREEN_PIO, GREEN_PIO_IDX_MASK);
						break;
					}
					
					if(!(pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK)))
					{
						delay_ms(100);
						if (pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK) == 0){
							song = !song;
							pause_flag = 0;
							pio_clear(GREEN_PIO, GREEN_PIO_IDX_MASK);
							break;
						}
					}
				
					// to distinguish the notes, set a minimum time between them.
					// the note's duration + 30% seems to work well:
					int pauseBetweenNotes = noteDuration * 1.3;
					delay_ms(pauseBetweenNotes);
 
					// stop the tone playing:
					buzz(0, noteDuration);
				}
			}
		
			if (song == 1){
				int size = sizeof(imperial_melody) / sizeof(int);
				pio_set(BLUE_PIO, BLUE_PIO_IDX_MASK);
				for (int note = note_paused2; note < size; note++){
					
					if(note == size-1){
						note = 0;
					}
					
					// to calculate the note duration, take one second
					// divided by the note type.
					//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
					int noteDuration = imperial_tempo[note]; // 1000 / imperial_tempo[note];
					
					buzz(imperial_melody[note], noteDuration);
					
					if(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK))){
						while(!(pio_get(PAUSE_PIO, PIO_INPUT, PAUSE_PIO_IDX_MASK))){
							delay_ms(100);
						}
						note_paused2 = note + 1;
						pause_flag = 1;
						pio_clear(BLUE_PIO, BLUE_PIO_IDX_MASK);
						break;
					}
					
					if(!(pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK)))
					{
						delay_ms(100);
						if (pio_get(CHANGE_PIO, PIO_INPUT, CHANGE_PIO_IDX_MASK) == 0){
							song = 0;
							pause_flag = 0;
							pio_clear(BLUE_PIO, BLUE_PIO_IDX_MASK);
							break;
						}
					}
					
					// to distinguish the notes, set a minimum time between them.
					int pauseBetweenNotes = noteDuration * 0.7;
					delay_ms(pauseBetweenNotes);
					
					// stop the tone playing:
					buzz(0, noteDuration);
				}
			}
		}
	  
  }
  return 0;
}
