/*
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED II
     
Judge 5 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODON_SIZE 3
#define RNA_SIZE 10000
#define UNKNOWN '*'

typedef struct {
    char codon[CODON_SIZE + 1];
    char aminoacid;
} CodonAminoacid;

int compare_codon_aminoacid(const void *a, const void *b) {
    CodonAminoacid *ca1 = (CodonAminoacid *) a;
    CodonAminoacid *ca2 = (CodonAminoacid *) b;
    return strcmp(ca1->codon, ca2->codon);
}

char *translate(char *rna, CodonAminoacid *dictionary, int n) {
    int rna_size = strlen(rna);

    int amino_size = rna_size / 3 + 1;

    char *amino = malloc(amino_size * sizeof(char));

    int amino_index = 0;

    for (int i = 0; i < rna_size; i += 3) {
        char codon[CODON_SIZE + 1];

        strncpy(codon, rna + i, CODON_SIZE);

        codon[CODON_SIZE] = '\0';

        CodonAminoacid ca;
        strcpy(ca.codon, codon);

        CodonAminoacid *result = bsearch(&ca, dictionary, n, sizeof(CodonAminoacid), compare_codon_aminoacid);

        if (result == NULL) {
            amino[amino_index] = UNKNOWN;
        } else {
            amino[amino_index] = result->aminoacid;
        }
        amino_index++;
    }
    amino[amino_index] = '\0';

    return amino;
}

int main() {
    int n;

    scanf("%d", &n);

    CodonAminoacid *dictionary = malloc(n * sizeof(CodonAminoacid));

    for (int i = 0; i < n; i++) {
        scanf("%s %c", dictionary[i].codon, &dictionary[i].aminoacid);
    }

    qsort(dictionary, n, sizeof(CodonAminoacid), compare_codon_aminoacid);

    int m;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char rna[RNA_SIZE + 1];

        scanf("%s", rna);

        char *amino = translate(rna, dictionary, n);

        printf("%s\n", amino);

        free(amino);
    }

    free(dictionary);

    return 0;
}
