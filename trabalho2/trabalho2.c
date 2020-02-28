// Informações do estudante
// Nome: Rodrigo Lemos Godinho
// Curso: Engenharia de Computação
// RA: 759020

#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int n, int vector[]) 
{
      int nOperations = 0;
      int aux;
      int change;
      do
      {
            change = 0;
            for (int i = 1; i < n; i++) 
            {
                  if(vector[i] < vector[i-1])
                  {
                        aux = vector[i];
                        vector[i] = vector[i-1];
                        vector[i-1] = aux;
                        change = 1;
                        nOperations++;
                  }
            }
      } while (change);
      return nOperations;
}

int main(int argc, char *argv[])
{
      int n;
      int nOperations;
      int* vector;
      scanf("%d", &n);
      vector = (int*) malloc(sizeof(int) * n);
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &vector[i]);
      }
      nOperations = bubbleSort(n, vector);
      printf("%d\n", nOperations);
      return 0;
}
