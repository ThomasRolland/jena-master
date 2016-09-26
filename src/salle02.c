#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle02()
{
  char		*entree;
  int           action;
  int           randmuni;
  int           randmedic;


  entree = malloc(sizeof(char*));
  action = 0;
  g_map[1][0].visited = 1;
  g_map[1][0].content = 1;
  look();
  srand(time(NULL));
  randmuni = rand();
  randmedic = rand();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;

  if (randmedic%10 == 0)
    {
      MEDIC_MAP = 1;
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
      if (action == 2)
        {
	  my_putstr("\nJe serai bien reste a l'abri ici pour attendre les secours... Mais je risque de manquer de nouriture et d'eau.\n");
	  my_putstr("C'est reparti pour l'aventure dans ce vaisseau super-flippant !\n");
	  g_map[1][0].content = 0;
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
      if ((action == 1) || ((action >= 3) && (action <= 4)))
        {
          erreur_depla();
          action = 0;
        }
    }
}
