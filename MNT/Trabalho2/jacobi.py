# -*- coding: utf-8 -*-
"""
Created on Fri Sep  3 11:28:28 2021

@author: dekom
"""

import numpy as np

A=np.array([[4.0,-2.0,1.0],[2.0,5.0,-1.0],[1.0,3.0,-7.0]])
b=np.array([3.0,6.0,-3.0])

x=np.zeros(3,float)
x_new=np.copy(x)

R=np.zeros(3,float)

for it in range(10):
    for i in range(3):
        soma=0.0
        for j in range(3):
            soma=soma+A[i,j]*x[j]
            
        R[i]=(1.0/A[i,i])*(b[i]-soma)
        x_new[i]=x[i]+R[i]
        
    x=np.copy(x_new)
    
    print(f'Iteração {it+1}.')
    print(f'R = {R} ')
    print(f'x={x}\n')