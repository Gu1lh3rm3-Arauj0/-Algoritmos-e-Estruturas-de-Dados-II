'''
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED 2
'''
import time

def countingSort(vetor, lugar):
    tamanho = len(vetor)
    saida = [0] * tamanho
    contador = [0] * 10

    for i in range(0, tamanho):
        indice = (vetor[i] // lugar) % 10
        contador[indice] += 1

    for i in range(1, 10):
        contador[i] += contador[i - 1]

    i = tamanho - 1
    while i >= 0:
        indice = (vetor[i] // lugar) % 10
        saida[contador[indice] - 1] = vetor[i]
        contador[indice] -= 1
        i -= 1

    for i in range(0, tamanho):
        vetor[i] = saida[i]

def radixSort(vetor):
    maximo_elemento = max(vetor)
    lugar = 1

    while maximo_elemento // lugar > 0:
        countingSort(vetor, lugar)
        lugar *= 10

nome = input('Informe o nome do arquivo: ')
tamanho_vetor = int(input('Informe o tamanho do arquivo: '))
vetor = []

arquivo = open(nome, 'r')

for linha in arquivo:
    vetor.append(int(linha.strip()))  # Converte a linha para inteiro

arquivo.close()

inicio = time.process_time()
radixSort(vetor)
fim = time.process_time()

tempo_decorrido = (fim - inicio) * 1000  # Multiplica por 1000 para obter milissegundos
print(f'Tempo de CPU com {tamanho_vetor} posições no vetor: {tempo_decorrido} milissegundos')