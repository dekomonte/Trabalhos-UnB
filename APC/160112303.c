/*        @file: Trabalho 3
 *  @disciplina: Algoritmos e Programa��o de Computadores
 *      @author: Andressa Maria Monteiro Sena
 *   @matr�cula: 16/0112303  */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef _WIN32
#define CLEAR ("cls")
#else
#define CLEAR ("clear")
#endif

typedef struct{
  char nome[50];
  int psenha,pcharada,pppt,pcampo,proda;
}ranking;

void spread(int matriz[][6],int mascara[][6],int x,int y)
{
    int i,j;
    mascara[x][y]=1;
    for(i=x-1;i<=x+1;i++)
    {
        for(j=y-1;j<=y+1;j++)
        {
            if(j>=0&&i>=0&&j<=5&&i<=5)
            {
                if(matriz[i][j]==0&&mascara[i][j]==0)
                {
                    spread(matriz,mascara,i,j);
                }
                else
                {
                    mascara[i][j]=1;
                }
            }
        }
    }
}


void senha(){

int senha,tentativa,contador;
    printf("\n");
    printf("#########\n");
    printf("# Senha #\n");
    printf("#########\n");
    printf("Voc� se juntou a um grupo de assaltantes para furtar barras de ouro de um velho bilion�rio do Lago Sul.\n");
    printf("Seu trabalho � o �mais simples�: descobrir qual a senha do cofre que guarda todas as riquezas do velhinho.\n");
    printf("Voc� tem �infinitas chances�, s� n�o pode colocar n�meros fora do intervalo [0-100000], caso contr�rio, o alarme � acionado e a pol�cia aparece magicamente.\n");
    printf("\n");
    srand(time(NULL));
    senha = rand() %100001;
    contador=0;
     while(senha != tentativa){
        contador=contador+1;
        printf("Chuta a� a senha,trouxa!");
        scanf("%d",&tentativa);
	if(tentativa<0){
	 printf("Se ferrou ot�rio! A senha era %d!\n",senha);
	 printf("I� I� I� I� (Sim, isso era para ser a sirene do carro da pol�cia)\n");
	 contador=contador+99;
	 printf("A sua pontua��o foi %d\n",10000/contador);
	 getchar();
         getchar();
         return;
	}
       if(senha<tentativa){
        printf("� menor que %d,cara!\n",tentativa);
       }
       if(senha>tentativa){
        printf("� maior que %d,cara!\n",tentativa);
       }
      }
     if(senha==tentativa){
        printf("Acertou!Conseguiu em apenas %d tentativas!\n",contador);

    }
    printf("A sua pontua��o foi %d\n",10000/contador);
  getchar();
  getchar();
  return;
}

void charada() {

    int opcao1,opcao2,opcao3,pontos;

    printf("\n");
    printf("###########\n");
    printf("# Charada #\n");
    printf("###########\n");
    printf("Um assassino tinha um cachorro. Um dia seu cachorro morreu,qual o nome do filme?\n");
    printf("1)Como c�es e gatos\n");
    printf("2)C�es assassinos\n");
    printf("3)Mato sem cachorro\n");
    printf("4)Sete psicop�tas e um shih tzu\n");
    printf("\n");

    scanf("%d",&opcao1);
     while(opcao1 != 1 && opcao1 != 2 && opcao1 !=3 && opcao1 !=4){
       printf("Essa op��o n�o � v�lida\n");
       printf("Digite sua op��o:\n");
       scanf("%d",&opcao1);
    }
       if(opcao1 != 3){
        printf("Acho que n�o!\n");
        scanf("%d",&opcao2);
	 while(opcao2 != 1 && opcao2 != 2 && opcao2 !=3 && opcao2 !=4){
            printf("Essa op��o n�o � v�lida\n");
            printf("Digite sua op��o:\n");
            scanf("%d",&opcao2);
         }
         if(opcao2 != 3){
            printf("Tente outra vez!\n");
             scanf("%d",&opcao3);
	      while(opcao3 != 1 && opcao3 != 2 && opcao3 !=3 && opcao3 !=4){
                printf("Essa op��o n�o � v�lida\n");
                printf("Digite sua op��o:\n");
                scanf("%d",&opcao3);
              }
              if(opcao3 != 3){
                printf("Perdeu ot�rio!\n");
                pontos=0;
              } else{
                  printf("At� que enfim!\n");
                  pontos=10;
                }
         } else{
             printf("De segunda mas foi!\n");
             pontos=50;
           }
    } else{
        printf("Parab�ns!Mandou bem!\n");
        pontos=100;
      }
      printf("A sua pontua��o � %d\n",pontos);
     getchar();
     getchar();
     return;
}

void ppt() {

    printf("\n");
    printf("#######################\n");
    printf("# Pedra-Papel-Tesoura #\n");
    printf("#######################\n");
    printf("Ap�s o sucesso no assalto (�Senha�), o grupo de assaltantes precisa dividir �justamente� o ouro.\n");
    printf("O l�der do grupo, sugeriu que eles jogassem Pedra-Papel-Tesoura para determinar a partilha.\n");
    printf("O vencedor ficaria com a maior parte dos lucros.\n");
    printf("\n");
    printf("p) Pedra\n");
    printf("P) Papel\n");
    printf("T) Tesoura\n");
    printf("\n");
    int escolha=0;
    char a,b,c;
        while(escolha == 0){
        printf("Assaltante 1, qual a sua escolha?\n");
        scanf(" %c",&a);
	 while(a != 'p' && a != 'P' && a !='T'){
           printf("Essa op��o n�o � v�lida\n");
           printf("Digite sua op��o:\n");
           scanf(" %c",&a);
         }
        printf("Assaltante 2, qual a sua escolha?\n");
        scanf(" %c",&b);
	 while(b != 'p' && b != 'P' && b !='T' ){
           printf("Essa op��o n�o � v�lida\n");
           printf("Digite sua op��o:\n");
           scanf(" %c",&b);
         }
        printf("Assaltante 3, qual a sua escolha?\n");
        scanf(" %c",&c);
	 while(c != 'p' && c != 'P' && c !='T'){
           printf("Essa op��o n�o � v�lida\n");
           printf("Digite sua op��o:\n");
           scanf(" %c",&c);
         }
         if(a=='p'&&b=='T'&&c == 'T'){
            printf("Parab�ns Assaltante 1!\n");
            escolha = 1;
         }
         if(a=='T'&&b=='p'&&c=='T'){
            printf("Parab�ns Assaltante 2!\n");
            escolha = 1;
         }
         if(a=='T'&&b=='T'&&c=='p'){
            printf("Parab�ns Assaltante 3!\n");
            escolha = 1;
         }
         if(a=='T'&&b=='P'&&c=='P'){
            printf("Parab�ns Assaltante 1!\n");
            escolha = 1;
         }
         if(a=='P'&&b=='T'&&c =='P'){
            printf("Parab�ns Assaltante 2!\n");
            escolha = 1;
         }
         if(a=='P'&&b=='P'&&c=='T'){
            printf("Parab�ns Assaltante 3!\n");
            escolha = 1;
         }
         if(a=='P'&&b=='p'&&c=='p'){
            printf("Parab�ns Assaltante 1!\n");
            escolha = 1;
         }
         if(a=='p'&&b=='P'&&c=='p'){
            printf("Parab�ns Assaltante 2!\n");
            escolha = 1;
         }
         if(a=='p'&&b=='p'&&c=='P'){
            printf("Parab�ns Assaltante 3!\n");
            escolha = 1;
         }
        }
        getchar();
	getchar();
        return;
}
void campo_minado()
{
    int x,y,i,j,l,condicional=0,ponto;
    int matriz[6][6],matrizx[6][6];

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            matriz[i][j]=0;
            }
    }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            matrizx[i][j]=0;
            }
    }

    srand(time(NULL));
    for(l=0;l<8;l++){
        x=rand()%6;
        y=rand()%6;
        if(matriz[x][y]==9){
            l--;
        }
        else{
            matriz[x][y]=9; /*Bomba*/
            for(i=x-1;i<=x+1;i++){
                for(j=y-1;j<=y+1;j++){
                    if(i>=0 && i<=5 && j>=0 &&j<=5 && matriz[i][j]!=9){
                        matriz[i][j]++;
                    }
                }
            }
        }
    }

    while(condicional == 0){
        system CLEAR;
        printf("################\n");
        printf("# Campo Minado #\n");
        printf("################\n");
        printf("Para fungir menos da tem�tica do conjunto de jogos,novamente voc� tem que fugir de um crime.\n");
        printf("Agora, o dono do cofre tem um sistema de alarmes mais eficiente no quintal.\n");
        printf("Sua propriedade � dividida em 36 regi�es(6x6) e contem 12 posi��es de risco(bombas).Pisando em qualquer uma delas,os 'tiras' chegam automaticamente.\n ");
        printf("Voc� consegue sair dessa?\n");
        printf("\n");

      for(i=0;i<6;i++){
            for (j=0;j<6;j++){
                if (matrizx[i][j]==0){
                    printf(" # ");
                }
                else{
                    if (matriz[i][j]==9){
                        printf(" X ");
                    }
                    else{
                        printf(" %d ",matriz[i][j]);
                    }
                }
            }
            printf("\n");
        }

        printf("\n");
        printf("Qual a coordenada de x(linha)?\n");
        scanf("%d",&x);
        x--;
        while(x<0 || x>5){
            printf("Essa coordenada n�o � v�lida\n");
            printf("Qual a coordenada de x(linha)?\n");
            scanf("%d",&x);
            x--;
        }

        printf("\n");
        printf("Qual a coordenada de y(coluna)?\n");
        scanf("%d",&y);
        y--;
        while(y<0 || y>5){
            printf("Essa coordenada n�o � v�lida\n");
            printf("Qual a coordenada de y(coluna)?\n");
            scanf("%d",&y);
            y--;
        }


        if(matriz[x][y]!=9 && matriz[x][y]!=0){
            matrizx[x][y]=1;
        }
        else if(matriz[x][y]==0){
            spread(matriz,matrizx,x,y);
        }

        else{

            condicional=1;
        }
        if(condicional!=1){
            condicional=2;
        }
        for(x=0;x<6;x++){
            for(y=0;y<6;y++){
                if(matriz[x][y]!=9&&matrizx[x][y]==0&&condicional!=1){
                    condicional=0;
                }
            }
        }

}


if(condicional==1){
    printf("Voc� Perdeu!\n");
            printf("Chama os tiras!Se ferrou ot�rio!\n");
            ponto=0;
            printf("A sua pontua��o foi %d\n",ponto);
}
if(condicional==2){
 printf("Parab�ns,voc� conseguiu n�o ser pego!\n");
 ponto=100;
 printf("A sua pontua��o foi %d\n",ponto);
 }

    printf("\n");
    getchar();
    getchar();

    return;
}

void roda_a_roda(){}

int main(){

  char escolha=0;
  char opcao=0;
  ranking jogador;
  while(1){
  system CLEAR;
  printf("Ol� querido jogador!\n");
  printf("Pronto para entrar no conjuntos de jogos com a tem�tica e com os contextos mais toscos da turma C de APC de 2/2016?\n");
  printf("Para continuar, registre seu nome do crime:\n");
  scanf("%[^\n]",jogador.nome);
  system CLEAR;
  printf("Fa�a sua escolha:\n");
  printf("      1) Jogos\n");
  printf("      2) Ranking\n");
  printf("      3)Canfigura��es\n");
  printf("\n");
  scanf(" %c",&escolha);
  if(escolha =='1'){
  system CLEAR;
  printf("\n");
  printf("################\n");
  printf("# GTA Bras�lia #\n");
  printf("################\n");
  printf("\n");
  printf("Menu:\n");
  printf("\n");
  printf("     1) Senha\n");
  printf("     2) Charadas\n");
  printf("     3) PTP\n");
  printf("     4) Campo Minado\n");
  printf("     5) Roda-a-roda\n");
  printf("     6) Sair\n");
  printf("\n");
  printf("Digite sua op��o:\n");
  scanf(" %c",&opcao);
  system CLEAR;
  while(opcao != '1' && opcao != '2' && opcao !='3' && opcao !='4' && opcao !='5' && opcao !='6'){
    printf("Essa op��o n�o � v�lida\n");
    printf("Digite sua op��o:\n");
    scanf(" %c",&opcao);
  }

   if(opcao == '1'){
    senha(&jogador.psenha);
   }
   if(opcao == '2'){
    charada(&jogador.pcharada);
   }
   if(opcao == '3'){
    ppt(&jogador.pppt);
   }
   if(opcao == '4'){
    campo_minado(&jogador.pcampo);
   }
   if(opcao == '5'){
    roda_a_roda(&jogador.proda);
  }
   if(opcao == '6'){
    printf("Tchau,I have to go now!\n");
    printf("I have to go now, tchau!\n");
    printf("Voc� acabou de ouvir Jammil e Uma Noites na BSBfict�cia FM!\n");
    return 0;
   }
  }
  if(escolha == '2'){

  }
  if(escolha == '3'){

  }
  }
}
