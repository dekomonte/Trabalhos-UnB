# -*- coding: utf-8 -*-
"""
Created on Mon Aug 23 14:22:41 2021

@author: dekom
"""

import numpy as np 
import matplotlib.pyplot as plt

def f(t,y):
    p=np.pi
    a=np.exp(-0.06*p*t)
    s1=np.sin(2*t)
    c1=np.cos(2*t)
    
    #----v----
    t1=-(a/1.7)*s1
    
    #----v'----
    m=1/(1.4*50)
    n=3*p*s1
    o=-100*c1
    t2=a*m*(n+o)
    
    #----v''----
    x=-0.3/2500
    y=(9*p*p-10000)*s1
    z=-600*p*c1
    t3=a*x*(y+z)

    r=t1+t2+t3
    return r

def euler_exp(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(t[i],0)
    
    plt.scatter(t,y,marker="o",color="blueviolet")
    plt.xlabel('Tempo(s)')
    plt.ylabel('i(A)')
    plt.grid(True)
    plt.title("Euler Explícito")
    plt.savefig('euler_exp.png',format='png',dpi=600)
    plt.show()

def rk_quarta(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt))
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
        
    plt.scatter(t,y,marker="o",color="forestgreen")
    plt.xlabel('Tempo(s)')
    plt.ylabel('i(A)')
    plt.grid(True)
    plt.title("Runge-Kutta de Quarta Ordem")
    plt.savefig('rk_4.png',format='png',dpi=600)
    plt.show()
    
#ti,tf,y0,dt
rk_quarta(0.0,10.0,0.0,0.05)
euler_exp(0.0,10.0,0.0,0.05)