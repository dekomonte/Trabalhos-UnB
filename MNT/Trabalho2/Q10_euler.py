# -*- coding: utf-8 -*-
"""
Created on Tue Aug 24 11:23:19 2021

@author: dekom
"""

import numpy as np 
import matplotlib.pyplot as plt

def f(n1,n2):
    a1=0.1
    b1=8*1e-7
    c1=1e-6
    n1=a1*n1-b1*pow(n1,2)-c1*n1*n2
    return n1

def f2(n1,n2):
    a2=0.1
    b2=8*1e-7
    c2=1e-7
    n2=a2*n2-b2*pow(n2,2)-c2*n1*n2
    return n2

#----------Métodos de Euler-------------
def euler_exp(ti,tf,dt):

    n=int(round((tf-ti)/dt)) 
    t=np.zeros(n,float)
    t[0]=ti
    y1=np.zeros(n,float)
    y1[0]=100000
    y2=np.zeros(n,float)
    y2[0]=100000
    
    for i in range(n-1):
        t[i+1]=t[i]+dt
        y1[i+1]=y1[i]+dt*f(y1[i],y2[i])
        y2[i+1]=y2[i]+dt*f2(y1[i],y2[i])
    
    plt.plot(t,y1,marker="o",color="forestgreen",label="$N_{1}(t)$")
    plt.plot(t,y2,marker='o',color='red',label="$N_{2}(t)$")
    plt.title("População x Tempo")
    plt.xlabel("Tempo (anos)")
    plt.ylabel("População $N_{i}$ (Indivíduos)")
    plt.grid(True)
    plt.legend()
    plt.show()
    
euler_exp(0.0,10.0,1.0)