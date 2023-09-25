/*
 * Guilherme Araújo Mendes de Souza - 156437
 * UNIFESP - ICT
 * AED 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa (int p, int r, int v[]) {
	int c, j, k, t;
	c = v[r]; j = p;
	for (k = p; k < r; k++)
		if (v[k] <= c) {
			t = v[j], v[j] = v[k], v[k] = t;
			j++;
		}
	v[r] = v[j], v[j] = c;
	return j;
}

void Quicksort (int p, int r, int v[]) {
	int j;
	if (p < r) {
		j = Separa (p, r, v);
		Quicksort (p, j - 1, v);
		Quicksort (j + 1, r, v);
	}
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
    Quicksort(0, tamanhoVetor, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo de CPU com %d posições no vetor: %f milissegundos\n", tamanhoVetor, tempo_decorrido);

    free(vetor);
    return 0;
}
