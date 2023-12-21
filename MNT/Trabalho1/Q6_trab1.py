# -*- coding: utf-8 -*-
"""
Created on Fri Aug  6 17:24:52 2021

@author: dekom
"""
#Trabalho 1 - Questão 6

import matplotlib.pyplot as plt
#import numpy as np

dias = ['8/7','9/7','12/7','13/7','14/7','15/7','16/7',
        '19/7','20/7','21/7','22/7','23/7','26/7','27/7',
        '28/7','29/7','30/7','2/8','3/8','4/8']
cotacao = [5.2587,5.2393,5.2239,5.1770,5.0880,5.1000,5.0941,5.1978,5.2465
           ,5.2516,5.1978,5.1701,5.1863,5.1669,5.1527
           ,5.0682,5.1216,5.1379,5.2464,5.2091]

#Personificação do Gráfico.
plt.figure(figsize=(12, 8))
plt.grid(True)
plt.xlabel('Dias',color='tab:red',fontsize=15)
plt.ylabel('Cotação do Dólar($)',color='tab:red',fontsize=15)
plt.title("Cotação do Dólar entre os dias 8/7 e 4/8 de 2021",color='gold',
fontsize=20)
plt.plot(dias,cotacao,color='teal',linewidth=4)
plt.scatter(dias,cotacao,marker="x",color='tomato')
plt.style.use(['dark_background'])
plt.savefig('cotacao.png',format='png',dpi=1200)
plt.show()

