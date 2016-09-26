#include "fonctions.h"

int		isnegatif(int n)
{
  if (n < 0)
    {
      n = -n;
      my_putchar('-');
      return (n);
    }
  else
    {
      return (n);
    }
}

void    	my_putnbr(int n)
{
  int tab[10];
  int i;

  i = 0;
  n = isnegatif(n);
  if (n == 0)
    {
      my_putchar(48);
      return ;
    }
  while (n > 0)
    {
      tab[i] = (n%10);
      n = (n / 10);
      i++;
    }
  i--;
  while (i >= 0)
    {
      my_putchar((tab[i])+48);
      i--;
    }
}
