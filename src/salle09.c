#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle09()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[3][1].visited = 1;
  g_map[3][1].content = 1;
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
	  if (DIAG_S09A08 == 0)
	    {
	      my_putstr("\n\nJ'entre dans l'infirmerie. Esperons que j'y trouve de quoi me soigner.\n");
	      my_putstr("Il y a encore un homme mort sur la table d'operation... Le sol est recouvert de sang.\n");
	      my_putstr("Il a du se trainer jusqu'ici et se hisser sur la table...\n");
	      my_putstr("Je m'approche du corps...\n");
	      //sleep(2);
	      my_putstr("Il est ecrit -Sergent Colas- sur l'uniforme.\n");
	      //sleep(2);
	      my_putstr("Un objet semble dépasser de la poche intèrieure de la veste.\nOn dirait un badge d'accés.\n");
	      my_putstr("Bonne nouvelle, J’ai trouvé de quoi réparer ce qui me sert de tête !\n");
	      my_putstr("Attendez une minute.\n");
	      //sleep(2);
	      my_putstr("Ok ! vu l'aspect de mon pansement, je n'aurais pas fait une bonne infirmière...\n");
	      my_putstr("Mais au moins, je m'en sortirai.\n");
	      my_putstr("Espérons que ma mémoire arrête d'en faire qu'a sa tête...\nAi-je toujours été aussi drôle ?\nJe ne sais plus...\n");
	      my_putstr("(Mis à part mes 'petits' problèmes de mémoire, tout va bien.)");
	      DIAG_S09A08 = 1;
            }
          else
            {
              my_putstr("\nJe retourne vers l'infirmerie.\n");
            }
	  g_map[3][1].content = 0;
	  SALLE = 8;
          salle08();
        }
      if (action == 2)
        {
	  if (CARTE_ACCES == 1)
	    {
	      my_putstr("\nC'est mon jour de chance, le bagde a fonctionné, allons voir de l'autre coté !\n\n");
	      //sleep(2);
	      my_putstr("\nAh, enfin quelque chose d'intéressant ! Il y a une grande baie vitrée de ce coté.\n");
	      my_putstr("Je pense que c'est un laboratoire !\n");
	      my_putstr("Allez, ouvrons les paris ! Je parie que je vais trouver...\n");
	      my_putstr("...");
	      //sleep(2);
	      my_putstr("Un microscope ! Aha !\nEt vous ?\n");
	      g_map[3][1].content = 0;
	      SALLE = 10;
	      salle10();
	    }
	  else
	    {
	      my_putstr("\nJe crois que cette porte vitrée va rester fermée\n");
        my_putstr("Je pense qu'il faut une carte d'accès pour la déverouiller.\n\n");
	      action = 0;
	    }
        }
      if (action == 4)
        {
	  my_putstr("\nJ'ai l'impression d'etre perdue... Etes-vous sur de ce que vous faites ?\n\n");
	  g_map[3][1].content = 0;
	  SALLE = 12;
	  salle12();
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/
      if (action == 3)
        {
          erreur_depla();
          action = 0;
        }
    }
}
