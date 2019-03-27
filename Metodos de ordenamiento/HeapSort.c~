#include <stdio.h>

int partition (int a[], int l, int r);
void quickSort (int a[], int l, int r);

void quickSort (int a[], int l, int r)
{
  int j;

  if (l < r)
    {
      j = partition (a, l, r);
      quickSort (a, l, j - 1);
      quickSort (a, j + 1, r);
    }
}

int partition (int a[], int l, int r)
{
  int pivot, i, j, t;

  pivot = a[l];
  i = l;
  j = r + 1;

  while (1)
    {
      do
	{
	  ++i;
	}
      while ((a[i] <= pivot) && (i <= r));
      do
	{
	  --j;
	}
      while (a[j] > pivot);
      if (i >= j)
	{
	  break;
	}
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  t = a[l];
  a[l] = a[j];
  a[j] = t;
  return j;
}

int main ()
{
  int m[] = {25, 2, 7, 3, 67, 43, 1, 15, 9, 32};
  int i;

  printf ("Arreglo original\n");
  for (i = 0; i < 10; i ++)
    {
      printf ("%d ", m[i]);
    }
  printf ("\nArreglo ordenado\n");
  quickSort (m, 0, 9);
  for (i = 0; i < 10; i ++)
    {
      printf ("%d ", m[i]);
    }
  return (1);
}
