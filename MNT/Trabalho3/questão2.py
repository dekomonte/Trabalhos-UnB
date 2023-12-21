# -*- coding: utf-8 -*-
"""
Created on Mon Sep 27 13:48:51 2021

@author: dekom
"""

#Trabalho 3 - Questão 2

import numpy as np
import matplotlib.pyplot as plt
    

N=10
dx=1.0/N
ti=0.0
tf=0.5
dt=0.00001
k=dt/(dx**2.0)

x=np.linspace(0.0,1.0,N+1)
T=np.ones(N+1,float)

T[0]=0.
T[N]=0.


T_nova=np.copy(T)

#print(T)

while ti < tf-(0.01*dt):
    for i in range(1,N):
        T_nova[i]=T[i]+k*(T[i+1]-2.0*T[i]+T[i-1])
        
    T=np.copy(T_nova)
    ti+=dt
 
x_exata=np.linspace(0.0,1.0,1001)  
T_exata=np.zeros(1001,float)

soma=0.0
for y in range(1,1001):
    soma=0.0
    for n in range(1,1001):
        a=(2*n)-1
        soma+=(4/(a*np.pi))*np.sin(a*np.pi*x_exata[y])*np.exp(-a**2*np.pi**2*tf)
    T_exata[y]=soma
    
    

plt.plot(x,T,'bo',label='Solução numérica')
plt.plot(x_exata,T_exata,'-r',label='Solução analítica')

plt.grid(True)
plt.title("Temperatura para $t = $ 0.5 s, com $\Delta t$ = 0.00001\n")
plt.xlabel("x")
plt.ylabel("T")
plt.legend()
plt.plot()
plt.savefig('Fig2_6.png',format='png',dpi=600)