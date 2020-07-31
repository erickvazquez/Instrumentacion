#include <16f877a.h>
#device adc=10 
#fuses xt, nowdt,noprotect,put,nolvp,brownout 
#use delay(clock=4MHz) 

int16 duty=0;
int Timer2, Poscaler;

void main(){
   Timer2=249; 
   Poscaler=1;
   setup_timer_2(t2_div_by_4,Timer2,Poscaler);
   setup_ccp1(ccp_pwm); 
   setup_adc_ports(all_analog);
   setup_adc(adc_clock_internal);
   while (1){
      set_adc_channel(0);
      delay_us(100);
      duty=read_adc(); 
      set_pwm1_duty(duty); 
   }
}
