#include <stdio.h>

int main(int c, char **v)
{
  if (c != 2)
    return (1);
  //TODO: create an validation to verifies if file has .rt extension
  printf("Qtd args: %i\n", c);
  printf("File: %s\n", v[1]);

  return (0);
}

