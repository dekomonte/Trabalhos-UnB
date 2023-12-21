# -*- coding: utf-8 -*-
"""
Created on Sat Aug  7 15:11:07 2021

@author: dekom
"""

import numpy as np

#def g(y):
#    return 2.0*np.cosh(y/4.0)

def g(y):
    return 4*np.arccosh(y/2.0) 

#Resolução usando o Método do Ponto-Fixo.
def ponto_fixo():
    x=5.0
    n=100
    atol=1.e-8
    i=0
    while i<=n :
        p=g(x)
        if abs(p-x)<atol:
            return p
            break
        i+=1
        #print('Na iteração %i, o valor de x é:%12.10f' %(i,x))
        x=p
    return False

resp = ponto_fixo()
if resp == False:
    print("O procedimento não foi bem sucedido.")
else:
    print(resp,"é raiz de f(x).")

        
        