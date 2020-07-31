#include <16f877a.h>
#fuses hs , nowdt ,noprotect,noput
#use delay (clock=4000000)
#include <stdio.h>
#use rs232 (baud=9600, parity=N, xmit=pin_c6,rcv=pin_c7, bits=8)
int dato;
#int_timer0
void timer_0()
{
   set_timer0(0);

}
void main ()
{
   setup_timer_0(rtcc_ext_h_to_l | rtcc_div_1);
   
   enable_interrupts(int_timer0);
   enable_interrupts(global);
   set_timer0(0);
   while(true){
      printf("Calculando pulso...\n");
      set_timer0(0);
      delay_ms(10000);
      dato=get_timer0();
      dato=dato*6;
      printf("%d\r\n",dato);
   }
}

