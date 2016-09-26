#include "fonctions.h"

extern t_map g_map[10][4];

void            salle04()
{
  int           action;
  int           randmedic;

  action = 0;
  g_map[1][2].visited = 1;
  g_map[1][2].content = 1;
  look();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;
  srand(time(NULL));
  randmedic = rand();
  
  if (randmedic%10 == 0)
    {
      MEDIC_MAP = 1;
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline();
      /*Traitement de laction :*/
      if (action == 1)
        {
	  my_putstr("\nVous etes sur ? Je trouvais la presence de toutes ces armes presque rassurante !\n");
	  g_map[1][2].content = 0;
	  SALLE = 3;
          salle03();
        }
      if (action == 5)
        {
          prendre();
	  action = 0;
        }
      if ((action >= 2) && (action <= 4))
        {
          erreur_depla();
	  action = 0;
	}
    }
}
