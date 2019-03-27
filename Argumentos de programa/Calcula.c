#include <stdio.h>
#include <string.h>

int main (int argc, char *argv [])
{
  int n1, n2, res;
  char operador;
  sscanf (argv [1], "%d", &n1);
  sscanf (argv [2], "%c", &operador);
  sscanf (argv [3], "%d", &n2);
  switch (operador)
    {
    case '+':
      res = n1 + n2;
      break;
    case '-':
      res = n1 - n2;
      break;
    case 'x':
      res = n1 * n2;
      break;
    case '/':
      res = n1 / n2;
      break;
    }
  printf ("El resultado de %d %c %d es = %d\n", n1, operador, n2, res);
}
