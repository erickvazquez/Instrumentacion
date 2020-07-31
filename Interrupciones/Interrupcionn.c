#include <16f877a.h>
#device adc=10
#include <stdio.h>
#fuses XT, NOWDT , NOPROTECT
#use delay(clock=4MHz)
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)

   VOID pulsaciones();

char dato;
float pulsa=0;

 #INT_rda
 VOID rda_isr ( ) {
    dato = getc ( ) ;
    SWITCH ( dato ) {
       CASE '1':
       output_high ( pin_b7 ) ;
       BREAK;

       CASE '2':
       output_low ( pin_b7 ) ;
       BREAK;

       CASE '3':
       output_high ( pin_b6 ) ;
       BREAK;

       CASE '4':
       output_low ( pin_b6 ) ;
       BREAK;

       CASE '9':
       pulsaciones ( ) ;
       BREAK;
    }
 }

 VOID main ( ) {
   enable_interrupts ( INT_rda ) ;
   enable_interrupts ( global ) ;
   WHILE ( true ) {
   }

 }

   VOID pulsaciones ( ) {
   setup_adc_ports ( all_analog ) ;
   setup_adc ( adc_clock_internal ) ;
   set_adc_channel ( 0 ) ;
   delay_us ( 50 ) ;
   pulsa = ( read_adc ( )  / 2 );
   
   printf ( " %0.2f\r \n", pulsa ) ;
   }

