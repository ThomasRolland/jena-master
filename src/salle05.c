#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle05()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[2][0].visited = 1;
  g_map[2][0].content = 1;
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
      if (action == 2)
        {
	  my_putstr("\nje traverse un petit couloir etroit. Je commence a avoir sacrementpeur...\n\n");
	      g_map[2][0].content = 0;
	      SALLE = 6;
	      salle06();
	}
      if (action == 4)
        {
	  my_putstr("\nOn retourne vers le cadavre du sergent, vous etes sur de vouloir vraiment y retourner ? Moi personnelement cela ne me plait pas.");
	  g_map[2][0].content = 0;
	  SALLE = 8;
	  salle08();
	}
      if (action == 5)
        {
          prendre();
	  action = 0;
        }
      if ((action == 1) || (action == 3))
        {
	  erreur_depla();
	  action = 0;
        }
    }
}
