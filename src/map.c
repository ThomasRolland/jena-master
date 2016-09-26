
#include <unistd.h>
#include <stdlib.h>
#include "fonctions.h"

//pour linstant utiliser que les 2 du milieu (0, droite exist ?, bas exist ?, 0)
//Reduire la taille du links de 4 a 2 (le 0 pour le lien de droite et le 1 pour celui du bas)
//a mettre g_map[3][4].visited = 1;

extern		t_map g_map[10][4];

void   		print_top_line(int y)
{
  int	x;
  int	tmp;

  for (x = 0; x < MAP_X; ++x)
    {
      for (tmp = 0; tmp < g_map[y][x].size_x; ++tmp)
	{
	  if (g_map[y][x].exist == 1 && g_map[y][x].visited == 1)
	    write(1, "-", 1);
	  else
	    write(1, " ", 1);
	}
      write(1, "    ", 4);
    }
  write(1, "\n", 1);
}

void	print_bottom_link(int y)
{
  int	x;
  int	tmp;

  for (x = 0; x < MAP_X; ++x)
    {
      for (tmp = 0; tmp < g_map[y][x].size_x; ++tmp)
	{
	  if (g_map[y][x].exist == 1 && g_map[y][x].visited == 1)
	    {
	      if (tmp == g_map[y][x].size_x / 2 && g_map[y][x].links[2] == 1)
		write(1, "|", 1);
	      else
		write(1, " ", 1);
	    }
	  else
	    write(1, " ", 1);
	}
      write(1, "    ", 4);
    }
  write(1, "\n", 1);
}

void	print_top_link(int y)
{
  int	x;
  int	tmp;

  for (x = 0; x < MAP_X; ++x)
    {
      for (tmp = 0; tmp < g_map[y][x].size_x; ++tmp)
	{
	  if (g_map[y][x].exist == 1 && g_map[y][x].visited == 1)
	    {
	      if (tmp == g_map[y][x].size_x / 2 && g_map[y][x].links[0] == 1)
		write(1, "|", 1);
	      else
		write(1, " ", 1);
	    }
	  else
	    write(1, " ", 1);
	}
      write(1, "    ", 4);
    }
  write(1, "\n", 1);
}

void	print_walls(int y)
{
  int	x;
  int	tmp;

  for (x = 0; x < MAP_X; ++x)
    {
      if (g_map[y][x].links[3] == 1 && g_map[y][x].visited == 1)
	write(1, "--", 2);
      else if (x != 0)
	write(1, "  ", 2);
      for (tmp = 0; tmp < g_map[y][x].size_x; ++tmp)
	{
	  if (g_map[y][x].exist == 1 && g_map[y][x].visited == 1)
	    {
	      if (tmp == 0 || tmp == g_map[y][x].size_x - 1)
		write(1, "|", 1);
	      else if (g_map[y][x].content == 1 && tmp == 3)
		write(1, "X", 1);
	      else
		write(1, " ", 1);
	    }
	  else
	    write(1, " ", 1);
	}
      if (g_map[y][x].links[1] == 1 && g_map[y][x].visited == 1)
	write(1, "--", 2);
      else
	write(1, "  ", 2);
    }
  write(1, "\n", 1);
}

void	show_map()
{
  int	y;
  int	x;

  for (y = 0; y < MAP_Y; ++y)
    {
      print_top_link(y);
      print_top_line(y);
      print_walls(y);
      print_top_line(y);
      print_bottom_link(y);
      for (x = 0; x < MAP_X; ++x)
	{
	  if (g_map[y][x].exist > 0)
	    {
	    }
	}
    }
}
