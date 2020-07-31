//#include "C:\Users\EHef_\Documents\OCTAVO-SEMESTRE-ESCOM\Instru\proyectosPic\led1\main.h"
#INCLUDE <16f877a.h>
#USE delay (clock= 4000000)
#FUSES XT, NOPROTECT, NOWDT
#DEFINE SW PORTA, 1
#DEFINE LED PORTB, 0
#BYTE PORTA= 0x5
#BYTE PORTB= 0x6

void main()
{
   Set_Tris_A(0b00000010);
   Set_Tris_B(0b11111110);
   while (true)
   {
      if(bit_test(SW))
      {
         bit_set(LED);
      }
      else
      {
        bit_clear(LED);
      }
   }
}
