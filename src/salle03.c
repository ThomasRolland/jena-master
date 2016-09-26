#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle03()
{
  int           action;
  char  	*entree;
  int           randmuni;
  int           randmedic;
  int		randmob;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[1][1].visited = 1;
  g_map[1][1].content = 1;
  look();
  srand(time(NULL));
  randmuni = rand();
  randmedic = rand();
  randmob = rand();
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
  if ((randmob%4 == 0) && (ARME_EQUIP > 0))
    {
      start_battle();
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline();
      /*Traitement de laction :*/
      if (action == 1)
        {
	  system("cat src/code_com.txt");
	  my_putstr("\n");
	  entree = readLine_code();
	  if ((strcmp(entree, "jena") == 0) || ((strcmp(entree, "JENA") == 0)))
	    {
	      if (DIAG_S03A02 == 0)
		{
		  my_putstr("Ca marche ! La porte se deverouille !\n");
		  my_putstr("Une minute ! Le code est mon prénom ?...\n");
		  my_putstr("Cela veut dire que...\n");
		  //sleep(2);
		  my_putstr("Je...\n");
		  //sleep(2);
		  my_putstr("Ce sont mes quartiers ?!\n\n");
		  DIAG_S03A02 = 1;
		  QUISUISJE = 1;
		}
	      else
		{
		  my_putstr("Je me dirige vers les quartiers du commandant.\nEnfin, vers MES quartiers.\n\n");
		}
	      g_map[1][1].content = 0;
	      SALLE = 2;
	      salle02();
	    }
	  else
	    {
	      my_putstr("\nJ'essaye le code....\nOups, on dirait que ce n'est pas demain la veille qu'on entrera dans la piece suivante...\n");
	      my_putstr("Le pavé tactile de la machine ne contient que des lettres, je me demande quel peut-etre le code...\n\n");
	      action = 0;
	    }
	}
      if (action == 2)
	{
	  if (CARTE_COM == 0)
	    {
	      my_putstr("\nVous avez besoin d'une carte pour entrer.\n\n");
	      action = 0;
	    }
	  else
	    {
	      my_putstr("\nCette porte ne s'ouvre qu'avec une carte magnetique... Essayons celle que j'ai trouvé dans ma cabine...\n");
	      //sleep(2);
	      my_putstr("\nParfait, ca marche ! La porte s'ouvre !\n\n");
	      g_map[1][1].content = 0;
	      SALLE = 4;
	      salle04();
	    }
	}
      if (action == 3)
	{
	  system("cat src/code_pil.txt");
	  my_putstr("\n");
	  entree = readLine_code();
	  if ((strcmp(entree, "ICARUS") == 0) || (strcmp(entree, "icarus") == 0))
	    {
	      my_putstr("\nICARUS, le nom du vaisseau, logique !\nEsperons que la cabine de pilotage ne sois pas trop endommagee !\n\n");
	      g_map[1][1].content = 0;
	      SALLE = 1;
	      salle01();
	    }
	  else
	    {
	      my_putstr("\nMAUVAIS CODE.\nLe protocole de securité est trop dur pour moi ...\n\n");
	      action = 0;
	    }
	}
      if (action == 4)
	{
	  my_putstr("\nTres bien, rebroussons chemin pour l'instant !\n\n");
	  g_map[1][1].content = 0;
	  SALLE = 6;
	  salle06();
	}
      if (action == 5)
	{
	  prendre();
	  action = 0;
	}
    }
}
