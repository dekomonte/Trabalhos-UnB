# -*- coding: utf-8 -*-
"""
Created on Mon Aug  9 13:25:31 2021

@author: dekom
"""

#Trabalho 1 - Questão 10

import numpy as np

def g(y):
    return (y+2/y)/2

#Método do Ponto Fixo.
x = 5.0
atol = 1e-8
k = 0
dif = 2*atol
while dif >= atol:
    x_novo = g(x)
    dif = abs(x_novo-x)
    x = x_novo
    k+=1
    #print("Na iteração k=%i, o valor de x é %12.10f"%(k,x))
print(x)