/*Universidade de Brasília (UnB)
  Disciplina: Estrutura de Dados - Turma D 
  Professor: Eduardo Adilio Pelinson Alchieri
  Estudantes: Andressa Maria Monteiro Sena - 16/0112303
              Marcus Fernando F. S. Lima - 16/0135958 */

/*Trabalho 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*          ARVORE BINÁRIA         */

/*Define como os nós da àrvore serão.*/
struct no{

	char letra;
	struct no * esquerda;
	struct no * direita;

};

typedef struct no no_arvore;

/*Cria o nó inicial da árvore.*/
no_arvore * cria_arvore(){

	no_arvore * l = (no_arvore *)malloc(sizeof(no_arvore));
	l->esquerda = NULL;
	l->direita = NULL;
	l->letra = 'r';
	return l;

}

/*Função que cria um nó.*/
no_arvore * cria_no(char dado){

	no_arvore * n = (no_arvore *)malloc(sizeof(no_arvore));
	n->esquerda = NULL;
	n->direita = NULL;
	n->letra = dado;
	
	return n;

}

/*Função que insere um nó na àrvore.*/
void insere_no(no_arvore ** raiz,char* informacao,char letra){

	no_arvore * aux;
	aux = *raiz;

	if(aux == NULL){
		aux = cria_no(' ');
	}
	if(*informacao == '.'){
		insere_no(&(aux->esquerda),informacao+1,letra);
	}
	if(*informacao == '-'){
		insere_no(&(aux->direita),informacao+1,letra);
	}
	if(*informacao == '\0'){
		aux->letra = letra;
	}
	*(raiz) = aux;

}

/*Função que decodifica usando as informações da árvore.*/
void decodifica_arvore(no_arvore * no,char* s_codigo){

	if(no == NULL){
		printf("Arvore nula.\n");
	}
	if(*s_codigo == '.'){
		decodifica_arvore(no->esquerda,s_codigo+1);
	}
	if(*s_codigo == '-'){
		decodifica_arvore(no->direita,s_codigo+1);
	}
	if(*s_codigo == '/'){
		printf(" ");
	}
	if(*s_codigo == '\0'){
		printf("%c",no->letra);
	}

}

/*          LISTA ENCADEADA          */

/*Registro que representa como será cada elemento da lista.*/
struct celula{

	char letra;
	char codigo[10];
	struct celula *proximo;

};

typedef struct celula elemento;

/*Registro que modela a lista.*/
typedef struct t_lista{

	elemento * inicio;
	elemento * fim;

}lista;

/*Essa função cria uma nova lista.*/
lista * cria_lista(){

	lista* l = (lista*)malloc(sizeof(lista));
	l->inicio = NULL;
	l->fim = NULL;

	return l;
}

/*Insere o código das letras na lista.*/
void insere_inicio(char Letra, char dado[], lista * a_lista){

	elemento * novo_elemento;
	novo_elemento = (elemento*) malloc(sizeof(elemento));
	novo_elemento->letra = Letra;
	strcpy(novo_elemento->codigo,dado); 
	novo_elemento->proximo = a_lista->inicio;
	a_lista->inicio = novo_elemento;
	if(a_lista->fim == NULL){
		a_lista->fim = novo_elemento;
	}

}

/*Função que mostrará as palavras da mensagem.*/
void decodifica(char codigos[], lista * l){

	int x;
	elemento * atual = l->inicio;
	while(atual != NULL){
		x = strcmp(codigos,atual->codigo);
		if(x==0){
			printf("%c",atual->letra);
			break;
		}
		atual = atual->proximo;
	}
}

/*Função principal.*/
int main(){

	/*Variáveis da ÁRVORE*/
	no_arvore * arvore = cria_arvore();
	char a_letra,item;
	char palavras[20],codigo[10];
	int j=0;

	/*Variáveis da LISTA*/
	lista *b_lista = cria_lista();
	char letra,caracter;
	char palavra[20],a_codigo[10];
	int i=0;

	/*Variáveis da ÁRVORE e da LISTA*/
	char arquivo1[10] = "texto.txt";
	char arquivo2[15] = "mensagem.txt";
	clock_t t_inicial,t_final;
	double tempo;


	/*          ARVORE BINÁRIA         */

	t_inicial = clock();
	printf("Arvore:\n");
	FILE *fp3 = fopen(arquivo1,"r");

	if(fp3 == NULL){
		printf("Não foi possível abrir %s.\n",arquivo1);
	}
	else{
		while(!feof(fp3)){
			a_letra = fgetc(fp3);
			fscanf(fp3," %s\n",codigo);
			insere_no(&arvore,codigo,a_letra);
		}
	}
	
	FILE *fp4 = fopen(arquivo2,"r");

	if(fp4 == NULL){
		printf("Não foi possível acessar %s.\n",arquivo2);
	}
	else{
		while(!feof(fp4)){
			item = fgetc(fp4);
			if(item != ' '){
				palavras[j] = item;
				j++;
			}
			else{
				palavras[j] = '\0';
				j=0;
				decodifica_arvore(arvore,palavras);
			}
		}
	}
	t_final = clock();
	tempo = (double)(t_final-t_inicial)*1000.0/CLOCKS_PER_SEC;

	/*Linha puramente estética. Finaliza a mensagem com um ponto.*/
	printf(".\n");
	printf("Tempo de execuçao: %lf s.\n",tempo);
	printf("\n");

	fclose(fp3);
	fclose(fp4);


	/*          LISTA ENCADEADA          */

	t_inicial = clock();
	printf("Lista:\n");
	FILE *fp = fopen(arquivo1,"r");

	if(fp == NULL){
		printf("Não foi possivel abrir %s.\n",arquivo1);
	}
	else{
		while(!feof(fp)){
			letra = fgetc(fp);
			fscanf(fp," %s\n",a_codigo);
			insere_inicio(letra,a_codigo,b_lista);
		}
	}
	
	FILE *fp2 = fopen(arquivo2,"r");

	if(fp2 == NULL){
		printf("Não foi possivel abrir %s.\n",arquivo2);
	}
	else{
		while(!feof(fp2)){
			caracter = fgetc(fp2);
			if((caracter!='/')&&(caracter!=' ')){
				palavra[i] = caracter;
				i++;
			}
			else{
				palavra[i] = '\0';
				i=0;
				decodifica(palavra,b_lista);
				if(caracter == '/'){
					printf(" ");
				}
			}
		}
	}
	t_final = clock();
	tempo = (double)(t_final-t_inicial)*1000.0/CLOCKS_PER_SEC;

	/*Linha puramente estética. Finaliza a mensagem com um ponto.*/
	printf(".\n");
	printf("Tempo de execuçao: %lf s.\n",tempo);
	printf("\n");

	fclose(fp);
	fclose(fp2);

	return 0;
}