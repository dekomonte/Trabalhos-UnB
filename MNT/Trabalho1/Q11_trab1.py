# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 15:36:48 2021

@author: dekom
"""

#Trabalho 1 - Questão 11

import numpy as np
import math

def f(x):
    #return 2.5*np.sinh(x/4.0-1.0)
    return np.sin(x)-2*x

def bisseccao():
    atol=1.e-8
    a=10.0
    b=1.0
    fa=f(a)
    fb=f(b)
    #print(fa)
    #print(fb)
    i=0
    k=abs(b-a/(2*atol))
    #print(k)
    n=int(math.log(k, 2))
    #print(n)
    #print(fa*fb)
    
    if fa*fb<0:
        while i<=n:
            p=(a+b)/2
            #if f(a)*f(b)<0.0:
            b=p
            #else:
            a=p
            i+=1
        print("ERRO. O número de iterações foi alcançado.")
        print(p)
    else:
        print("f(a)*f(b) não é menor que 0.")
    
        
bisseccao()