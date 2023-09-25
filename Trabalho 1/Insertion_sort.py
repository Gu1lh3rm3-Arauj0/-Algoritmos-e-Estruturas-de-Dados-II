'''
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED 2
'''
import time

def insercao(n, v):
    for i in range(1, n):
        x = v[i]
        j = i - 1
        while j >= 0 and v[j] > x:
            v[j + 1] = v[j]
            j -= 1
        v[j + 1] = x

nome = input('Informe o nome do arquivo: ')
tamanho_vetor = int(input('Informe o tamanho do arquivo: '))
vetor = []

arquivo = open(nome, 'r')

for linhas in arquivo:
    vetor.append(linhas.strip())

arquivo.close()

inicio = time.process_time()
insercao(tamanho_vetor, vetor)
fim = time.process_time()

tempo_decorrido = fim - inicio
print(f'Tempo de CPU com {tamanho_vetor} posições no vetor: {tempo_decorrido*1000} milissegundos')
