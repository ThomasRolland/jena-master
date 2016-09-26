#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle06()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[2][1].visited = 1;
  g_map[2][1].content = 1;
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
	  my_putstr("\nCe couloir ouvre sur plusieurs portes. Il y a des noms a l'entree de chaque porte. ");
	  my_putstr("COLAS, CURLLY, ... Ce doit etre les quartiers des hommes de l'equipage.\n");
	  my_putstr("Esperons que j'en aprenne d'avantage sur l'equipage.");
	  g_map[2][1].content = 0;
	  SALLE = 5;
          salle05();
        }
      if (action == 2)
        {
	  my_putstr("\nOn dirait... Des quartiers ! Tout est en desordre, mais je devine aux bottes et aux accessoires sur les lits que ce doit etre les quartiers des femmes.\n\n");
	  g_map[2][1].content = 0;
	  SALLE = 7;
	  salle07();
        }
      if (action == 3)
        {
	  if (CARTE_ACCES == 0)
            {
              my_putstr("\nLa porte est fermee. On dirait qu'il faut une badge d'acces.\n");
	      my_putstr("Super, je suis piegee dans un vaisseau flippant, enfermee avec des cadavres...\n");
	      my_putstr("Tout. Va. Bien !\n\n");
              action = 0;
            }
          else
            {
	      my_putstr("J'essaye le badge sur le boitier de la porte...\n");
	      //sleep(2);
	      my_putstr("Et... Ca marche, la porte s'est ouverte !\n");
              g_map[2][1].content = 0;
              SALLE = 3;
              salle03();
            }
        }
      if (action == 4)
        {
          erreur_depla();
          action = 0;
        }
      if (action == 5)
        {
          prendre();
	  action = 0;
        }
    }
}
