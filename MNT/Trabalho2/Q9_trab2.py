# -*- coding: utf-8 -*-
"""
Created on Mon Aug 23 21:18:33 2021

@author: dekom
"""

import numpy as np 
import matplotlib.pyplot as plt

def f(t,y):
    a=0.1
    b=10e-6
    r=a*y-b*pow(y,2)
    #print(r)
    return r

def euler_exp(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(0,y[i])
    
    y_e=np.zeros(n,float)
    y_e=y
    plt.plot(t,y_e,'o',color='blueviolet',label='Euler Explícito')
   

def rk_quarta(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        k1=dt*f(0,y[i])
        k2=dt*f(0,y[i]+k1/2)
        k3=dt*f(0,0+k2/2)
        k4=dt*f(0,k3)
        y[i+1]=y[i]+1/6*(k1+2*k2+2*k3+k4)
    
    y_rk=np.zeros(n,float)
    y_rk=y
    plt.plot(t,y_rk,'o',color='forestgreen',label='Runge-Kutta 4ª Ordem')
    
    
#ti,tf,y0,dt
euler_exp(0.0,20.0,100,1.0)
rk_quarta(0.0,20.0,100,1.0)
plt.xlabel("Tempo (anos)")
plt.ylabel('População N (milhares)')
plt.title("População N x Tempo, $b=10^{-6}$")
plt.legend()
plt.grid(True)
#plt.savefig('nxt_b-3.png',format='png',dpi=600)
