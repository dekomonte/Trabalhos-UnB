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
int m;
char palavras[50][50];
int indice;
int pontos[50];
char palavra_decifrada[21];
char alfabeto[27];
int pontos_total;
char forca[23][31];
int erros;

void draw(){
    
    memcpy(forca,"                              \n                              \n    +-----------------+       \n    |                 |       \n    |                 |       \n    |                 +       \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n    |                         \n   +++                        \n  +++++                       \n +++++++                      \n                              \n",651);
    return;
}

void parte_do_corpo(){

    /*Essa funcao mostra as partes do corpo do boneco que faltam (ou o numero de erros) na tela.*/
    int i,j;
    if(erros==1){
        forca[6][21]='_';
        forca[6][22]='_';
        forca[6][23]='_';
        forca[7][20]='/';
        forca[7][24]='\\';
        forca[8][24]='/';
        forca[8][20]='\\';
        forca[8][21]='_';
        forca[8][23]='_';
    }
    else if(erros==2){
        forca[9][22]='|';
        forca[10][22]='+';
        forca[10][23]='-';
        forca[10][21]='-';
        forca[11][22]='|';
        forca[12][22]='|';
        forca[13][22]='|';
    }
    else if(erros==3){
        forca[11][24]='\\';
        forca[12][25]='\\';
        forca[13][26]='\\';
    }
    else if(erros==4){
        forca[11][20]='/';
        forca[12][19]='/';
        forca[13][18]='/';
    }
    else if(erros==5){
        forca[14][23]='\\';
        forca[15][24]='\\';
        forca[16][25]='\\';
        forca[17][26]='\\';
    }
    else if(erros==6){
        forca[14][21]='/';
        forca[15][20]='/';
        forca[16][19]='/';
        forca[17][18]='/';
    }
    else if(erros==7){
        forca[5][21]='_';
        forca[5][20]='_';
        forca[6][19]='/';
        forca[7][18]='/';
        forca[8][18]='\\';
        forca[9][19]='-';
        forca[9][20]='-';
        forca[9][21]='-';
        forca[9][23]='-';
        forca[9][24]='-';
        forca[9][25]='-';
    }
    for (i=0;i<23;i++){
        for(j=0;j<30;j++){
            printf("%c",forca[i][j]);
        }
        printf("\n");
    }

    return;
}

void interface(int tam){

    /*Essa funcao eh responsavel pela interacao do usuario com a tela.*/

    int i;

    printf("#################\n");
    printf("# JOGO DA FORCA #\n");
    printf("#################\n");
    printf("\n\n");
    printf("Pontuacao acumulada: %d\n",pontos_total);
    printf("Pontuacao a receber por essa palavra: %d\n",pontos[indice]);
    printf("\n");

    parte_do_corpo();
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

int compara_decifrada(char alvo[],int tam){

    /*Essa funcao eh responsavel por indicar se a palavra alvo ja foi identificada.*/
    /*Ela retorna o quanto que a palavra decifrada ja foi preenchida com letras.*/
    /*Se o contador for igual ao numero de letras da alvo, um dos loops da main eh parado.*/

    int i,contador=0;

    for(i=0;i<tam;i++){
        if(palavra_decifrada[i]==alvo[i]){
            contador++;
        }
    }

    return contador;
}

void zera_tudo(int tam){

    /*Essa funcao preenche o alfabeto com as 26 letras.*/
    /*Além disso, preenche com os 'underscores' a string palavra_decifrada de acordo com o tamanho da palavra lida no arquivo.*/

    int i,j;
    draw();
    for(i=0;i<26;i++){
        alfabeto[i]=i + 'A';
    }
    alfabeto[i]='\0';

    for(j=0;j<tam;j++){
        palavra_decifrada[j]='_';
    }
    palavra_decifrada[j]='\0';

    return;
}

int decifradora(char alvo[],int tam,char letra){

    /*Essa funcao compara e preenche a palavra decifrada com a letra caso ela esteja na alvo.*/
    /*O contador eh usado para saber se o programa entrou ou nao no 'if'.*/
    /*Se o contador nao incrementa, a main interpreta a informacao como um erro. */

    int k,contador;

    contador=0;
    for(k=0;k<tam;k++){
        if(alvo[k]==letra){
            contador++;
            palavra_decifrada[k]=letra;
        }
    }
    palavra_decifrada[k]='\0';
    printf("\n");

    return contador;
}

int compacta_alfabeto(char letra){

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

    char letra,decisao,palavra_alvo[21];
    int tam,continua,perdeu,retorno_compara=0,x;  /*Declaracao de variaveis.*/
    FILE *fp;

    fp=fopen("palavras.txt","r");
    if(fp == NULL){
        printf("Arquivo nulo!"); /*Esse trecho testa se o arquivo existe. Sugestao de um monitor.*/
        return 1;
    }
    continua=0;
    perdeu=0;
    pontos_total=0;
    indice=0;
    while(!feof(fp)){
            fscanf(fp,"%s",&palavras[m][0]);
            fscanf(fp,"%d",&pontos[m]);
            m++;
        }
    while((perdeu==0) && (continua==0)){
        memcpy(palavra_alvo,palavras[indice],50);
        tam = strlen(palavra_alvo);
        zera_tudo(tam); /*Parte que "reinicia" o jogo apos cada letura de palavra.*/
        erros=0;
        retorno_compara=0;
        while((erros<6) && (retorno_compara<tam)){
            interface(tam);
            scanf("%c",&letra);
            getchar();
            while(compacta_alfabeto(letra)==0){  /*Teste que verifica se a letra esta fora do alfabeto ou ja foi usada.*/
                printf("Digite outra letra:\n");
                scanf("%c",&letra);
                getchar();
            }
            compacta_alfabeto(letra);
            x = decifradora(palavra_alvo,tam,letra);
            if(x==0){
                erros++;
                pontos[indice]-=5;
                printf("Letra incorreta. Voce ainda tem %d chances.\n",6-erros);
                printf("Tecle enter para continuar.\n");
                getchar();
            }
            compacta_alfabeto(letra);
            retorno_compara=compara_decifrada(palavra_alvo,tam);
            system CLEAR;
        }
        if(erros==6){
            pontos_total+=pontos[indice];
            perdeu = 1;
            printf("Voce perdeu!\n");
            printf("Total de pontos: %d\n",pontos_total); /*Indica que o usuario erdeu.*/
            getchar();
        }
        else{
            pontos_total+=pontos[indice];
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
        indice++;
    }
    fclose(fp);

    return 0;
}
