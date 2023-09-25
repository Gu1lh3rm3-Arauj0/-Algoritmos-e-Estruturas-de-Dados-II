"""
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED II

Gerador de arquivos com números aleatorios
"""

import random

#Gera um arquivo com números aleatorios entre 1 e 100000
def gerar_arquivo(nome_arquivo, n):
    with open(nome_arquivo, 'w') as arquivo:
        for _ in range(n):
            numero = random.randint(1, 100000)
            arquivo.write(str(numero) + '\n')


nome_do_arquivo = input('Nome do arquivo de saída: ')
n_elementos = int(input('Quantidade de elementos: '))

gerar_arquivo(nome_do_arquivo, n_elementos)
print('Arquivo salvo')