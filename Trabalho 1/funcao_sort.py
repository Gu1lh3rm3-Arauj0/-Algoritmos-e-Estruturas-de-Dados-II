'''
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED 2
'''
import time
nome = input('Informe o nome do arquivo: ')
tamanho_vetor = int(input('Informe o tamanho do arquivo: '))
vetor = []

arquivo = open(nome, 'r')

for linhas in arquivo:
    vetor.append(linhas.strip())

arquivo.close()

inicio = time.process_time()
vetor.sort()
fim = time.process_time()

tempo_decorrido = fim - inicio
print(f'Tempo de CPU com {tamanho_vetor} posições no vetor: {tempo_decorrido*1000} milissegundos')