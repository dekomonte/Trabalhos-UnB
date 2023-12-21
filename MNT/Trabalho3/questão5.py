# -*- coding: utf-8 -*-
"""
Created on Mon Sep 27 13:48:51 2021

@author: dekom
"""

#Trabalho 3 - Questão 5

import numpy as np
import matplotlib.pyplot as plt
    

N=10
dx=0.5/N
ti=0.0
tf=0.5
dt=0.00005

k=dt/(dx**2.0)

#Condições Iniciais
x=np.linspace(0.0,0.5,N+1)
T=np.zeros(N+1,float)

for l in range(N+1):
    T[l]=200*x[l]
    
#print(T)

T_nova=np.copy(T)


while ti < tf-(0.01*dt):
    for i in range(1,N):
        T_nova[i]=T[i]+k*0.01*(T[i+1]-2.0*T[i]+T[i-1])
        
    T_nova[N]=T_nova[N-1]
    T=np.copy(T_nova)
    ti+=dt
 
x_exata=np.linspace(0.0,0.5,100)  
T_exata=np.zeros(100,float)

soma=0.0
for y in range(100):
    soma=0.0
    for n in range(100):
        a=(2*n)+1
        s=np.sin(a*np.pi*x_exata[y])
        e=np.exp(-a**2*np.pi**2*tf*0.01)
        c=(-1)**n
        soma+=(c/(a**2))*s*e
    T_exata[y]=(800/(np.pi**2))*soma
    
    

plt.plot(x,T,'bo',label='Solução numérica')
plt.plot(x_exata,T_exata,'-r',label='Solução analítica')

plt.grid(True)
plt.title("Temperatura para $t = $ 0.5 s, com $\Delta t$ = 0.00005\n Condição de contorno de Neumann")

plt.xlabel("x")
plt.ylabel("T")
plt.legend()
plt.plot()
plt.savefig('Fig5_6.png',format='png',dpi=600)