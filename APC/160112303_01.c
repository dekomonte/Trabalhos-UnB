/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao

    Algoritmos e Programacao de Computadores

    Aluno(a): Andressa Maria Monteiro Sena
    Matricula: 16/0112303
    Turma: VERAO
    Versao do Compilador: gcc version 4.9.2 (tdm-1)

    Descricao: Jogo da forca em C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
#define CLEAR ("cls")
#else
#define CLEAR ("clear")
#endif

void parte_do_corpo(int erros){

    /*Essa funcao mostra as partes do corpo do boneco que faltam (ou o numero de erros) na tela.*/

    printf("1-cabeca, ");
    printf("2-tronco, ");
    printf("3-braco direito, ");
    printf("4-braco esquerdo, ");
    printf("5-perna direita, ");
    printf("6-perna esquerda, \n");
    if(erros==1){
        printf("1 \n");
    }
    else if(erros==2){
        printf("1 2 \n");
    }
    else if(erros==3){
        printf("1 2 3 \n");
    }
    else if(erros==4){
        printf("1 2 3 4 \n");
    }
    else if(erros==5){
        printf("1 2 3 4 5 \n");
    }
    else if(erros==6){
        printf("1 2 3 4 5 6 \n");
    }

    return;
}

void interface(int pontos_total,int pontos,char palavra_decifrada[],int tam,char alfabeto[],int erros){

    /*Essa funcao eh responsavel pela interacao do usuario com a tela.*/

    int i;

    printf("#################\n");
    printf("# JOGO DA FORCA #\n");
    printf("#################\n");
    printf("\n\n");
    printf("Pontuacao acumulada: %d\n",pontos_total);
    printf("Pontuacao a receber por essa palavra: %d\n",pontos);
    printf("\n");

    parte_do_corpo(erros);
    printf("\n\n");

    for(i=0;i<tam;i++){
        printf("%c ",palavra_decifrada[i]);
    }
    palavra_decifrada[i]='\0';

    printf("\n\n");
    printf("%s\n",alfabeto);
    printf("\n");
    printf("Digite uma letra: \n");

    return;
}

int compara_decifrada(char alvo[],char decifra[],int tam){

    /*Essa funcao eh responsavel por indicar se a palavra alvo ja foi identificada.*/
    /*Ela retorna o quanto que a palavra decifrada ja foi preenchida com letras.*/
    /*Se o contador for igual ao numero de letras da alvo, um dos loops da main eh parado.*/

    int i,contador=0;

    for(i=0;i<tam;i++){
        if(decifra[i]==alvo[i]){
            contador++;
        }
    }

    return contador;
}

void zera_tudo(char alfabeto[],char decifra[],int tam){

    /*Essa funcao preenche o alfabeto com as 26 letras.*/
    /*Além disso, preenche com os 'underscores' a string palavra_decifrada de acordo com o tamanho da palavra lida no arquivo.*/

    int i,j;

    for(i=0;i<26;i++){
        alfabeto[i]=i + 'A';
    }
    alfabeto[i]='\0';

    for(j=0;j<tam;j++){
        decifra[j]='_';
    }
    decifra[j]='\0';

    return;
}

int decifradora(char decifra[],char alvo[],int tam,char letra){

    /*Essa funcao compara e preenche a palavra decifrada com a letra caso ela esteja na alvo.*/
    /*O contador eh usado para saber se o programa entrou ou nao no 'if'.*/
    /*Se o contador nao incrementa, a main interpreta a informacao como um erro. */

    int k,contador;

    contador=0;
    for(k=0;k<tam;k++){
        if(alvo[k]==letra){
            contador++;
            decifra[k]=letra;
        }
        /*printf("%c ",decifra[k]);*/
    }
    decifra[k]='\0';
    printf("\n");

    return contador;
}

int compacta_alfabeto(char alfabeto[],char letra){

    /*Essa funcao compacta o vetor alfabeto.*/

    int i,j=0,tamanho,contador=0;

    tamanho=strlen(alfabeto);
    for(i=0;i<tamanho;i++){
        if(alfabeto[i]!=letra){
            alfabeto[j]=alfabeto[i];
            j++;
        }
        else{
            contador++;
        }

    }
    alfabeto[j]='\0';


    return contador;
}

int main(){

    char alfabeto[27],palavra_alvo[21],palavra_decifrada[21],letra,decisao;
    int pontos,pontos_total=0,tam,continua,perdeu,erros=0,retorno_compara=0,x;  /*Declaracao de variaveis.*/
    FILE *fp;

    fp=fopen("palavras.txt","r");
    if(fp == NULL){
        printf("Arquivo nulo!"); /*Esse trecho testa se o arquivo existe. Sugestao de um monitor.*/
        return 1;
    }
    continua=0;
    perdeu=0;
    while((fscanf(fp,"%s",palavra_alvo) > 0) && (perdeu==0) && (continua==0)){
        fscanf(fp,"%d\n",&pontos);
        tam = strlen(palavra_alvo);
        zera_tudo(alfabeto,palavra_decifrada,tam); /*Parte que "reinicia" o jogo apos cada letura de palavra.*/
        erros=0;
        retorno_compara=0;
        while((erros<6) && (retorno_compara<tam)){
            interface(pontos_total,pontos,palavra_decifrada,tam,alfabeto,erros);
            scanf("%c",&letra);
            getchar();
            while(compacta_alfabeto(alfabeto,letra)==0){  /*Teste que verifica se a letra esta fora do alfabeto ou ja foi usada.*/
                printf("Digite outra letra:\n");
                scanf("%c",&letra);
                getchar();
            }
            compacta_alfabeto(alfabeto,letra);
            x = decifradora(palavra_decifrada,palavra_alvo,tam,letra);
            if(x==0){
                erros++;
                pontos-=5;
                printf("Letra incorreta. Voce ainda tem %d chances.\n",6-erros);
                printf("Tecle enter para continuar.\n");
                getchar();
            }
            compacta_alfabeto(alfabeto,letra);
            retorno_compara=compara_decifrada(palavra_alvo,palavra_decifrada,tam);
            system CLEAR;
        }
        if(erros==6){
            pontos_total+=pontos;
            perdeu = 1;
            printf("Voce perdeu!\n");
            printf("Total de pontos: %d\n",pontos_total); /*Indica que o usuario erdeu.*/
            getchar();
        }
        else{
            pontos_total+=pontos;
            printf("Voce tem %d pontos.\n",pontos_total);
            printf("Deseja continuar jogando?\n");
            scanf("%c",&decisao);
            getchar();
            while((decisao!='S')&&(decisao !='s')&&(decisao!='n')&&(decisao!='N')){ /*Verifica se a pessoa deseja continuar.*/
                printf("ERRO! Digite uma opcao valida: \n");
                scanf("%c",&decisao);
                getchar();
            }
            if((decisao=='N')||(decisao=='n')){
                continua=1;
                printf("Total de pontos: %d\n",pontos_total);
                getchar();
            }
            system CLEAR;
        }
    }
    fclose(fp);

    return 0;
}
