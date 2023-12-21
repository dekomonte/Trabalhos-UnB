# -*- coding: utf-8 -*-
"""
Created on Sat Aug  7 18:51:11 2021

@author: dekom
"""

#Trabalho 1 - Exercício 8

import numpy as np

def f(x):
    return 2*np.cosh(x/4.0)-x

#Para r=8.51
x0=1.0
x1=10.0
#Para r=2.36, mudar(inverter) os valores.

atol=1.e-8
dif=2*atol

y0=f(x0)
y1=f(x1)

while dif>=atol :
    r=x1-y1*(x1-x0)/(y1-y0)
    if abs(r-x1) < atol:
        print(r,"é raiz da função f(x)")
        break
    dif=abs(r-x1)
    x0=x1
    y0=y1
    x1=r
    y1=f(r)
    
#print("O procedimento não foi bem sucedido.")