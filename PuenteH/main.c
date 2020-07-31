#include <16f877a.h>
#device adc=10
#include <stdio.h>

#fuses XT, NOWDT, NOPROTECT
#use delay (clock=4MHz)
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)
#byte TRISB = 0x86
#byte PORTB = 0x06
#byte TRISA = 0x85
#byte PORTA = 0x05


void main()
{
   TRISB = 0x00;
   PORTB = 0x00;
   TRISA = 0x00;
   PORTA = 0x00;
   
      while(true)
      {
         if(bit_test(PORTA, 0))bit_set(PORTB, 0);
         else if(bit_test(PORTA, 1)) bit_set(PORTB, 1);
         else{
         bit_clear(PORTB, 0);
         bit_clear(PORTB, 1);
         }
      }
}
