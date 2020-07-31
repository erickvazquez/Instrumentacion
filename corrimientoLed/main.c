#include <16f877a.h>
#fuses xt, nowdt
#use delay(clock=4M)

int i;
void main()
{
   
  //set_tris_b(0);
  //set_tris_c(0);
   
   while(true)
   {
   
      for(i = 0; i < 9; i ++)
      {
         output_b(0x01 << i);
         if(i < 8)delay_ms(100);
      }
      for(i = 0; i < 3; i ++)
      {
         output_c(0x01 << i);
         delay_ms(100);
      }
   }
}
