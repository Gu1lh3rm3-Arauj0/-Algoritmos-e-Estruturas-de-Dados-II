/*
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED II
     
Judge 3 
*/

#include <stdio.h>
#include <stdlib.h>

int max_index(int v[], int n) {
  int max = v[0];
  int index = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
      index = i;
    }
  }
  return index;
}

int second_index(int v[], int n) {
  int max = v[0];
  int second = -1;
  int index = -1;
  for (int i = 1; i < n; i++) {
    if (v[i] > max) {
      second = max;
      max = v[i];
    } else if (v[i] > second) {
      second = v[i];
      index = i;
    }
  }
  return index;
}

int sum(int v[], int n) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += v[i];
  }
  return s;
}

void eleicoes_economicas(int V, int C, int votos[][3]) {
  int primeiro[C];
  for (int i = 0; i < C; i++) {
    primeiro[i] = 0;
  }
  for (int i = 0; i < V; i++) {
    int candidato = votos[i][0];
    if (candidato >= 1 && candidato <= C) {
      primeiro[candidato - 1]++;
    }
  }
  int total = sum(primeiro, C);
  if (total < C) {
    printf("0\n");
    return;
  }
  if (total == 0) {
    printf("0\n");
    return;
  }
  int vencedor1 = max_index(primeiro, C);
  double porcentagem1 = (double)primeiro[vencedor1] / total * 100;
  printf("%d %.2lf\n", vencedor1 + 1, porcentagem1);
  if (porcentagem1 >= 50) {
    return;
  }
  int segundo1 = second_index(primeiro, C);
  int segundo[C];
  for (int i = 0; i < C; i++) {
    segundo[i] = 0;
  }
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < 3; j++) {
      int candidato = votos[i][j];
      if (candidato == vencedor1 + 1 || candidato == segundo1 + 1) {
        segundo[candidato - 1]++;
        break;
      }
    }
  }
  int total2 = sum(segundo, C);
  int vencedor2 = max_index(segundo, C);
  double porcentagem2 = (double)segundo[vencedor2] / total2 * 100;
  printf("%d %.2lf\n", vencedor2 + 1, porcentagem2);
}

int main() {
  int V, C;
  scanf("%d %d", &V, &C);
  int votos[V][3];
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &votos[i][j]);
    }
  }
  eleicoes_economicas(V, C, votos);
  return 0;
}

