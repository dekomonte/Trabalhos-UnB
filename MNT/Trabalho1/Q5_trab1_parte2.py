# -*- coding: utf-8 -*-
"""
Created on Wed Aug 11 15:44:43 2021

@author: dekom
"""

#Trabalho 1 - Questão 5_Parte 2

import random

#Versão com mais chance de vitória do Computador. Trapaça. 
print("Você tem 3 opções:")
print("1-Pedra\n2-Papel\n3-Tesoura")
resp_usuario=int(input("Escolha um número:"))
print("\n")

resp_com=random.randint(1,3)
#print(resp_usuario)
#print(resp_com)

if resp_usuario == 1:
    print("Você escolheu Pedra.")
    while resp_com == 3:
        resp_com=random.randint(1,3)
        
elif resp_usuario == 2:
    print("Você escolheu Papel.")
    while resp_com == 1:
         resp_com=random.randint(1,3)
else:
    print("Você escolheu Tesoura.")
    while resp_com == 2:
         resp_com=random.randint(1,3)
    

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
            