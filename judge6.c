/*
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED II
     
Judge 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int valida_seguraca(int x, int y, int w, int h, char grade[MAX][MAX]) {
  if (x < 0 || x >= w || y < 0 || y >= h) {
    return 0;
  }
  if (grade[y][x] == '.') {
    return 1; 
  }
  return 0;
}

int conta_servidores(int x, int y, int w, int h, char grade[MAX][MAX]) {
  int cont = 1;
  grade[y][x] = 'V';
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, -1, 0, 1};
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valida_seguraca(nx, ny, w, h, grade)) {
      cont += conta_servidores(nx, ny, w, h, grade);
    }
  }
  return cont;
}

int main() {
  int w, h;
  scanf("%d %d", &w, &h);
  char grade[MAX][MAX];
  int x, y;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf(" %c", &grade[i][j]);
      if (grade[i][j] == '@') {
        x = j;
        y = i;
      }
    }
  }
  int res = conta_servidores(x, y, w, h, grade);
  printf("%d\n", res);
  return 0;
}
