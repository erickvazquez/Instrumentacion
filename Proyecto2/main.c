#INCLUDE <16f877a.h>
#device adc=10
#include <stdio.h>
#use delay(clock=4000000)
#fuses XT, NOWDT, NOPROTECT
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)
#BYTE PORTB = 0x6
//long bits1, bits2, bits3;
float temp1, temp2, temp3, tempProm;
void main() {
   setup_adc_ports(all_analog);  
   setup_adc(adc_clock_internal);
      output_low(pin_b0);
      output_low(pin_b1);
      while(true){
         set_adc_channel(0); 
         output_low(pin_b1);
         delay_ms(1000);                          
         temp1=(read_adc()*5)/1023.0; 
         
         output_high(pin_b0);
         delay_ms(1000);            
         temp2=(read_adc()*5)/1023.0;
         
         output_high(pin_b1);
         delay_ms(1000);           
         temp3=(read_adc()*5)/1023.0;
         
         output_low(pin_b0);
        
         tempProm = (temp1*20 + temp2*20 + temp3*20)/3.0;
         printf("t1%Lf\r\n", temp1*20);  
         printf("t2%Lf\r\n", temp2*20);
         printf("t3%Lf\r\n", temp3*20);
         printf("tp%Lf\r\n", tempProm);
      
   }
}

