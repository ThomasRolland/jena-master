#ifndef __HERO_H__
#define __HERO_H__
#define MAP_X 4
#define MAP_Y 10
#define NB_ATTACK 3
#define NB_WEAPON 4
#define NBCREA 3
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*USER*/
int		ERREUR_PROMPT;
char*		USER;
int		SCORE;
int		ARME_EQUIP;
int		TETE_EQUIP;
int		MAINS_EQUIP;
int		CORPS_EQUIP;
int		JAMBES_EQUIP;

int		QUISUISJE;
int		SALLE;

/*VARIABLES GLOBALES ITEM*/
int		BOTTES;

/*VARIABLES GLOBALES KEY*/
int		COMBI;
int		CARTE_ACCES;
int		CARTE_COM;

/*VARIABLES GLOBALES ITEMS DANS LA MAP*/
int		MEDIC_RESE;
int		DOUCHE_TAKEN;
int		MUNI_ARMU;
int		MUNI_MAP;
int		MEDIC_MAP;
int		BOSS_BATTU;
/*VARIABLES GLOBALES DE DIALOGUE*/
int		DIAG_S12A09;
int		DIAG_S09A08;
int		DIAG_S03A02;


/*Modif pour item structures*/
typedef struct s_tete
{
  int	possede;
  int	equipe;
  char	*nom_obj;
  int	armure;
}	t_tete;

typedef struct s_mains
{
  int	possede;
  int	equipe;
  char *nom_obj;
  int armure;
} t_mains;

typedef struct s_jambes
{
  int	possede;
  int	equipe;
  char *nom_obj;
  int armure;
} t_jambes;

typedef struct s_corps
{
  int	possede;
  int	equipe;
  char *nom_obj;
  int armure;
} t_corps;
/*fin*/

typedef struct  s_attack
{
  char          *name;
  int           damage;
}               t_attack;

typedef struct  s_drop
{
  char          *name;
  int		nombre;
}               t_drop;

typedef struct  s_enemy
{
  char          *name;
  int		lvl;
  int           pv;
  int		pvmax;
  int		strenght;
  t_attack      *attack;
  int		exp;
}               t_enemy;

// arme du joueur
typedef struct  s_weapon
{
  int           available;
  char          *name;
  int           damage;
  int		        munitions;
  int           nb_coup;
}               t_weapon;

// le joueur
typedef struct  s_player
{
  int		lvl;
  int		exp;
  int           pv;
  int		pvmax;
  int		armure;
  t_mains	*equip_mains;
  t_jambes	*equip_jambes;
  t_tete	*equip_tete;
  t_corps	*equip_corps;
  int		medicaments;
  int		munitions;
  int		munitionsmax;
  t_weapon      *weaponTab;
}               t_player;

void		drop_item();
void		warning();
char            *my_strupcase(char *str);
void            inventaire();
void            show_items();
int	        xpNeeded(int lvl);
int             give_exp();
void            stats_jena();
void            stats_arme();
t_enemy		*init_e();
int	        battle(t_enemy *e, int i);
int		start_battle();
int             enemy_attack(t_enemy *e);
int             player_attack(t_enemy *e);
void		init_globales();
char            *readLine_code();
void            erreur_prendre();
void            quisuisje();
void            show_equip();
void		utiliser();
char            *readline_utiliser();
char            *readline_console();

void            salle01();
void            salle02();
void            salle03();
void            salle04();
void            salle05();
void            salle06();
void            salle07();
void            salle08();
void            salle09();
void            salle10();
void            salle11();
void            salle12();
void            salle13();
void            salle14();
void            salle15();
void            salle16();
void            salle17();
void            salle18();
void            salle19();
void            salle20();
void            salle21();
void            salle22();
void            salle23();
void            salle24();

void            spawn(int salle, t_player *player);
int             comparer(char* entree);
void            erreur_depla();
void            my_putstr(char* str);
void            my_putchar(char c);
void    	my_putnbr(int n);
int             isnegatif(int n);
int             readline();
char             *readline_prendre();
char		*readLine();
int             my_strcmp(char *s1, char *s2);
char            *my_strcpy(char *dest, char *src);
void            suspence();
void            accueil();
void            help();
void            gameover();
void    	show_map();
void            look();
int             my_strlen(char* str);
void            fouiller();
int		prendre();
void            score();


typedef struct s_inventaire
{
  char nom_obj;
  void *prev;
  void *next;
} t_inventaire;


typedef struct s_map
{
  int	exist;
  int	size_x;
  int	links[4];
  int	content;
  int	visited;
} t_map;

/*eauiper arme 1;*/

/*equiper main : t_player->mainWeapon = t_player->weapons[1];*/


#endif
