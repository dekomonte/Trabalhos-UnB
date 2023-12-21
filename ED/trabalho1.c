/*Universidade de Brasília
  Disciplina: Estrutura de Dados - Turma D 
  Professor: Eduardo Adilio Pelinson Alchieri
  Estudantes: Andressa Maria Monteiro Sena - 16/0112303
              Marcus Fernando F. S. Lima - 16/0135958 */
                
/*Trabalho 1: Avaliação de Expressões Aritméticas*/
/*Obs1: Ao longo do código como retorno de funções 1 representa VERDADEIRO e 0 representa FALSO. 
  Obs2: Cada função apresenta uma simples descrição com o intuito de facilitar sua interpretação.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Definindo "variáveis compostas" que modelam as pilhas.*/
typedef struct{

	int indice;
	char vetor[100];

}pilha;

typedef struct{

	int indice_inteiros;
	int vetor_inteios[100];

}pilha_inteiro;

/*Funções que "criam" as pilhas. Elas inicializam o índice de cada pilha.*/
pilha nova_pilha(){

	pilha nova_pilha;
	nova_pilha.indice=0;
	return nova_pilha;

}

pilha_inteiro nova_pilha_inteiros(){

	pilha_inteiro nova_pilha_inteiros;
	nova_pilha_inteiros.indice_inteiros=0;
	return nova_pilha_inteiros;

}

/*Essa função verifica se a pilha de caracteres está vazia.*/
int esta_vazia(pilha nova_pilha){

	if(nova_pilha.indice == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*A ideia dessas funções é colocar um elemento no topo pilha. Uma para cada tipo de pilha.*/
void empilha(pilha *nova_pilha, char c){

	nova_pilha->indice++;
	nova_pilha->vetor[nova_pilha->indice] = c;

}

void empilha_inteiros(pilha_inteiro *e_pilha , int valor){

	e_pilha->indice_inteiros++;
	e_pilha->vetor_inteios[e_pilha->indice_inteiros] = valor;

}

/*Desempilha o topo da pilha. Novamente uma função para cada tipo de pilha.*/
char desempilha(pilha *nova_pilha){

	nova_pilha->indice--;
	return nova_pilha->vetor[nova_pilha->indice+1];

}

int desempilha_inteiros(pilha_inteiro *d_pilha){

	d_pilha->indice_inteiros--;
	return d_pilha->vetor_inteios[d_pilha->indice_inteiros+1];
}

/*Validação de parênteses.*/
int validacao(char elemento[]){

	pilha c_pilha = nova_pilha();
	int i=0,validacao=1;
	while(elemento[i] != '\0'){
		if(elemento[i] == '('){
			empilha(&c_pilha,elemento[i]);
		}
		if(elemento[i] == ')'){
			if(esta_vazia(c_pilha) == 1){
				validacao = 0;
			}
			else{
				desempilha(&c_pilha);
			}
		}
	i++;
	}
	if(esta_vazia(c_pilha)!=1){
		validacao=0;
	}

	return validacao;

}

/*Função que coloca os elementos na forma posfixa.*/
pilha posfixa(char elemento[]){

	int i=0;
	char aux;
	pilha operandos = nova_pilha();
	pilha b_pilha = nova_pilha();
	while(elemento[i] != '\0'){
		if((elemento[i] == '*') || (elemento[i] == '/') || (elemento[i] == '+') || (elemento[i] == '-')){
			while((esta_vazia(b_pilha)!=1) && (b_pilha.vetor[b_pilha.indice] != '(') && (b_pilha.vetor[b_pilha.indice] == '*' || b_pilha.vetor[b_pilha.indice] == '/' || elemento[i] == '+' || elemento[i] == '-')){
				empilha(&operandos, desempilha(&b_pilha));
			}
			empilha(&operandos,' ');
			empilha(&b_pilha,elemento[i]);
		}
		else if(elemento[i] == '('){
			empilha(&b_pilha,elemento[i]);
		}
		else if(elemento[i] == ')'){
			aux = desempilha(&b_pilha);
			while(aux != '('){
				empilha(&operandos, aux);
				aux = desempilha(&b_pilha);
			}
		}
		else{
			empilha(&operandos, elemento[i]);
		}

	i++;
	}
	while(esta_vazia(b_pilha) != 1){
		empilha(&operandos, desempilha(&b_pilha));
	}
	empilha(&operandos,'\0');
	return operandos;

}

/*Verifica se o caracter é operador.*/
int eh_operador(char c){

	if ((c == '/')||(c == '+')||(c == '-') || (c == '*')){
		return 1;
	}
	else {
		return 0;
	}

}

/*Devolve o valor da operação.*/
int operacao(char r , int x , int y){

	int resultado;

	if(r == '*'){
		resultado = x * y;
	}
	else if(r == '/'){
		resultado = x / y;
	}
	else if(r == '+'){
		resultado = x + y;
	}
	else if(r == '-'){
		resultado = x - y;
	}
	return resultado;

}

/*Função que devolve o valor da conta.*/
int calcula(pilha saida){

	pilha_inteiro d_pilha = nova_pilha_inteiros();
	int num1,num2,i=0,y,j;
	char numero[10];

	for(j=1;j<=saida.indice;j++){
		if((eh_operador(saida.vetor[j]) == 0) && (saida.vetor[j] != ' ') && (j<=saida.indice)) {
			numero[i] = saida.vetor[j];
			i++;
		}
		else{
			if((saida.vetor[j] == ' ') || (eh_operador(saida.vetor[j]) == 1)) {
				numero[i] = '\0';
				y = atoi(numero);
				if(((y!= 0) && (strlen(numero)!=0)) || ((y == 0) && (strlen(numero)!= 0))){
					empilha_inteiros(&d_pilha,y);
				}	
				i=0;
				if(eh_operador(saida.vetor[j]) == 1){
					num1 = desempilha_inteiros(&d_pilha);
					num2 = desempilha_inteiros(&d_pilha);
					empilha_inteiros(&d_pilha,operacao(saida.vetor[j],num2,num1));
				}
			}	
		}
		
	}
	return desempilha_inteiros(&d_pilha);
 }

/*Função principal.*/
int main()
{

	/*Declaração de variáveis.*/
	pilha a_pilha;
	char elemento[100];
	int valido,x=0;

	/*Lê e guarda os dados digitados.*/
	printf("Digite a expressão:\n");
	printf("\n");
	scanf("%s",elemento);

	/*Verifica se os parênteses estão válidos.*/
	printf("\n");
	valido = validacao(elemento);

	/*Coloca os elementos na forma posfixa.*/
	a_pilha = posfixa(elemento);
	a_pilha.vetor[0]=' ';

	/*Calcula o valor das operações.*/
	x = calcula(a_pilha);

	if(valido==1){
		printf(" Valida\n");
		printf("%s\n",a_pilha.vetor);
		printf(" %d\n",x);	
		printf("\n");

	}
	else{
		printf(" Nao valida\n");
		printf("\n");
	}

	return 0;
}