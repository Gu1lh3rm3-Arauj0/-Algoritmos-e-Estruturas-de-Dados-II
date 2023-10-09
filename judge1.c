    /*
    Guilherme Araújo Mendes de Souza - 156437
    UNIFESP - ICT
    AED II
     
    Judge 1
    */
#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int Separa (int p, int r, int *S) {
	int c, j, k, t;
	c = S[r]; j = p;
	for (k = p; k < r; k++)
		if (S[k] <= c) {
			t = S[j], S[j] = S[k], S[k] = t;
			j++;
		}
	S[r] = S[j], S[j] = c;
	return j;
}

void Quicksort (int p, int r, int *S) {
	int j;
	if (p < r) {
		j = Separa (p, r, S);
		Quicksort (p, j - 1, S);
		Quicksort (j + 1, r, S);
	}
}

int conta_pares(int *S, int n, int N) {
    int i = 0; 
    int j = n - 1; 
    int cont = 0; 
    while (i < j) {
        int soma = S[i] + S[j]; 
        if (soma == N) { 
            cont++; 
            i++; 
            j--; 
            while (i < j && S[i] == S[i-1]) i++; 
            while (i < j && S[j] == S[j+1]) j--;
        }
        else if (soma < N) { 
            i++; 
        }
        else { 
            j--; 
        }
    }
    return cont; 
}

int main() {
    int n, N;
    scanf("%d %d", &n, &N); 
    int *S = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { 
        scanf("%d", &S[i]); 
    }
    Quicksort(0, n - 1, S);
    int pares = conta_pares(S, n, N);
    printf("%d\n", pares);
    return 0;
}
