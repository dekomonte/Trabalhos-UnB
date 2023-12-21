# -*- coding: utf-8 -*-
"""
Created on Mon Sep 27 13:48:51 2021

@author: dekom
"""

#Trabalho 3 - Questão 1

import numpy as np
import matplotlib.pyplot as plt
    

N=10
dx=2.0/N
ti=0.0
tf=10
dt=0.001
k=dt/(dx**2.0)

x=np.linspace(0.0,2.0,N+1)
T=np.zeros(N+1,float)
T_nova=np.copy(T)

#Condição de contorno
T=np.sin(np.pi*x/2)
    

while ti < tf-(0.01*dt):
    for i in range(1,N):
        T_nova[i]=T[i]+k*(T[i+1]-2.0*T[i]+T[i-1])
        
    T=np.copy(T_nova)
    ti+=dt
 
x_exata=np.linspace(0.0,2.0,1001)    
T_exata=np.exp((-np.pi**2)*tf/4)*np.sin(np.pi*x_exata/2)


plt.plot(x,T,'bo',label='Solução numérica')
plt.plot(x_exata,T_exata,'-r',label='Solução analítica')

plt.grid(True)
plt.title("Temperatura para $t = 1.0 s $, com $\Delta t$ = 0.001\n")
plt.xlabel("x")
plt.ylabel("T")
plt.legend()
plt.plot()
plt.savefig('Fig5.png',format='png',dpi=600)