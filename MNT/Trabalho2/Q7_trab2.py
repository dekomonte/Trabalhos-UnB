# -*- coding: utf-8 -*-
"""
Created on Tue Aug 24 18:53:47 2021

@author: dekom
"""

import numpy as np
import matplotlib.pyplot as plt

def exata_simplificada(t):
    g=9.81
    L=10
    y0=0.5
    y_0=0.0
    w=np.sqrt(g/L)
    r=y0*np.cos(w*t)+(y_0/w)*np.sin(w*t)
    return r


tf=20
ti=0.0
dt=0.01
n=int(round((tf-ti)/dt)) 
t=np.zeros(n,float)
t[0]=ti

for i in range(n-1):
    t[i+1]=t[i]+dt
    
y_exata_simplificada=exata_simplificada(t)
plt.plot(t,y_exata_simplificada,'-r')
plt.title("")
plt.xlabel('Tempo(s)')
plt.ylabel('y')
plt.grid(True)
plt.show()