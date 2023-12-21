# -*- coding: utf-8 -*-
"""
Created on Fri Aug  6 22:12:08 2021

@author: dekom
"""

#Trabalho 1 - Exercício 7

import numpy as np

#def g(y):
#    return 2.0*np.cosh(y/4.0)

#def g(y):
#    return 4*np.arccosh(y/2.0) 

#Chute inicial.
x = 5.0

#Tolerância.
atol = 1e-8
k = 0
dif = 2*atol

while dif >= atol:
    x_novo = g(x)
    dif = abs(x_novo-x)
    x = x_novo
    k+=1
    print("Na iteração k=%i, o valor de x é %12.10f"%(k,x))
print(x)