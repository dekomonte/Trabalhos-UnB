# -*- coding: utf-8 -*-
"""
Created on Sat Aug 21 09:34:07 2021

@author: dekom
"""

import numpy as np 
import matplotlib.pyplot as plt

def f(t,y):
    r=1+0.5*pow(y,2)
    return r

def exata(t):
    a=pow(0.5,3/2)
    b=np.arctan(a)
    c=b+t*np.sqrt(0.5)
    d=np.tan(c)
    e=1/np.sqrt(0.5)
    resp=e*d
    return resp

#----------Métodos de Euler-------------
def euler_exp(ti,tf,y0,dt):

    n=int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=t[i]+dt
        y[i+1]=y[i]+dt*f(t[i],y[i])
    
    y_exata=exata(t)
    plt.scatter(t,y,marker="o",color="blueviolet")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Euler Explícito")
    plt.savefig('euler_exp5.png',format='png',dpi=600)
    plt.show()
    

#----------Runge-Kutta------------------

def rk_seg(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=t[i]+dt
        k1=dt*f(t[i],y[i])
        k2=dt*f(t[i]+dt,y[i]+k1)
        y[i+1]=y[i]+1/2*(k1+k2)
         
    y_exata=exata(t)
    plt.scatter(t,y,marker="o",color="gold")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Runge-Kutta de Segunda Ordem")
    plt.savefig('rk_25.png',format='png',dpi=600)
    plt.show()
    
def rk_quarta(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=t[i]+dt
        k1=dt*f(t[i],y[i])
        k2=dt*f(t[i]+dt/2,y[i]+k1/2)
        k3=dt*f(t[i]+dt/2,y[i]+k2/2)
        k4=dt*f(t[i]+dt,y[i]+k3)
        y[i+1]=y[i]+1/6*(k1+2*k2+2*k3+k4)
        
    y_exata=exata(t)
    plt.scatter(t,y,marker="o",color="forestgreen")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Runge-Kutta de Quarta Ordem")
    plt.savefig('rk_45.png',format='png',dpi=600)
    plt.show()
    
        
#ti,tf,y0,dt
euler_exp(0.0,1.0,0.5,0.05)
rk_seg(0.0,1.0,0.5,0.05)
rk_quarta(0.0,1.0,0.5,0.05)
