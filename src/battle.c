#include "fonctions.h"

extern t_weapon weaponList;
extern t_player jena;
extern t_player mainsList;

/*ATTACK LIST DES MONSTRES*/
static t_attack attackList[NB_ATTACK] = {
  {"Filet", 3},
  {"Charge", 5},
  {"Jet d'acide", 7}
};

/*TABLE DES MONSTRES*/
/*NAME, LVL, PV, PVMAX, STRENGHT, Liste d'attaque structure, EXP donne, items drop*/
static t_enemy BossList[1] = {
  {"Larve géante", 1, 300, 300, 6, attackList, 50}
};


static t_enemy enemyList[NBCREA] = {
  {"Larve ouvrière", 1, 80, 80, 3, attackList, 10},
  {"Petite larve", 1, 50, 50, 4, attackList, 10},
  {"Larve guerrière", 1, 100, 100, 5, attackList, 15}
};




int		player_attack(t_enemy *e)
{
  int		commande;
  int           player_attack(t_enemy *e);
  int		coups_arme;

  commande = 0;
  my_putstr("Que souhaitez vous faire ?\n");
  printf("1 : Utiliser %s\n2 : Prendre un médicament\n", jena.weaponTab[ARME_EQUIP].name);
  while ((commande <= 0) || (commande > 2))
    {
      my_putstr("\nEntrez une action > ");
      commande = atoi(readLine());
      if (((commande == 2) && (jena.medicaments > 0)) && (jena.pv == jena.pvmax))
	{
	  printf("\nInutile de vous soigner maintenant, vous avez %d points de vie sur %d !\n", jena.pv, jena.pvmax);
	  commande = 0;
	}
      else if ((commande == 2) && (jena.medicaments < 1))
      	{
	  my_putstr("\nVous n'avez pas de médicaments !\n");
	  commande = 0;
	}
    }

  if (commande == 1)
    {
      if (jena.munitions < jena.weaponTab[ARME_EQUIP].munitions)
	{
	  my_putstr("Vous n'avez pas assez de munitions pour attaquer !\n");
	  printf("Votre arme requiert [%d] munitions pour tirer. Il vous reste [%d] munitions.\n", jena.weaponTab[ARME_EQUIP].munitions, jena.munitions);
	  my_putstr("\033[1;31mVous attaquez avec vos poings ! Vous infligez 5 point de dégats !\033[0m\n");
	  e->pv -= 5;
	}
      else
	{
    coups_arme = 0;
    while (coups_arme != jena.weaponTab[ARME_EQUIP].nb_coup)
	   {
       printf("\n\033[1;31mVous attaquez avec : %s.\nVous avez infligé %d dégats\n\033[0m", jena.weaponTab[ARME_EQUIP].name, jena.weaponTab[ARME_EQUIP].damage);
      e->pv -= jena.weaponTab[ARME_EQUIP].damage;
	   jena.munitions -= jena.weaponTab[ARME_EQUIP].munitions;
	    printf("Votre arme requiert [%d] munitions pour tirer. Il vous reste [%d] munitions.\n", jena.weaponTab[ARME_EQUIP].munitions, jena.munitions);
      coups_arme++;
    }
	}
    }
  else if (commande == 2)
    {
      jena.pv += 50;
      if (jena.pv > jena.pvmax)
	jena.pv = jena.pvmax;
      jena.medicaments -= 1;
      my_putstr("\n\033[1;32mVous prenez [1x] médicament. Vous regagnez 50 points de vie.\n\033[0m");
      //sleep(2);
      if (jena.medicaments > 0)
	{
	  my_putstr("Il vous reste [");
	  my_putnbr(jena.medicaments);
	  my_putstr("x] médicaments !\n\n");
	}
      else
	{
	  my_putstr("Vous n'avez plus de médicaments !\n");
	}
    }

  if (e->pv <= 0)
    {
      printf("\n- JENA : [%d/%d] PV's.\n- %s : [0/%d] PV's", jena.pv, jena.pvmax, e->name, e->pvmax);
      printf("\n\n\033[1;34mVous avez tué : %s !\033[0m\n", e->name);
      return (0);
    }
  else
    return (1);
}

int		enemy_attack(t_enemy *e)
{
  int		res;
  char		*buffer;
  int		attack;
  int		armure;

  // 1024 taille max
  srand(time(NULL));
  if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
    return -1;
  res = rand() % NB_ATTACK;
  armure = jena.equip_tete[TETE_EQUIP].armure + jena.equip_mains[MAINS_EQUIP].armure + jena.equip_corps[CORPS_EQUIP].armure + jena.equip_jambes[JAMBES_EQUIP].armure;
  attack = (e->attack[res].damage * e->strenght - armure);
  sprintf(buffer, "%s vous attaque !\n\033[1;31mIl utilise : %s, et vous inflige %d dégats.\033[0m", e->name, e->attack[res].name, attack);
  puts(buffer);
  jena.pv -= attack;
  if (jena.pv <= 0)
    {
      memset(buffer, 0, strlen(buffer));
      sprintf(buffer, "%s vous a vaincu....", e->name);
      puts(buffer);
      return (0);
    }
  return (1);
}

int		battle(t_enemy *e, int i)
{
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * 200)) == NULL)
    return (-1);
  sprintf(buffer, "- JENA : [%d/%d] PV's.\n- %s : [%d/%d] PV's", jena.pv, jena.pvmax, e->name, e->pv, e->pvmax);
  puts(buffer);
  if (i % 2 == 0)
    {
      //sleep(2);
      my_putstr("\n----------------------- Votre tour ---------------------------\n\n");
      return (player_attack(e));
    }
  else
    {
      //sleep(2);
      my_putstr("\n\n------------------ Tour de l'adversaire ----------------------\n\n");
      return (enemy_attack(e));
    }
  return (0);
}

t_enemy		*init_e()
{
  int           rnd;
  t_enemy	*e;

  /*MOB BOSS*/
  if (SALLE == 16)
    {
      e = malloc(sizeof(t_enemy));
      e->name = BossList[0].name;
      e->pv = BossList[0].pv;
      e->pvmax = BossList[0].pvmax;
      e->strenght = BossList[0].strenght;
      e->attack = BossList[0].attack;
      e->exp = BossList[0].exp;
      return (e);
    }
  /*MOB STANDARD*/
  else
    {
      srand(time(NULL));
      e = malloc(sizeof(t_enemy));
      rnd = rand() % NBCREA;
      e->name = enemyList[rnd].name;
      e->pv = enemyList[rnd].pv;
      e->pvmax = enemyList[rnd].pvmax;
      e->strenght = enemyList[rnd].strenght;
      e->attack = enemyList[rnd].attack;
      e->exp = enemyList[rnd].exp;
      return (e);
    }
}

int		start_battle()
{
  t_enemy	e;
  int		i;
  int		res;
  int		is_lvlup;

  system("clear");
  srand(time(NULL));
  res = 1;
  i = 0;
  my_putstr("\n\033[5;31mUn monstre vous attaque !\033[0m\n");
  e = *init_e();
  while (res != 0)
    {
      res = battle(&e, i);
      i++;
    }
  /*Traitement de la fin de combat 1 : defaite, 0 : victoire*/
  if (jena.pv <= 0)
    {
      gameover();
      score(e.name);
    }
  else
    {
      drop_item();
    }
  /*FIN MOB DROP*/
  
  /*LVLUP*/
  is_lvlup = give_exp(e.exp);
  stats_jena(is_lvlup);
  SCORE = SCORE + 20;
  my_putstr("\nJ'ai eu chaud ! Merci pour votre aide !\n\n");
return (0);
}
