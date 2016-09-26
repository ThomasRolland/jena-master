#include "fonctions.h"
#include <stdio.h>
void		gameover()
{
  system("cat src/skull.txt");
  my_putstr("\n\n                       ===========================\n\n");
  my_putstr("                                 GAME OVER\n");
  my_putstr("\n                       ===========================\n\n");
}
