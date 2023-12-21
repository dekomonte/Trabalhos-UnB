# -*- coding: utf-8 -*-
"""
Created on Fri Aug 20 15:48:23 2021

@author: dekom
"""

#Trabalho 2 - Questão 2

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
    #ti=0.0
    #tf=1.0
    #y0=1.0
    #dt=0.1
    n=int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(t[i],0)
    
    y_exata=exata(t,0)
    plt.scatter(t,y,marker="o",color="blueviolet")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Euler Explícito")
    #plt.savefig('euler_exp.png',format='png',dpi=600)
    plt.show()
    
def euler_imp(ti,tf,y0,dt):
    
    
    n=int(round((tf-ti)/dt))
    t=np.zeros(n,float)
    t[0]=ti
    y=np.zeros(n,float)
    y[0]=y0
    
    for i in range(n-1):
        t[i+1]=(i+1)*dt
        y[i+1]=y[i]+dt*f(t[i+1],0)
        
    
    y_exata=exata(t,0)
    plt.scatter(t,y,marker="o",color="royalblue")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Euler Implicito")
    #plt.savefig('euler_imp.png',format='png',dpi=600)
    plt.show()

#----------Runge-Kutta------------------

def rk_seg(ti,tf,y0,dt):
    
    n=int(round((tf-ti)/dt))
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
    plt.scatter(t,y,marker="o",color="gold")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Runge-Kutta de Segunda Ordem")
    #plt.savefig('rk_2.png',format='png',dpi=600)
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
        
    y_exata=exata(t,0)
    plt.scatter(t,y,marker="o",color="forestgreen")
    plt.plot(t,y_exata,'-r')
    plt.xlabel('Tempo(s)')
    plt.ylabel('y')
    plt.grid(True)
    plt.title("Runge-Kutta de Quarta Ordem")
    #plt.savefig('rk_4.png',format='png',dpi=600)
    plt.show()
    
        
#ti,tf,y0,dt
euler_exp(0.0,1.0,1.0,0.1)
euler_imp(0.0,1.0,1.0,0.1)
rk_seg(0.0,1.0,1.0,0.1)
rk_quarta(0.0,1.0,1.0,0.1)
