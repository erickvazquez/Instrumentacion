#include <16f877a.h>
#device adc=10
#include <stdio.h>

#fuses XT, NOWDT, NOPROTECT
#use delay (clock=4MHz)
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)
#byte TRISB=0x86
#byte PORTB=0x06


void main()
{
   TRISB = 0x00;
   PORTB = 0x00;
   int16 dato, dato3;
   float dato2, dato4;
   setup_adc_ports(ALL_ANALOG); 
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_internal);
   
      while(true)
      {
         set_adc_channel(0);
         //delay_ms(1000);
         dato=read_adc();
         dato2=(dato*5.0)/1023.0;
         set_adc_channel(1);
         dato3=read_adc();
         dato4=(dato3*5.0)/1023.0;
         printf("Lectura en LSB sensor 1   %4Ld\r\n", dato);
         printf("Valor en voltaje sensor 1 %2.2Lf\r\n\n", dato2);
         
         
         printf("Lectura en LSB sensor 2   %4Ld\r\n", dato3);
         printf("Valor en voltaje sensor 2 %2.2Lf\r\n\n", dato4);
         
         if(dato2 < 0.30)bit_set(PORTB, 0);
         else bit_clear(PORTB, 0);
         if(dato4 > 0.50) bit_set(PORTB, 1);
         else bit_clear(PORTB, 1);
      }
}
