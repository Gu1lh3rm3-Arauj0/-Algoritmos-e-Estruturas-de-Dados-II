    /*
    Guilherme Araújo Mendes de Souza - 156437
    UNIFESP - ICT
    AED II
     
    Judge 2
    */
     
    #include <stdio.h>
    #include <stdlib.h>
     
    typedef struct {
        int senha;
        int valor;
    } Comprador;
     
    typedef struct {
        Comprador* compradores;
        int capacidade;
        int tamanho;
    } FilaCompradores;
     
    FilaCompradores* criarFila(int capacidade) {
        FilaCompradores* fila = (FilaCompradores*)malloc(sizeof(FilaCompradores));
        fila->capacidade = capacidade;
        fila->tamanho = 0;
        fila->compradores = (Comprador*)malloc(capacidade * sizeof(Comprador));
        return fila;
    }
     
    void destruirFila(FilaCompradores* fila) {
        free(fila->compradores);
        free(fila);
    }
     
    void inserirCompra(FilaCompradores* fila, int senha, int valor) {
        if (fila->tamanho < fila->capacidade) {
            fila->compradores[fila->tamanho].senha = senha;
            fila->compradores[fila->tamanho].valor = valor;
            fila->tamanho++;
        }
    }
     
    void realizarVenda(FilaCompradores* fila) {
        int i, index_maior = -1;
        int maior_valor = 0;
     
        for (i = 0; i < fila->tamanho; i++) {
            if (fila->compradores[i].valor > maior_valor) {
                maior_valor = fila->compradores[i].valor;
                index_maior = i;
            }
        }
     
        if (index_maior >= 0) {
            printf("%d\n", fila->compradores[index_maior].senha);
            for (i = index_maior + 1; i < fila->tamanho; i++) {
                fila->compradores[i - 1] = fila->compradores[i];
            }
            fila->tamanho--;
        } else {
            printf("0\n");
        }
    }
     
    int main() {
        FilaCompradores* fila = criarFila(1000000);
        int senha_atual = 1;
        char operacao;
        int valor;
     
        while (1) {
            scanf(" %c", &operacao);
            if (operacao == 'f') {
                break;
            }
            if (operacao == 'c') {
                scanf("%d", &valor);
                inserirCompra(fila, senha_atual, valor);
                senha_atual++;
            } else if (operacao == 'v') {
                realizarVenda(fila);
            }
        }
     
        destruirFila(fila);
        return 0;
    }