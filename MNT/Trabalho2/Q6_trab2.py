# -*- coding: utf-8 -*-
"""
Created on Fri Aug 20 15:48:23 2021

@author: dekom
"""

#Trabalho 2 - Questão 6

import numpy as np 
import matplotlib.pyplot as plt

def f(t,y):
    r=2-2*pow(t,1)+4*pow(t,2)-4*pow(t,3)-4*pow(t,4)
    return r

def exata(t,y):
    resp=1+2*t-pow(t,2)+(4/3)*pow(t,3)-pow(t,4)-(4/5)*pow(t,5)
    return resp

#----------Métodos de Euler-------------
def euler_exp(ti,tf,y0,dt):
    
    n=1+int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(t[i],0)
    
    y_exata=exata(t,0)
    
    erro1=np.zeros(n,float)
    erro1=np.abs(y-y_exata)
    print('Erro Euler Explícito em t=1s: ',erro1[n-1])
    plt.plot(t,erro1,color='blueviolet',label='Euler Explícito')
    
def euler_imp(ti,tf,y0,dt):
    
    
    n=1+int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(t[i+1],0)
        
    
    y_exata=exata(t,0)
    erro2=np.zeros(n,float)
    erro2=np.abs(y-y_exata)
    print('Erro Euler Impplícito em t=1s: ',erro2[n-1])
    plt.plot(t,erro2,color='royalblue',label='Euler Implícito')
    
    
#----------Runge-Kutta------------------

def rk_seg(ti,tf,y0,dt):
    
    n=1+int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        k1=dt*f(t[i],0)
        k2=dt*f(t[i]+dt,0)
        y[i+1]=y[i]+1/2*(k1+k2)
         
    y_exata=exata(t,0)
    erro3=np.zeros(n,float)
    erro3=np.abs(y-y_exata)
    print('Erro Runge-Kutta 2ª Ordem em t=1s:',erro3[n-1])
    plt.plot(t,erro3,color='gold',label='Runge-Kutta 2ª Ordem')
    
    
def rk_quarta(ti,tf,y0,dt):
    
    n=1+int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        k1=dt*f(t[i],0)
        k2=dt*f(t[i]+dt/2,0+k1/2)
        k3=dt*f(t[i]+dt/2,0+k2/2)
        k4=dt*f(t[i]+dt,k3)
        y[i+1]=y[i]+1/6*(k1+2*k2+2*k3+k4)
        
    y_exata=exata(t,0)
    erro4=np.zeros(n,float)
    erro4=np.abs(y-y_exata)
    print('Erro Runge-Kutta 4ª Ordem em t=1s:',erro4[n-1])
    plt.plot(t,erro4,color='forestgreen',label='Runge-Kutta 4ª Ordem')
    
            
#ti,tf,y0,dt
euler_exp(0.0,1.0,1.0,0.1)
euler_imp(0.0,1.0,1.0,0.1)
rk_seg(0.0,1.0,1.0,0.1)
rk_quarta(0.0,1.0,1.0,0.1)
plt.xlabel(r'$\Delta t$')
plt.ylabel('Erro Relativo')
plt.title("Erro Relativo x $\Delta t$")
plt.legend()
plt.grid(True)
plt.savefig('erro_dt.png',format='png',dpi=600)