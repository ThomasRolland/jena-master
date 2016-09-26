#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle11()
{
  int           action;
  char          *entree;
  int           randmob;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[4][0].visited = 1;
  g_map[4][0].content = 1;
  look();
  srand(time(NULL));
  randmob = rand();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;

  if ((randmob%4 == 0) && (ARME_EQUIP > 0))
    {
      start_battle();
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline();
      /*Traitement de laction :*/
      if (action == 3)
        {
	  my_putstr("\nVous avez raison, quittons vite cette réserve flippante !\n");
	  g_map[4][0].content = 0;
	  SALLE = 8;
          salle08();
        }

      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/

      if ((action == 1) || (action == 2) || (action == 4))
	{
	  erreur_depla();
	  action = 0;
	}
    }
}
