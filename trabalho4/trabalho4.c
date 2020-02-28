//Nome: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computação

#include <stdio.h>
#include <stdlib.h>

int** criaTabuleiro(int);
int posValida(int**, int, int, int);
void nRainhas(int**, int, int);

int solucoes;

int main(int argc, char *argv[])
{
      int n;
      int **tabuleiro;
      scanf("%d", &n);
      tabuleiro = criaTabuleiro(n);
      nRainhas(tabuleiro, n, 0);
      printf("%d", solucoes); 
      return 0;
}


int** criaTabuleiro(int n)
{
      int **t, i, j;
      t = malloc(n * sizeof(int*));
      for(i = 0; i < n; i++)
            t[i] = malloc(n * sizeof(int));
      for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                  t[i][j] = 0;
      return t;
}

int posValida(int **tabuleiro, int n, int linha, int coluna)
{
      int i;

      for(i = 0; i < n; i++)
            if(tabuleiro[linha][i] == 1)
                  return 0;

      for(i = 0; i < n; i++)
            if(tabuleiro[i][coluna] == 1)
                  return 0;
      
      for(i = 0; i <= linha && i <= coluna; i++)
            if(tabuleiro[linha - i][coluna - i] == 1)
                  return 0;

      for(i = 0; i + linha < n && i <= coluna; i++)
            if(tabuleiro[linha + i][coluna - i] == 1)
                  return 0;
      
      return 1;
}

void nRainhas(int **tabuleiro, int n, int coluna)
{
      if(coluna == n)
      {
            solucoes++;
            return;
      }

      for(int i = 0; i < n; i++)
      {
            if(posValida(tabuleiro, n, i, coluna))
            {
                  tabuleiro[i][coluna] = 1;
                  nRainhas(tabuleiro, n, coluna + 1);
                  tabuleiro[i][coluna] = 0;
            }
      }
}
