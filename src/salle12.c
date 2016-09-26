#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle12()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;

  action = 0;
  g_map[4][1].visited = 1;
  g_map[4][1].content = 1;
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
      if (action == 3)
        {
	  if (DIAG_S12A09 == 0)
	    {
	      my_putstr("\nJ'arrive dans une grande salle. Oh mon dieu, il y a des hommes au sol...\n");
	      //sleep(2);
	      my_putstr("J'en compte quatre. Il y a du sang partout... Ils s'en sont moins bien sortis que moi...\n");
	      //sleep(2);
	      my_putstr("J'ai pris leurs pouls, tous morts.\n");
	      //sleep(7);
	      my_putstr("Je ne peux rien faire pour eux, continuons.\n");
	      DIAG_S12A09 = 1;
	    }
	  else
	    {
	      my_putstr("OK, je me dirige vers la salle suivante.\n");
	    }
	  g_map[4][1].content = 0;
	  SALLE = 9;
	  salle09();
	}
      if (action == 4)
        {
	  my_putstr("Je traverse un long couloir... Tout est silencieux ici, pas tres rassurant...\n");
	  my_putstr("Je suis arrive dans une grande salle.\n");
	  g_map[4][1].content = 0;
	  SALLE = 13;
	  salle13();
	}
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      if ((action >= 1) && (action <= 2))
        {
	  erreur_depla();
	  action = 0;
        }
    }
}
