#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle01()
{
  int		action;
  int		randmob;
  int		randmuni;
  int		randmedic;

  action = 0;
  g_map[0][1].visited = 1;
  g_map[0][1].content = 1;
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
      if (action == 4)
	{
	  my_putstr("\nJe ne peux rien faire de plus dans le poste de pilotage pour le moment, je reprends ma route.\n\n");
	  g_map[0][1].content = 0;
	  SALLE = 3;
	  salle03();
	}
      /*Prendre*/
      if (action == 5)
	{
	  prendre();
	  action = 0;
	}
      /*fin prendre*/
      if ((action >= 1) && (action <= 3))
	{
	  erreur_depla();
	  action = 0;
	}
    }
}
