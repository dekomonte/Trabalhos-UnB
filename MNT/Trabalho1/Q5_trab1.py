# -*- coding: utf-8 -*-
"""
Created on Wed Aug 11 14:59:58 2021

@author: dekom
"""

#Trabalho 1 - Questão 5_Parte 1

import random

#Versão com a mesma probabilidade.
print("Você tem 3 opções:")
print("1-Pedra\n2-Papel\n3-Tesoura")
resp_usuario=int(input("Escolha um número:"))
print("\n")

resp_com=random.randint(1,3)
#print(resp_usuario)
#print(resp_com)

if resp_usuario == 1:
    print("Você escolheu Pedra.")
elif resp_usuario == 2:
    print("Você escolheu Papel.")
else:
    print("Você escolheu Tesoura.")
    
if resp_com == 1:
    print("O computador escolheu Pedra.")
elif resp_com == 2:
    print("O computador escolheu Papel.")
else:
    print("O computador escolheu Tesoura.")
    

if resp_usuario == resp_com:
    print("Empate!")
else:
    if resp_usuario == 1:
        if resp_com == 2:
            print("Derrota!Papel embrulha Pedra!")
        else:
            print("Vitória!:)\nPedra quebra Tesoura!")
    elif resp_usuario == 2:
        if resp_com == 3:
            print("Derrota!Tesoura corta Papel!")
        else:
            print("Vitória!:)\nPapel embrulha Pedra!")
    else:
        if resp_com == 2:
            print("Vitória!:)\nTesoura corta Papel!")
        else:
            print("Derrota! Pedra quebra Tesousa!")
            