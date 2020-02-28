//Nome: Rodrigo Lemos Godinho
//RA: 759020
//Curso: Engenharia de Computação

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
      int posicao;
      struct pessoa *prox;
} Pessoa;

Pessoa *inicio = NULL;
Pessoa *fim = NULL;

void insereLista(int);
void removeLista(Pessoa*);
void imprimeLista();
int resolveJosephus(int, int);

int main(int argc, char *argv[])
{
      int nroexecs;

      scanf("%d", &nroexecs);
      int *n = malloc(nroexecs * sizeof (int));
      int *p = malloc(nroexecs * sizeof (int));

      for (int i = 0; i < nroexecs ; i++)
      {
            scanf ("%d", &n[i]);
            scanf ("%d", &p[i]);
      }

      for (int i = 0; i < nroexecs ; i++)
            printf ("Usando n=%d, m=%d, resultado=%d\n", n[i], p[i], resolveJosephus (n[i], p[i]));
      return 0;
}

void insereLista(int x)
{
      Pessoa *nova;

      nova = malloc(sizeof(Pessoa));
      nova->posicao = x;

      if (fim == NULL)
      {
            inicio = nova;
            nova->prox = inicio;
            fim = nova->prox;
      }
      else
      {
            nova->prox = inicio;
            fim->prox = nova;
            fim = nova;
      }
}

void removeLista(Pessoa *p)
{
      Pessoa *morta;
      morta = p->prox;
      if(morta == inicio)
            inicio = morta->prox;
      if(morta == fim)
            fim = p;
      p->prox = morta->prox;
      free(morta);
}

void imprimeLista()
{
      Pessoa *p;
      p = inicio;
      while (p->prox != inicio)
      {
            printf("%d ", p->posicao);
            p = p->prox;
      }
      printf("%d ", p->posicao);
}

int resolveJosephus(int n, int m)
{
      Pessoa *p;
      int i;

      for (i = 1; i <= n; i++)
            insereLista(i);
      
      p = inicio;

      while (p->posicao != p->prox->posicao)
      {
            int posicao_inicial = p->posicao;
            for (i = 0; i < m - 1; i++)
                  p = p->prox;
            if (p->prox->posicao == posicao_inicial && i != 0)
                  p = p->prox;
            removeLista(p);
            p = p->prox;
      }

      inicio = NULL;
      fim = NULL;

      return p->posicao;
}
