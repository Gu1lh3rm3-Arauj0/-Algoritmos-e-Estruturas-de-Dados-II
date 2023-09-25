/*
 * Guilherme Araújo Mendes de Souza - 156437
 * UNIFESP - ICT
 * AED 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int vetor[], int n) {
  int maximo = vetor[0];
  for (int i = 1; i < n; i++)
    if (vetor[i] > maximo)
      maximo = vetor[i];
  return maximo;
}

void countingSort(int vetor[], int tamanho, int lugar) {
  int saida[tamanho];
  int maximo = (vetor[0] / lugar) % 10;

  for (int i = 1; i < tamanho; i++) {
    if (((vetor[i] / lugar) % 10) > maximo)
      maximo = (vetor[i] / lugar) % 10;
  }
  int contador[maximo + 1];

  for (int i = 0; i <= maximo; ++i)
    contador[i] = 0;

  for (int i = 0; i < tamanho; i++)
    contador[(vetor[i] / lugar) % 10]++;
    
  for (int i = 1; i <= maximo; i++)
    contador[i] += contador[i - 1];

  for (int i = tamanho - 1; i >= 0; i--) {
    saida[contador[(vetor[i] / lugar) % 10] - 1] = vetor[i];
    contador[(vetor[i] / lugar) % 10]--;
  }

  for (int i = 0; i < tamanho; i++)
    vetor[i] = saida[i];
}

void radixsort(int tamanho, int vetor[]) {
  int maximo = getMax(vetor, tamanho);

  for (int lugar = 1; maximo / lugar > 0; lugar *= 10)
    countingSort(vetor, tamanho, lugar);
}

int main() {
    clock_t inicio, fim;
    FILE *arquivo;
    char nome[25];
    int tamanhoVetor;
    int i = 0;

    printf("Informe o nome do arquivo: ");
    scanf("%s", nome);

    printf("\nInforme o tamanho do arquivo: ");
    scanf("%d", &tamanhoVetor);

    int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

    if (vetor == NULL) {
        printf("\nFalha na alocação de memória.\n");
        return 1;
    }

    arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo\n");
        return 1;
    }

    while (i < tamanhoVetor && fscanf(arquivo, "%d", &vetor[i]) != EOF) {
        i++;
    }
    
    fclose(arquivo);

    inicio = clock();
    radixsort(tamanhoVetor, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo de CPU com %d posições no vetor: %f milissegundos\n", tamanhoVetor, tempo_decorrido);

    free(vetor);
    return 0;
}
