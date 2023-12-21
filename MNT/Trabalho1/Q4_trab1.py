#Trabalho 1 - Exercício 4

nome = input("Qual seu nome?")
idade = input("Qual sua idade?")

#print(nome, idade)

#Escreve os dados no arquivo.
arquivo = open("Exercicio4.txt","a")
arquivo.write(nome)
arquivo.write(" ")
arquivo.write(idade)
arquivo.write("\n")


#Lê do arquivo e imprime na tela.
print("\n")
arquivo = open("Exercicio4.txt","r")
for linha in arquivo:
    print(linha)

arquivo.close()

#Coloquei um loop de leitura dos arquivos pois com algumas modificações
#é possível separar os dados Nome e Idade por manipulação dos dados. 