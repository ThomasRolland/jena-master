#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle24()
{
  int           action;
  char       		*entree;
  int           randmob;
  int           randmuni;
  int           randmedic;


  entree = malloc(sizeof(char*));
  action = 0;
  g_map[6][2].visited = 1;
  g_map[6][2].content = 1;
  look();
  srand(time(NULL));
  randmob = rand();
  randmuni = rand();
  randmedic = rand();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;

  if (randmedic%10 == 0)
    {
      MEDIC_MAP = 1;
    }
  if ((randmob%4 == 0) && (ARME_EQUIP > 0))
    {
      start_battle();
    }
  if ((randmuni%4 == 0))
    {
      MUNI_MAP = 4;
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline();
      /*Traitement de laction :*/

      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/

      if (action == 3)
        {
	  my_putstr("\nj'ai besoin de retourner en arriere, vous vous souvenez la ou je pouvais marcher sur du sol et non des cartons !\n\n ");
	  g_map[6][2].content = 0;
	  SALLE = 23;
          salle23();
        }
      if ((action == 4) || ((action >= 1) && (action <= 2)))
        {
          erreur_depla();
          action = 0;
        }
    }
}
