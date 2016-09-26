#include "fonctions.h"

extern t_weapon weaponList;
extern t_player jena;
extern t_player mainsList;

void		drop_item()
{
  int		drop;
  /*BOSS DROP*/
  if (SALLE == 16)
    {
      BOSS_BATTU = 1;
      SCORE += 20;
      srand(time(NULL));
      drop = 1 + rand() % 99;
      if ((drop >= 0) && (drop <= 44))
	{
	  MAINS_EQUIP = 1;
	  jena.equip_mains[MAINS_EQUIP].possede = 1;
	  printf("J'ai trouvé : %s (Armure + %d) près du cadavre de la larve géante !\nJe l'équipe tout de suite !\n", jena.equip_mains[MAINS_EQUIP].nom_obj, jena.equip_mains[MAINS_EQUIP].armure);
	}
      if ((drop >= 45) && (drop <= 69))
	{
	  CORPS_EQUIP = 1;
	  jena.equip_corps[CORPS_EQUIP].possede = 1;
	  printf("J'ai trouvé : %s (Armure + %d) près du cadavre de la larve géante !\nJe l'équipe tout de suite !\n", jena.equip_corps[CORPS_EQUIP].nom_obj, jena.equip_corps[CORPS_EQUIP].armure);
	}
      if ((drop >= 70) && (drop <= 89))
	{
	  jena.munitions += 12;
	  jena.medicaments += 4;
	  my_putstr("J'ai trouvé des munitions et des bandages derrière le cadavre de la larve géante.\n");
	  my_putstr("[JENA] : Munitions + 12\n");
	  my_putstr("[JENA] : Médicaments + 4\n\n");
	}
      if ((drop >= 90) && (drop <= 100))
	{
	  ARME_EQUIP = 3;
	  jena.weaponTab[ARME_EQUIP].available = 1;
	  printf("J'ai trouvé : %s (Dégats : %d) près du cadavre de la larve géante !\nJe l'équipe tout de suite !\n", jena.weaponTab[ARME_EQUIP].name, jena.weaponTab[ARME_EQUIP].damage);
	  stats_arme();
	}
    }
  /*FIN BOSS DROP*/


  /*MOB DROP*/
  else
    {
      srand(time(NULL));
      drop = 1 + rand() % 99;
      if ((drop >= 0) && (drop <= 15))
	{
	  my_putstr("\nJ'ai trouvé quelques munitions au sol apres le combat !\n");
	  my_putstr("[JENA] : Munitions + 5\n\n");
	  jena.munitions += 5;
	  SCORE += 5;
	}
      else if ((drop >= 16) && (drop <= 10))
	{
	  my_putstr("\nJ'ai trouvé un médicament au au sol apres le combat !\n");
	  my_putstr("[JENA] : Médicaments + 1\n\n");
	  jena.medicaments += 1;
	  SCORE += 1;
	}
      else
	{
	}
    }
}
