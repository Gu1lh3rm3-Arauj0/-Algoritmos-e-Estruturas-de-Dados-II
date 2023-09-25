'''
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED 2
'''
import time

def separa(p, r, v):
    c = v[r]
    j = p
    for k in range(p, r):
        if v[k] <= c:
            t = v[j]
            v[j] = v[k]
            v[k] = t
            j += 1
    v[r] = v[j]
    v[j] = c
    return j

def quicksort (p, r, v):
    if(p<r):
        j = separa(p, r, v)
        quicksort(p, j-1, v)
        quicksort(j+1, r, v)


nome = input('Informe o nome do arquivo: ')
tamanho_vetor = int(input('Informe o tamanho do arquivo: '))
vetor = []

arquivo = open(nome, 'r')

for linhas in arquivo:
    vetor.append(linhas.strip())

arquivo.close()

inicio = time.process_time()
quicksort(0, tamanho_vetor-1, vetor)
fim = time.process_time()

tempo_decorrido = fim - inicio
print(f'Tempo de CPU com {tamanho_vetor} posições no vetor: {tempo_decorrido*1000} milissegundos')