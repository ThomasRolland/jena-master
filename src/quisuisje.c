#include "fonctions.h"

void		quisuisje()
{
  if (QUISUISJE == 0)
    {
      my_putstr("\nComme je vous l'ai dit, je m'appelle Jena, mais c'est tout ce qui me revient...\n\n");
    }
  else if (QUISUISJE == 1)
    {
      my_putstr("\nJe pense que je suis le commandant du vaisseau...\n");
      my_putstr("Je pense etre (pour l'instant) l'unique survivante du crash.\n");
      my_putstr("J'attends les secours... S'ils viennent un jour !\n\n");
    }
}
