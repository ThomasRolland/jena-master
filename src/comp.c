#include "fonctions.h"
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

int             comparer(char* entree)
{
  if ((my_strcmp(entree, "regarder") == 0) || (atoi(entree) == 5))
    {
      look();
      return (0);
    }
  
  if ((my_strcmp(entree, "ouest") == 0) || (atoi(entree) == 4))
    {
      return (1);
    }
  
  if ((my_strcmp(entree, "est") == 0) || (atoi(entree) == 2))
    {
      return (2);
    }
  
  if ((my_strcmp(entree, "nord") == 0) || (atoi(entree) == 1))
    {
      return (3);
    }
  
  if ((my_strcmp(entree, "sud") == 0) || (atoi(entree) == 3))
    {
      return (4);
    }
  
  
  if ((my_strcmp(entree, "aide") == 0))
    {
      help();
      return (0);
    }
  
  
  if ((my_strcmp(entree, "qui suis-je ?") == 0) || (atoi(entree) == 12))
    {
      quisuisje();
      return (0);
    }
  
  if ((my_strcmp(entree, "carte") == 0) || (atoi(entree) == 9))
    {
      show_map();
      return (0);
    }
  
  if ((my_strcmp(entree, "stats") == 0) || (atoi(entree) == 10))
    {
      stats_jena(0);
      return (0);
    }
  
  if ((my_strcmp(entree, "inventaire") == 0) || (atoi(entree) == 11))
    {
      inventaire();
      return(0);
    }

  if ((my_strcmp(entree, "fouiller") == 0) || (atoi(entree) == 6))
    {
      fouiller();
      return(0);
    }
  
  if ((my_strcmp(entree, "prendre") == 0) || (atoi(entree) == 7))
    {
      return (5);
    }
  
  if (my_strcmp(entree, "va te pendre") == 0)
  {
    my_putstr("Me pendre ? Des que j'aurai une corde, avec plaisir !\n");
    my_putstr("En attendant, vouz allez devoir m'aider !\n");
    return (0);
  }
  
  if ((my_strcmp(entree, "quitter") == 0) || (atoi(entree) == 13))
    {
      score("Quitter");
      exit(0);
    }
  
  if (my_strcmp(entree, "kill myself with hands") == 0)
    {
      my_putstr("\nJena, désespérée, serre ses mains autour de sa gorge...\n");
      score("Suicide");
      gameover();
      exit(0);
    }
  
  if ((my_strcmp(entree, "utiliser") == 0) || (atoi(entree) == 8))
    {
      utiliser();
      return (0);
    }
  return (0);
}
