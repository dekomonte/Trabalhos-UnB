# -*- coding: utf-8 -*-
"""
Created on Sat Oct  2 18:31:41 2021

@author: dekom
"""

#Trabalho 3 - Questão 8

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
from matplotlib import cm

Nx=10
Ny=10
dx=1.0/Nx
dy=1.0/Ny
ti=0.0
tf=10.0
dt=0.001
k1=dt/(dx**2)
k2=dt/(dy**2)

T=np.zeros((Nx+1,Ny+1),float)

x=np.linspace(0.0,1.0,Nx+1)
y=np.linspace(0.0,1.0,Ny+1)

#Condições de contorno
limite=2/3
for l in range(Nx):
    if x[l]<=limite:
        T[l,1]=75*x[l]
    else:
        T[l,1]=150*(1.0-x[l])

T_nova=np.copy(T)

while ti < (tf-0.01*dt):
    
    for i in range(1,Nx):
        for j in range(1,Ny):
            T_nova[i,j]=T[i,j]+k1*(T[i+1,j]-(2.0*T[i,j])+T[i-1,j])\
            +k2*(T[i,j+1]-(2.0*T[i,j])+T[i,j-1])
    
    T=np.copy(T_nova)
    ti+=dt


#Gráfico 3D - Solução Numérica

plt.figure(figsize=((20,8)))
ax=plt.axes(projection='3d')
X,Y = np.meshgrid(x,y)

ax.set_xlabel('$x$',fontsize=20)
ax.set_ylabel('$y$',fontsize=20)
ax.set_zlabel('$T$',fontsize=20)

ax.set_title("Temperatura para $t = $10.0s e $\Delta t$ = 0.001",fontsize=20)

ax.dist=8
ax.plot_surface(X,Y,np.transpose(T),cmap='coolwarm',linewidth=0
                ,antialiased=False)
plt.savefig('f2_3d.png',format='png',dpi=600,bbox_inches='tight')

#Solução Exata

x=np.linspace(0.0,1.0,100)
y=np.linspace(0.0,1.0,100)

Te=np.zeros((100,100),float)
soma=0.0
n=1
for t in range (100):
   soma=0.0
   for r in range(100):
       s1=np.sin((2*n*np.pi)/3)
       s2=n**2*np.sinh(n*np.pi)
       s3=np.sin(n*np.pi*x[t])
       s4=np.sinh(n*np.pi*y[r])
       soma+=(s1/s2)*s3*s4
   Te[t,r]=(450/(np.pi**2))*soma
   n+=1
       

plt.figure(figsize=((20,8)))
ax=plt.axes(projection='3d')
X,Y = np.meshgrid(x,y)

ax.set_xlabel('$x$',fontsize=20)
ax.set_ylabel('$y$',fontsize=20)
ax.set_zlabel('$T$',fontsize=20)

ax.set_title("Solução Analítica",fontsize=20)

ax.dist=8
ax.plot_surface(X,Y,np.transpose(Te),cmap='coolwarm',linewidth=0
                ,antialiased=False)
#plt.savefig('exata1_3d.png',format='png',dpi=600,bbox_inches='tight')

            