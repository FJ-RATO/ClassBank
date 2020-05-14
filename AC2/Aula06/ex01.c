#include <detpic32.h>
#include "../helper.h"
volatile int val = 0;
int main() {
  TRISBbits.TRISB4 = 1;
  AD1PCFGbits.PCFG4 = 0;
  AD1CON1bits.SSRC = 7;
  AD1CON1bits.CLRASAM = 1;
  AD1CON3bits.SAMC = 1;
  AD1CON2bits.SMPI = 4 - 1;
  AD1CHSbits.CH0SA = 4;
  AD1CON1bits.ON = 1;

  IPC6bits.AD1IP = 2;
  IFS1bits.AD1IF = 0;
  IEC1bits.AD1IE = 1;

  TRISEbits.TRISE0 = 0;

  TRISB &= 0x00FF;
  TRISDbits.TRISD5 = 0;
  TRISDbits.TRISD6 = 0;
  LATDbits.LATD5 = 1;
  LATDbits.LATD6 = 0;
  AD1CON1bits.ASAM = 1;  // startsample

  EnableInterrupts();

  int i = 0;
  while (1) {
    if (i++ % 25 == 0) {
      i = 0;
      AD1CON1bits.ASAM = 1;
    }
    send2displays((unsigned char)val);
    delay(10);
  }
}

void _int_(27) isr_adc() {
  int *p = (int *)(&ADC1BUF0);
  int i = 0;
  int media = 0;
  for (i = 0; i < 4; i++) {
    media += (p[i * 4] * 33 + 511) / 1023;
  }
  media /= 4;
  IFS1bits.AD1IF = 0;
  LATEbits.LATE0 = 0;
  val = media;
  IFS1bits.AD1IF = 0;
}