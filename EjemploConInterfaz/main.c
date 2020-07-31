
#include <16f877a.h>
#device adc = 10;
#include <stdio.h>


#fuses XT, NOWDT, NOPROTECT

#use delay(clock = 4M)

#use rs232 (baud = 9600, parity = N, xmit = pin_c6, rcv = pin_c7, bits = 8)
#bit RB7 = 0x06.7

void pulsaciones();
char dato;
float pulsa=0;
int8 aux1, aux2, temp, frec;


#int_timer1
void timer1_isr(void){
   temp++;
   set_timer1(0x0BDB);

}

#int_timer0
void timer_0(){
   set_timer0(0);
}

#int_rda
void rda_isr()
{
   dato = getc();
   switch(dato)
   {
      case '9':
         pulsaciones();
        break;
   }
}


void main()
{
   enable_interrupts(int_rda);
   enable_interrupts(global);
   setup_timer_0(rtcc_ext_h_to_l|rtcc_div_1);
   set_timer0(0);
  
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(true)
   {
      if(temp==10){
            aux1 = get_timer0();
            frec = aux1*12;
            printf(".%d\r\n",frec);
            aux2 = aux1;
            temp=0;
            set_timer1(0);
            set_timer0(0);
        } 
   }
   
}

void pulsaciones(){
   setup_adc_ports(AN0);
   setup_adc(adc_clock_div_64);
   set_adc_channel(0);
   delay_us(50);
   pulsa = (read_adc())/2;
   printf("%0.2f\r \n", pulsa);
}


