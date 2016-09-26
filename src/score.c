#include "fonctions.h"
extern t_player jena;

void		score(char *cause)
{
  my_putstr("\nVotre score est de : ");
  my_putnbr(SCORE);
  my_putstr("\n");
  if (strcmp(cause, "Suicide") == 0)
    {
      my_putstr("Jena est morte par suicide.\n");
      cause = "suicide";
    }
  else if (strcmp(cause, "radiations") == 0)
    {
      my_putstr("Jena est morte irradiée.\n");
      cause = "radiations";
    }
  else
    {
      my_putstr("Jena s'est fait massacrer par : ");
      my_putstr(cause);
      my_putstr(".\n");
    }
  my_putstr("\n");
  my_putstr("                       ==========================\n\n");
  my_putstr("                                 SCORES\n\n");
  my_putstr("                       ==========================\n");
 FILE *f = fopen("src/highscore.txt", "a+");
 if (f == NULL)
   {
     fprintf(stderr, "Error opening file!\n");
     exit(1);
   }

 fprintf(f,"       - %s (Niv. %d) : %d Pts. (Cause la mort : %s)\n", USER, jena.lvl, SCORE, cause);
 fclose(f);
 system("cat src/highscore.txt");
 my_putstr("\n\n");
 exit(0);
}
