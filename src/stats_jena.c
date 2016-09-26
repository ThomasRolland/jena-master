#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void		stats_jena(int is_lvlup)
{
  int armure;

  armure = jena.equip_tete[TETE_EQUIP].armure +jena.equip_mains[MAINS_EQUIP].armure + jena.equip_corps[CORPS_EQUIP].armure + jena.equip_jambes[JAMBES_EQUIP].armure;
  my_putstr("\n                =========================\n");
  my_putstr("                           JENA");
  my_putstr("\n                =========================\n");
  if (is_lvlup)
    printf("                Niveau : \033[1;32m%d\033[0m (+1)\n", jena.lvl);
  else
    printf("                Niveau : %d\n", jena.lvl);
  printf("                Experience : [%d/%d]\n", jena.exp, xpNeeded(jena.lvl));
  if (is_lvlup)
    printf("                PV's : \033[1;32m[%d/%d]\033[0m (+ 10)\n", jena.pv, jena.pvmax);
  else
    printf("                PV's : [%d/%d]\n", jena.pv, jena.pvmax);
  printf("                Equipé : %s\n                > [%d dégats par coup]\n", jena.weaponTab[ARME_EQUIP].name, jena.weaponTab[ARME_EQUIP].damage);
    printf("                Armure : %d\n\n", armure);
}

void		stats_arme()
{
  my_putstr("\n                =========================\n");
  my_putstr("                    ");
  if (ARME_EQUIP == 0)
    my_putstr("     ");
  else if ((ARME_EQUIP == 1) || (ARME_EQUIP == 2))
  my_putstr(" ");
  my_putstr(jena.weaponTab[ARME_EQUIP].name);
  my_putstr("\n                =========================\n");
  printf("                Dégats : %d par coup\n", jena.weaponTab[ARME_EQUIP].damage);
  printf("                Cartouches : %d par coup\n", jena.weaponTab[ARME_EQUIP].munitions);
  printf("                Munitions : %d/%d\n\n", jena.munitions, jena.munitionsmax);
}

void		inventaire()
{
  stats_arme();
  my_putstr("                =========================\n");
  my_putstr("                        EQUIPEMENT");
  my_putstr("\n                =========================\n");
  show_equip();
  my_putstr("\n");
  my_putstr("                =========================\n");
  my_putstr("                         AUTRES");
  my_putstr("\n                =========================\n");
  show_items();
 my_putstr("\n");
  my_putstr("                =========================\n");
  my_putstr("                        MEDICAMENTS");
  my_putstr("\n                =========================\n");
  printf("                Possédés : %d\n\n", jena.medicaments);
 my_putstr("\n");
}

void		show_items()
{
  if (CARTE_ACCES == 1)
    my_putstr("                - Badge d'acces\n");
  if (CARTE_COM == 1)
    my_putstr("                - Carte du commandant\n");
  if (COMBI == 1)
    my_putstr("                - Combinaison\n");

}


void		show_equip()
{
  int armure;

  armure = jena.equip_tete[TETE_EQUIP].armure +jena.equip_mains[MAINS_EQUIP].armure + jena.equip_corps[CORPS_EQUIP].armure + jena.equip_jambes[JAMBES_EQUIP].armure;
  printf("                - Tête : %s (+%d)\n", jena.equip_tete[TETE_EQUIP].nom_obj, jena.equip_tete[TETE_EQUIP].armure);
  printf("                - Corps : %s (+%d)\n", jena.equip_corps[CORPS_EQUIP].nom_obj, jena.equip_corps[CORPS_EQUIP].armure);
  printf("                - Mains : %s (+%d)\n", jena.equip_mains[MAINS_EQUIP].nom_obj, jena.equip_mains[MAINS_EQUIP].armure);
  printf("                - Jambes : %s (+%d)\n", jena.equip_jambes[JAMBES_EQUIP].nom_obj, jena.equip_jambes[JAMBES_EQUIP].armure);
}

int		give_exp(int exp)
{
  int		xpneeded;

  jena.exp = jena.exp + exp;
  xpneeded = xpNeeded(jena.lvl);
  if (jena.exp >= xpneeded)
    {
      jena.lvl = jena.lvl + 1;
      jena.exp = (jena.exp - xpneeded);
      jena.pvmax = jena.pvmax + 10;
      jena.pv = jena.pv + 10;
      return (1);
   }
  return (0);
}
