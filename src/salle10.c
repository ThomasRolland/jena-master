#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle10()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[3][2].visited = 1;
  g_map[3][2].content = 1;
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
      if (action == 1)
        {
	  if (CARTE_ACCES == 1)
	    {
	      my_putstr("\nJe quitte ce qui ressemble a un laboratoire d'experiences, pour retourner vers des cadavres. Super...\n");
	      my_putstr("Vous n'avez pas une meilleure idée ? Vous donnez certes de bon conseils, mais des fois j'hesite vraiment.\n\n");
	      g_map[3][2].content = 0;
	      SALLE = 9;
	      salle09();
	    }
	  else
	    {
	      my_putstr("\nImpossible de passer cette baie vitre sans la deverouiller, pourtant je connait se qu'il y a derriere.\n\n");
	      action = 0;
	    }
	}
      if (action == 3)
        {
	  my_putstr("\nOh un endroit pour se reposer ? Apres tout se que je viens de decouvrir je ne dirais pas non a une petite sieste.\n");
	  g_map[3][2].content = 0;
	  SALLE = 7;
	  salle07();
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/
      if ((action == 2) || (action == 4))
        {
          erreur_depla();
          action = 0;
        }
    }
}
