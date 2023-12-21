#Trabalho 1

#Exercício 2

import numpy as np
import math

m = int(input("Digite M:"))
n = int(input("Digite N:"))

matriz=np.zeros((m,n),int) 
aux=np.zeros(n)
soma=0.0

for i in range (0,m):
    for j in range(0,n):
        x = int(input("Digite um elemento:"))
        aux[j]=x
        soma+=x
    matriz[i]=aux
    aux=np.zeros(n)
    
#print(matriz)
total_num=m*n

#Média.
media=soma/(total_num)
print("A Média é:",media)


soma_dp=0.0

#Desvio Padrão.
for k in range (0,m):
    for l in range (0,n):
        y=matriz[k][l]
        z=abs(y-media)
        z=z*z
        soma_dp+=(z/total_num)
            
dp=math.sqrt(soma_dp)
print("O Desvio Padrão é:",dp)
        