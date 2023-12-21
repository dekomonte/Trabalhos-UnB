#Trabalho 1

#Exercício 3

import math
import numpy as np

#Adaptação da questão anterior.
def media_dp(mat,l_c,soma):
    
   total=(l_c*l_c)   
   media=soma/total
   soma_dp=0.0
   
   for i in range(0,l_c):
       for j in range(0,l_c):
           x=mat[i][j]
           z=abs(x-media)
           z=z*z
           soma_dp+=(z/total)
    
   dp=math.sqrt(soma_dp)
   print(mat)
   print("A Média é:",media)
   print("O Desvio Padrão é:",dp)

#Criação da matriz de números aleatórios. 
n = int(input("Qual o valor de n?"))
matriz = np.random.randint(-2,2,size=(n,n))

#Precisei fazer isso para poder mandar a soma dos elementos da matriz de 
#números aleatórios direto para a função de média e desvio padrão.
sum=0.0
for k in range(0,n):
    for l in range(0,n):
        sum+=matriz[k][l]

media_dp(matriz,n,sum)

#print(matriz)

