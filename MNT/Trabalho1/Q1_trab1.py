#Trabalho Parcial 1

#Exercício 1

#Função que multiplica duas matrizes e mostra na tela o resultado.
def multiplicacao_matrizes(a,b,lin_a,col_b,lin_b):
    mat_c=np.zeros((lin_a,col_b),int)
    num=0
    for i in range(0,lin_a):
        for j in range(0,col_b):
            for k in range(0,lin_b):
                num+=a[i][k]*b[k][j]
            mat_c[i][j]=num
            num=0
    print("\n")
    print("O resultado da multiplicação é:")
    print(mat_c)            

import numpy as np

la = int(input("Qual o número de Linhas de A?"))
ca = int(input("Qual o número de Colunas de A?"))

lb = int(input("Qual o número de Linhas de B?"))
cb = int(input("Qual o número de Colunas de B?"))
 
#Teste para saber se a multiplicação é possível.    
if ca != lb:
    print("ERRO! Não é possível executar essa operação.")
else:
    
    #Esse trecho serve para obter os dados das duas matrizes.
    mat_a=np.zeros((la,ca),int)
    mat_b=np.zeros((lb,cb),int)
    
    aux_a=np.zeros(ca)
    
    print("\n")
    print("Definição de A")
    
    for i in range(0,la):
        for j in range (0,ca):
            x = int(input("Digite um elemento:"))
            aux_a[j]=x
        mat_a[i]=aux_a
        aux_a=np.zeros(ca)
    
    #print(mat_a)
    
    aux_b=np.zeros(cb)
    
    print("\n")
    print("Definição de B")
    
    for k in range(0,lb):
        for l in range (0,cb):
            y = int(input("Digite um elemento:"))
            aux_b[l]=y
        mat_b[k]=aux_b
        aux_b=np.zeros(cb)
    
    #print(mat_b)
    
    multiplicacao_matrizes(mat_a,mat_b,la,cb,lb)
    
       
            
    