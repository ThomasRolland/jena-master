#include "fonctions.h"
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

int		prendre()
{
  char		*entree;
  /* char		*temp;
  int		i;

  i = 0;*/

  entree = malloc(sizeof(char*));
  entree = readline_prendre();
  if(MEDIC_MAP > 0)
    {
      if ((strcmp(entree, "medicament") == 0) || strcmp(entree, "medicaments") == 0)
      {
	my_putstr("\nUne chance d'avoir trouvé un médicament.\n");
	my_putstr("[JENA] : médicaments + 1\n\n");
	jena.medicaments += 1;
	MEDIC_MAP = 0;
	SCORE += 1;
	return (0);
      }
	}
  if(MUNI_MAP > 0)
    {
      if (strcmp(entree, "munitions") == 0)
      {
	my_putstr("\nUne chance d'avoir trouvé ces munitions.\n");
	my_putstr("[JENA] : Munitions + 4\n\n");
	jena.munitions += 4;
	MUNI_MAP = 0;
	SCORE += 4;
	return (0);
      }
    }
  /*debut des salles*/
  /*DEBUT SALLE 01*/

 if(SALLE == 01)
    {
      if (strcmp(entree, "console") == 0)
	{
	  my_putstr("Je ne peux pas prendre la console ! Il faut que je trouve le moyen de m'en servir !\n\n");
	}
      else
	{
	  my_putstr("Il n'y a rien de tel a prendre ici !\n\n");
	}
    }

  /*DEBUT 02*/
  if(SALLE == 02)
    {
      if (strcmp(entree, "douche") == 0)
	{
	  system("cat src/douche.txt");
	  my_putstr("\n\n");
	  if (DOUCHE_TAKEN == 0)
	      SCORE = SCORE + 20;
	  return (0);
	}
     
      else if (strcmp(entree, "lit") == 0)
	{
	  my_putstr("Je ne peux pas prendre la lit voyons ! Mais je peux l'utiliser pour me reposer !\n\n");
	}
      else if (strcmp(entree, "carte") == 0)
	{
	  if (CARTE_COM == 0)
	    {
	      my_putstr("\nEcoutez, je ne sais pas si c'est important mais j'ai trouve une carte d'acces avec mon nom dessus !\n\n");
	      system("cat src/carte_com.txt");
	      my_putstr("\n");
	      CARTE_COM = 1;
	      SCORE = SCORE + 5;
	    }
	  else if ((strcmp(entree, "munitions") == 0))
	    {
	      my_putstr("\nUne chance d'avoir trouvé ces munitions.\n");
	      my_putstr("[JENA] : Munitions + 4\n\n");
	      jena.munitions += 4;
	      MUNI_MAP = 0;
	    }
	  else
	    {
	      my_putstr("\nJe n'ai rien trouvé de tel ici !\n\n");
	    }
	  return (0);
	}
    }
  /*FIN 02*/

  /*DEBUT 04*/
  if(SALLE == 4)
    {
      /*DEBUT MUNITIONS*/
      if (strcmp(entree, "munitions") == 0)
        {
	  if (MUNI_ARMU > 0)
	    {
	      my_putstr("\nJ'ai trouvé une cartouche d'energie !\n");
	      my_putstr("Je peux m'en servir pour recharger des armes ou des appareils.\n");
	      jena.munitions += 16;
	      my_putstr("[JENA] : Munitions + 20\n");
	      printf("J'ai maintenant %d munitions.\n\n", jena.munitions);
	      MUNI_ARMU -= 20;
	      SCORE = SCORE + 20;
	    }
	  else
	    {
	      my_putstr("\nJ'ai deja pris toutes les munitions que j'ai pu trouver !\n");
	    }
	}
      /*FIN MUNITIONS*/

      /*DEBUT PRENDRE ARME*/
      if (strcmp(entree, "pistolet") == 0)
	{
	  if ((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0))
	    {
	      ARME_EQUIP = 1;
	      jena.weaponTab[ARME_EQUIP].available = 1;
	      my_putstr("\nJ'ai fouillé l'armurerie, et devinez ce que j'ai trouvé ?\n");
	      my_putstr("Un pistolet laser flambant neuf ! Il est chargé et pret a l'emploi !\n");
	      stats_arme();
	      my_putstr("\nJe me sens déjà plus rassurée !\n");
	      my_putstr("Maintenant que j'ai une arme meilleur que mes simples poings, je dois être d'avantage sur mes gardes...\n\n");
	      SCORE = SCORE + 10;
	    }
	  else
	    {
	      my_putstr("\nVous croyez vraiment que je n'aimerai pas emporter ces deux armes ?\n");
	      my_putstr("Malheureusement, tout cela est trop lourd pour moi !\n\n");
	    }
	}
      else if (strcmp(entree, "fusil") == 0)
	{
	  if ((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0))
	    {
	      ARME_EQUIP = 2;
	      jena.weaponTab[ARME_EQUIP].available = 1;
	      my_putstr("\nJ'ai fouillé l'armurerie, et devinez ce que j'ai trouvé ?\n");
	      my_putstr("Un fusil plasma flambant neuf ! Il est chargé et pret a l'emploi !\n");
	      stats_arme();
	      my_putstr("\nJe me sens déjà plus rassurée !\n");
	      my_putstr("Maintenant que j'ai une arme meilleur que mes simples poings, je dois être d'avantage sur mes gardes...\n\n");
	      SCORE = SCORE + 10;
	    }
	  else
	    {
	      my_putstr("\nVous croyez vraiment que je n'aimerai pas emporter ces deux armes ?\n");
	      my_putstr("Malheureusement, tout cela est trop lourd pour moi !\n\n");
	    }
	}
      /*else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}*/
      return (0);
    }

  /*FIN 04*/

  /*DEBUT 07*/
  if(SALLE == 7)
    {
      if (strcmp(entree, "bottes") == 0)
	{
	  if (jena.equip_jambes[1].possede == 0)
	    {
	      JAMBES_EQUIP = 1;
	      jena.equip_jambes[JAMBES_EQUIP].possede = 1;
	      jena.equip_jambes[JAMBES_EQUIP].equipe = 1;
	      printf("\nJ'ai trouvé de supeeeerbes %s ! A ma taille en plus !\nJe n'ai jamais été chanceuse pendant les soldes pourtant...\nMa mere me disait que j'avais de trop grands pieds...\n\n", jena.equip_jambes[JAMBES_EQUIP].nom_obj);
	    }
	  else
	    {
	      my_putstr("\nJ'ai déja pris les bottes, a part des sandalles trop petites, il n'y a plus rien ici.\n\n");
	    }
	}
      else
	{
	  my_putstr("\nJe ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
      /*DEBUT 08*/
  if(SALLE == 8)
    {
      if (strcmp(entree, "badge") == 0)
	{
	  if (CARTE_ACCES == 0)
	    {
	      my_putstr("\nEuh… Vous êtes vraiment sûr ? Ok…\nC’est dégoûtant…\n");
	      //sleep(2);
	      my_putstr("C’est bon, j’ai le badge d’accès du Sergent Colas.\n\n");
	      CARTE_ACCES = 1;
	      SCORE = SCORE + 5;
	    }
	  else
	    {
	      my_putstr("\nJ'ai deja pris le badge.\nNe m'obligez pas a fouiller le cadavre d'avantage.\n\n");
	    }
	}
      else
	{
	  my_putstr("\nJe ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 08*/

  /*DEBUT 11*/
  if(SALLE == 11)
    {
      if ((strcmp(entree, "medicaments") == 0) || strcmp(entree, "medicament") == 0)
	{
	  if (MEDIC_RESE > 0)
	    {
	      my_putstr("J'ai fouillé dans les armoires, bonne nouvelle, j'ai trouvé des médicaments !\n\n");
	      my_putstr("[JENA] : Médicaments + 5\n\n");
	      jena.medicaments += 5;
	      MEDIC_RESE -= 5;
	      SCORE = SCORE + 5;
	    }
	  else
	    {
	      my_putstr("Il n' y a plus de médicaments dans la piece !\n\n");
	    }
	}
      else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 11*/

  /*DEBUT 24*/
  if(SALLE == 24)
    {
      if (strcmp(entree, "combinaison") == 0)
	{
	  if (COMBI == 0)
	    {
	      my_putstr("Bonne idee, une combinaison anti-radiation ne pourra que m'etre utile !\n\n");
	      COMBI = 1;
	      SCORE = SCORE + 10;
	    }
	  else
	    {
	      my_putstr("J'ai deja pris la combinaison !\n\n");
	    }
	}
      else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 24*/

  my_putstr("\nIl n'y a rien a prendre dans cette salle vous savez...\n\n");
  return (1);
}


