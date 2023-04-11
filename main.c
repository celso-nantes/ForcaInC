#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Necessario para gerar o numero aleatorio.

typedef struct {
  int pt1;
  int pt2; 
  int pt3;
  int pt4;
  char nome_1[100];
  char nome_2[100];
  char nome_3[100];
  char nome_4[100];
} tJogadores;//Responsavel por armazenar os nomes e pontuacoes dos players.

typedef struct {

  char dica[26];
  char palavra_chave[26];
} tSorteada;//Responsavel por armazenar a dica e palavra-chave da vez.

typedef struct {

  char nome_vencedor[100];
} tJogo;//Responsavel por armazenar os nomes dos vencedores.

void Incialiaza_structJogo(tJogo jogo[], int vetor_jogo);//Inicializara os nomes com barra-zero.

tSorteada Lepalavras_Sorteia_Armazena();//Responsavel por ler, sortear e armazenar a palavra-chave da rodada.
int Sorteia_num(int num);//Sorteara um numero aleatorio para a as palavras e jogador inicial.
int Conta_carac(tSorteada palavras); //Conta quantidade de caracteres da palavra-chave.
void TransformaString(tSorteada palavras, char Leitura_Certa_Letras_Player[]);//Passar a string de acertos para underline.
void Transforma_Letra_Ja_Escolhida(tSorteada palavras, char Ja_escolhida[]);// Transformae a string que armazena as leituras em barras-zero.
void flush_in();//Limpa o buffer, evitar problema de armazenar caracteres indesejados.

void Menu();//Menu Inicial, o primeiro menu.

//Menu de 1 player.
void jogo1players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez);
//Menu de 2 players.
void jogo2players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez);
//Menu de 3 players.
void jogo3players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez);
//Menu de 4 players.
void jogo4players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez);//Menu durante o jogo...

tJogadores DefinePontos(int pt1, int pt2, int pt3, int pt4);//Denifir a pontuacao inical de cada player.
tJogadores Le_1_jogador();//Leitura do nome para modo solo.
tJogadores Le_2_jogadores();//Leitura do nome para modo dupla.
tJogadores Le_3_jogadores();//Leitura do nome para modo trio.
tJogadores Le_4_jogadores();//Leitura do nome para o modo quarteto.

void JogaJogo1(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]);// leitura das entradas e comparacoes..o jogo em si. E ao termino do jogo ja printa o resultado. Para 1 player.

void JogaJogo2(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]);// leitura das entradas e comparacoes..o jogo em si. E ao termino do jogo ja printa o resultado. Para 2 players.

void JogaJogo3(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]);// leitura das entradas e comparacoes..o jogo em si. E ao termino do jogo ja printa o resultado. Para 3 players.

void JogaJogo4(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]);// leitura das entradas e comparacoes..o jogo em si. E ao termino do jogo ja printa o resultado. Para 4 players.

int TerminouJogo_1_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]); //Condicao dee parada para ver se o jogo terminou. Para 1 player.
int TerminouJogo_2_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]); //Condicao dee parada para ver se o jogo terminou. Para 2 players.
int TerminouJogo_3_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]); //Condicao dee parada para ver se o jogo terminou. Para 3 players.
int TerminouJogo_4_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]); //Condicao dee parada para ver se o jogo terminou. Para 4 players.

void Printa_vencedor_1player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez); //Printa resultado do jogo de 1 player.
void Printa_vencedor_2player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez); //Printa resultado do jogo de 2 players.
void Printa_vencedor_3player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez); //Printa resultado do jogo de 3 players.
void Printa_vencedor_4player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez); //Printa resultado do jogo de 4 players.

int Continua_ou_para();//Condicional de continuar a jogar ou sair.

void Printa_Vencedores(tJogo jogo[], int jogo_da_vez);//Printa os vencedores.

int main() {
  int i=0,qtdj=1, pt1=6, pt2=6, pt3=6, pt4=6, numLinhas=40, qtd_Carac_Pchave =0, jogador_da_vez =0,opcao, jogo_da_vez= 0, vetor_jogo=20;
  tJogadores jogadores;
  tSorteada palavras;
  tJogo jogo[20];
  char matrizStrg[40][41];
  char Leitura_Certa_Letras_Player[26];
  char Ja_escolhida[26];
  FILE * pFilepalavras;

  Incialiaza_structJogo(jogo, vetor_jogo);

  palavras= Lepalavras_Sorteia_Armazena();
  qtd_Carac_Pchave= Conta_carac(palavras);


  while(qtdj != 0){

    Menu();
  
    scanf("%d%*c", &qtdj);//Quantidade de jogadores.
    printf("\n\n");

    if(qtdj == 1){
    
      jogadores = Le_1_jogador();

      if(jogadores.nome_1[0] == '9'){
        continue;
      }// Repetiria o Menu..
      else if(jogadores.nome_1[0] == '0'){
        exit (0);
      }// Sairia do game..
      
      jogador_da_vez = 1;
      
      JogaJogo1(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez, opcao, jogo);

      //Menu de conituacao.. se for para repetir colocar o continue, se nao; faz nada.

      if(opcao == 1){
        continue;
      }
      else if(opcao == 2){
        exit (0);
      }
      
      break;
      
    }
    else if(qtdj == 2){

      jogadores = Le_2_jogadores();
      jogador_da_vez= Sorteia_num(qtdj);//Sortea o primeiro jogador.

      if(jogadores.nome_1[0] == '9' || jogadores.nome_2[0] == '9'){
        continue;
      }
      else if(jogadores.nome_1[0] == '0' || jogadores.nome_2[0] == '0'){
        exit (0);
      }
      
      JogaJogo2(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez, opcao, jogo);

      //printa menu de conituacao.. se for para repetir colucar o continue, se nao faz nada.

      if(opcao == 1){
        continue;
      }
      else if(opcao == 2){
        exit (0);
      }

      break;

    }
    else if(qtdj == 3){

      jogadores = Le_3_jogadores();
      jogador_da_vez= Sorteia_num(qtdj);//Sortea o primeiro jogador.

      if(jogadores.nome_1[0] == '9' || jogadores.nome_2[0] == '9' || jogadores.nome_3[0] == '9'){
        continue;
      }
      else if(jogadores.nome_1[0] == '0' || jogadores.nome_2[0] == '0' || jogadores.nome_3[0] == '0'){
        exit (0);
      }
      
      JogaJogo3(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez, opcao, jogo);

      //printa menu de conituacao.. se for para repetir colucar o continue, se nao faz nada.

      if(opcao == 1){
        continue;
      }
      else if(opcao == 2){
        exit (0);
      }

      break;

    }
    else if(qtdj == 4){

      jogadores = Le_4_jogadores();
      jogador_da_vez= Sorteia_num(qtdj);//Sortea o primeiro jogador.

      if(jogadores.nome_1[0] == '9' || jogadores.nome_2[0] == '9' || jogadores.nome_3[0] == '9' || jogadores.nome_4[0] == '9'){
        continue;
      }
      else if(jogadores.nome_1[0] == '0' || jogadores.nome_2[0] == '0' || jogadores.nome_3[0] == '0' || jogadores.nome_4[0] == '0'){
        exit (0);
      }
      
      JogaJogo4(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez, opcao, jogo);

      //printa menu de conituacao.. se for para repetir colucar o continue, se nao faz nada.

      if(opcao == 1){
        continue;
      }
      else if(opcao == 2){
        exit (0);
      }

      break;

    }

    Menu();
    scanf("%d", &qtdj);
  }

  //Printa_Vencedores(jogo,jogo_da_vez);
  return 0;
}

void Incialiaza_structJogo(tJogo jogo[], int vetor_jogo){
  int i, j=0;

  for(i=0; i<vetor_jogo; i++){

    while(j <100){
      
      jogo[i].nome_vencedor[j] = '\0';
      j++;
    }
  }
}

tJogadores DefinePontos(int pt1, int pt2, int pt3, int pt4){
  tJogadores jogador;

  jogador.pt1=pt1;
  jogador.pt2=pt2;
  jogador.pt3=pt3;
  jogador.pt4=pt4;

  return jogador;
}

void Menu() {

  system("clear");
  printf("|--------------------MENU----------------------|\n");
  printf("|                                              |\n");
  printf("|1- Modo Solo (Treinamento)                    |\n");
  printf("|2- 2 Jogadores                                |\n");
  printf("|3- 3 Jogadores                                |\n");
  printf("|4- 4 Jogadores                                |\n");
  printf("|0- Sair do jogo                               |\n");
  printf("|Informe a quantidade de jogadores disponiveis:|\n");
  printf("|                                              |\n");
  printf("|----------------------------------------------|\n\n");

}

void jogo1players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez){
  int i=0, qtd =0;

  qtd = Conta_carac(palavras);
  
  system("clear");
  
  printf("############################### Forca ####################################\n\n");

  printf("Jogador 1: %s    --> %d\n\n\n", jogadores.nome_1, jogadores.pt1);

  for(i=0; i <qtd; i++){
    printf("%c ", Leitura_Certa_Letras_Player[i]);
  }
  printf("\n\n\n");
  
  printf("Dica: %s \t\t\t", palavras.dica);

  printf ("Letras ja escolhidas: ");
  for(i=0; i <50; i++){
    printf("%c ", Ja_escolhida[i]);
  }
  printf("\n\n\n");
  
  printf("Jogador %d digite uma letra a sua escolha: \n\n", jogador_da_vez);
}

void jogo2players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez){
  int i=0, qtd =0;

  qtd = Conta_carac(palavras);
  
  system("clear");
  
  printf("############################### Forca ####################################\n\n");
  
  printf("Jogador 1: %s    --> %d\n",jogadores.nome_1, jogadores.pt1 );
  printf("Jogador 2: %s    --> %d\n\n\n\n", jogadores.nome_2, jogadores.pt2);

  for(i=0; i <qtd; i++){
    printf("%c ", Leitura_Certa_Letras_Player[i]);
  }
  printf("\n\n\n");
  
  printf("Dica: %s \t\t\t", palavras.dica); 

  printf ("Letras ja escolhidas: ");
  for(i=0; i <50; i++){
    printf("%c ", Ja_escolhida[i]);
  }
  printf("\n\n\n");
  
  printf("Jogador %d digite uma letra a sua escolha: \n\n", jogador_da_vez);
}

void jogo3players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez){
  int i=0, qtd =0;

  qtd = Conta_carac(palavras);
  
  system("clear");
  
  printf("############################### Forca ####################################\n\n");
  
  printf("Jogador 1: %s    --> %d\n",jogadores.nome_1, jogadores.pt1 );
  printf("Jogador 2: %s    --> %d\n", jogadores.nome_2, jogadores.pt2);
  printf("Jogador 3: %s    --> %d\n\n\n\n", jogadores.nome_3, jogadores.pt3);

for(i=0; i <qtd; i++){
    printf("%c ", Leitura_Certa_Letras_Player[i]);
  }
  printf("\n\n\n");
  
  printf("Dica: %s \t\t\t", palavras.dica); 

  printf ("Letras ja escolhidas: ");
  for(i=0; i <50; i++){
    printf("%c ", Ja_escolhida[i]);
  }
  printf("\n\n\n");
  
  printf("Jogador %d digite uma letra a sua escolha: \n\n", jogador_da_vez);
}

void jogo4players(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char Ja_escolhida[], int jogador_da_vez){
  int i=0, qtd =0;

  qtd = Conta_carac(palavras);
  system("clear");
  
  printf("############################### Forca ####################################\n\n");
  
  printf("Jogador 1: %s    --> %d\n",jogadores.nome_1, jogadores.pt1 );
  printf("Jogador 2: %s    --> %d\n", jogadores.nome_2, jogadores.pt2);
  printf("Jogador 3: %s    --> %d\n", jogadores.nome_3, jogadores.pt3);
  printf("Jogador 4: %s    --> %d\n\n\n\n", jogadores.nome_4, jogadores.pt4);

for(i=0; i <qtd; i++){
    printf("%c ", Leitura_Certa_Letras_Player[i]);
  }
  printf("\n\n\n");
  
  printf("Dica: %s \t\t\t", palavras.dica); 

  printf ("Letras ja escolhidas: ");
  for(i=0; i <50; i++){
    printf("%c ", Ja_escolhida[i]);
  }
  printf("\n\n\n");
  
  printf("Jogador %d digite uma letra a sua escolha: \n\n", jogador_da_vez);
  
}

tJogadores Le_1_jogador(){
  tJogadores jogador;

  system("clear");

  printf ("Informe o nome do jogador 1\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_1);
    printf("\n");
  return jogador;
}
tJogadores Le_2_jogadores(){

  system("clear");
  
  tJogadores jogador;

  printf ("Informe o nome do jogador 1\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_1);
  printf("\n");
  printf ("Informe o nome do jogador 2\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_2);
  printf("\n");

  return jogador;
}
tJogadores Le_3_jogadores(){

  system("clear");
  
  tJogadores jogador;

  printf ("Informe o nome do jogador 1\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_1);
  printf("\n");
  printf ("Informe o nome do jogador 2\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_2);
  printf("\n");
  printf ("Informe o nome do jogador 3\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_3);
  printf("\n");
  
  return jogador;
}
tJogadores Le_4_jogadores(){

  system("clear");
  
  tJogadores jogador;

  printf ("Informe o nome do jogador 1\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_1);
  printf("\n");
  printf ("Informe o nome do jogador 2\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_2);
  printf("\n");
  printf ("Informe o nome do jogador 3\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_3);
  printf("\n");
  printf ("Informe o nome do jogador 4\n\n\n");
  printf ("Nome: <nome do jogador> ou <numero>\n\n");
  printf("9- Voltar\n");
  printf("0- Sair do jogo\n\n");

  printf("Digite seu nome: ");
  scanf("%s", jogador.nome_4);
  printf("\n");

  return jogador;
}

int Sorteia_num(int num){
  int numSorteio;

  srand(time(NULL));/*objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL)*/

  numSorteio = 1 + (rand() % num);

  return numSorteio;
}

tSorteada Lepalavras_Sorteia_Armazena(){
  char letra;
  int i=0,j=0, numSorteado, quantLinhas = 39;
  char matrizStrg[40][52];
  char palavra_chave[26];
  char dica[26];
  FILE * pFilepalavras;
  tSorteada palavras;

  //Inicio da leitura e armazenamento das palvras.

  for (i=0; i<40; i++){
    for(j=0; j<52; j++){
      matrizStrg[i][j] = '\0';
    }
  }

  pFilepalavras= fopen("palavras.csv", "r");

  for(i=0; i<40; i++){
    for(j=0; j<52; j++){
      fscanf(pFilepalavras, "%c" , &letra);
      
      if(letra == '\n'){
        break;
      }
      if((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || (letra ==',')){
        matrizStrg[i][j]= letra;
      }
    }
  }

  fclose(pFilepalavras);

  //Inicio do Sorteio das palavras.

  numSorteado= Sorteia_num(quantLinhas);

  //Armazenando a palavra de dica escolhida na string. 
  int k=0, l=0;
  j=0;
  
  while(matrizStrg[numSorteado][j]!= ','){
    dica[k] = matrizStrg[numSorteado][j];
    k++;
    j++;
  }
  j++;

  while(matrizStrg[numSorteado][j]!= '\n'){
    palavra_chave[l] = matrizStrg[numSorteado][j];
    l++;
    j++;
  }


  // Passando as palvras para a struct

  i=0;
  j=0;

  while(dica[i] != '\0'){
    palavras.dica[i]= dica[i];
    i++;
  }
  while(palavra_chave[j] != '\0'){
    palavras.palavra_chave[j]= palavra_chave[j];
    j++;
    
  }
  return palavras;
}

int Conta_carac(tSorteada palavras){
  int count = 0;

    for (int i = 0; palavras.palavra_chave[i] != '\0'; i++) {
      count++;    
    }

  return count;
}

void flush_in(){ 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void TransformaString(tSorteada palavras, char Leitura_Certa_Letras_Player[]){
  int qtd=0, i=0;
  
  qtd = Conta_carac(palavras);

  for(i=0; i <qtd; i++){
    Leitura_Certa_Letras_Player[i]= '_';
  }
  i++;
  Leitura_Certa_Letras_Player[i]= '\0';
  
}

void Transforma_Letra_Ja_Escolhida(tSorteada palavras, char Ja_escolhida[]){
  int i=0;
  
  for(i=0; i <50; i++){
    Ja_escolhida[i]= '\0';
  }
}

void JogaJogo1(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char
Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]){
  int i = 0, j = 0, Leu_certo = 0, segunda_rodada = 0;
  int pt1=6, pt2=6, pt3=6, pt4=6, jogo_da_vez = 0;
  char leitura;

  jogadores = DefinePontos(pt1,  pt2,  pt3,  pt4); // Define a pontucao dos players.
  TransformaString(palavras, Leitura_Certa_Letras_Player);// Transforma em underline.
  Transforma_Letra_Ja_Escolhida(palavras, Ja_escolhida);// Trasnforma em barra-zero.

  flush_in();//Limpeza do buffer.

  do {
    jogo1players(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez);
    scanf("%c%*c", &leitura);
  
    // se errar na entrada refazer a leitura.
    
    if(!(((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z')))){
  
      printf("Opcao invalida! Digite uma letra novamente: \n\n");
      
      do {
        scanf("%c%*c", &leitura);

        
        if(!((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z'))){
          printf("Opcao invalida! Digite uma letra novamente: \n\n");
          Leu_certo =0;
        }
        else{
          Leu_certo =1;
          break;
        }
      }while(Leu_certo == 0);
    }
    
    //transforma em minuscula caso nao seja.
    if(leitura >= 'A' && leitura <= 'Z'){
      leitura = leitura+32;
    }

    //A partir da segunda rodada confere se a letra ja foi escolhida anteriormente.

    int k=0, iguais =0, Nao_e_igual = 1;

    if(segunda_rodada >0){
      
      while(Ja_escolhida[k] != '\0'){
        if (leitura == Ja_escolhida[k]){
          iguais++;
        }
        k++;
      }
      
      if(iguais >0){
        printf("Essa letra ja foi escolhida. Escolha outra letra:\n\n");

        iguais = 0;

        while(Nao_e_igual != 0){

          scanf("%c%*c", &leitura);

          while(Ja_escolhida[k] != '\0'){
            if (leitura == Ja_escolhida[k]){
              iguais++;
            }
            k++;
          }
          
          if(iguais > 0){
            Nao_e_igual = 1;
          }
          else{
            break;
          }
          k=0;
          iguais=0;
        }
      }
      k=0;
      iguais=0;
    }
    Ja_escolhida[i]= leitura;

    //Apos a leitura correta, conferir se a letra faz parte da palvra chave.
    
    j=0;
    int acertou =0;
    while(palavras.palavra_chave[j] != '\0'){
      
      if(leitura == palavras.palavra_chave[j]){
        Leitura_Certa_Letras_Player[j] = leitura;
        acertou++;
      }
      j++;
    }
    if(acertou ==0){
      jogadores.pt1--;
    }
    j=0;
    segunda_rodada++;
    i++;
    acertou=0;

    if(jogadores.pt1 ==0){
      break;
    }
    
  } while(TerminouJogo_1_player(jogadores, Leitura_Certa_Letras_Player) != 0);

  Printa_vencedor_1player(jogadores, jogo, jogo_da_vez);

  opcao = Continua_ou_para();

  // if(opcao == 1){
  //   jogo_da_vez++;
  // }
}

void JogaJogo2(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char
Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]){
  int i = 0, j = 0, Leu_certo = 0, segunda_rodada = 0, jogo_da_vez = 0;
  int pt1=6, pt2=6, pt3=6, pt4=6;
  char leitura;

  jogadores = DefinePontos(pt1,  pt2,  pt3,  pt4); // Define a pontucao dos players.
  TransformaString(palavras, Leitura_Certa_Letras_Player);// Transforma em underline.
  Transforma_Letra_Ja_Escolhida(palavras, Ja_escolhida);// Trasnforma em barra-zero.

  flush_in();

  do {
    jogo2players(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez);
    
    scanf("%c%*c", &leitura);
  
    // se errar na entrada refazer a leitura.
    
    if(!(((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z')))){
  
      printf("Opcao invalida! Digite uma letra novamente: \n\n");
      
      do {
        scanf("%c%*c", &leitura);

        
        if(!((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z'))){
          printf("Opcao invalida! Digite uma letra novamente: \n\n");
          Leu_certo =0;
        }
        else{
          Leu_certo =1;
          break;
        }
      }while(Leu_certo == 0);
    }
    
    //transforma em minuscula caso nao seja.
    if(leitura >= 'A' && leitura <= 'Z'){
      leitura = leitura+32;
    }

    //A partir da segunda rodada confere se a letra ja foi escolhida anteriormente.

    
    int k=0, iguais =0, Nao_e_igual = 1;

    if(segunda_rodada >0){
      
      while(Ja_escolhida[k] != '\0'){
        if (leitura == Ja_escolhida[k]){
          iguais++;
        }
        k++;
      }
      
      if(iguais >0){
        printf("Essa letra ja foi escolhida. Escolha outra letra:\n\n");

        iguais = 0;

        while(Nao_e_igual != 0){

          scanf("%c%*c", &leitura);

          while(Ja_escolhida[k] != '\0'){
            if (leitura == Ja_escolhida[k]){
              iguais++;
            }
            k++;
          }
          
          if(iguais > 0){
            Nao_e_igual = 1;
          }
          else{
            break;
          }
          k=0;
          iguais=0;
        }
      }
      k=0;
      iguais=0;
    }
    Ja_escolhida[i]= leitura;

    //Apos a leitura correta, conferir se a letra faz parte da palvra chave.

    if(jogador_da_vez == 1){
    
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt1--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 2){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt2--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    jogador_da_vez++;

    if(jogador_da_vez > 2 ){
      jogador_da_vez = 1;
    }
    
  } while(TerminouJogo_2_player(jogadores, Leitura_Certa_Letras_Player) != 0);

  Printa_vencedor_2player(jogadores, jogo, jogo_da_vez);

  opcao = Continua_ou_para();

  if(opcao == 1){
    jogo_da_vez++;
  }
}

void JogaJogo3(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char
Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]){
  int i = 0, j = 0, Leu_certo = 0, segunda_rodada = 0, jogo_da_vez =0;
  int pt1=6, pt2=6, pt3=6, pt4=6;
  char leitura;

  jogadores = DefinePontos(pt1,  pt2,  pt3,  pt4); // Define a pontucao dos players.
  TransformaString(palavras, Leitura_Certa_Letras_Player);// Transforma em underline.
  Transforma_Letra_Ja_Escolhida(palavras, Ja_escolhida);// Trasnforma em barra-zero.

  flush_in();

  do {
    jogo3players(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez);
    
    scanf("%c%*c", &leitura);
  
    // se errar na entrada refazer a leitura.
    
    if(!(((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z')))){
  
      printf("Opcao invalida! Digite uma letra novamente: \n\n");
      
      do {
        scanf("%c%*c", &leitura);

        
        if(!((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z'))){
          printf("Opcao invalida! Digite uma letra novamente: \n\n");
          Leu_certo =0;
        }
        else{
          Leu_certo =1;
          break;
        }
      }while(Leu_certo == 0);
    }
    
    //transforma em minuscula caso nao seja.
    if(leitura >= 'A' && leitura <= 'Z'){
      leitura = leitura+32;
    }

    //A partir da segunda rodada confere se a letra ja foi escolhida anteriormente.

    
    int k=0, iguais =0, Nao_e_igual = 1;

    if(segunda_rodada >0){
      
      while(Ja_escolhida[k] != '\0'){
        if (leitura == Ja_escolhida[k]){
          iguais++;
        }
        k++;
      }
      
      if(iguais >0){
        printf("Essa letra ja foi escolhida. Escolha outra letra:\n\n");

        iguais = 0;

        while(Nao_e_igual != 0){

          scanf("%c%*c", &leitura);

          while(Ja_escolhida[k] != '\0'){
            if (leitura == Ja_escolhida[k]){
              iguais++;
            }
            k++;
          }
          
          if(iguais > 0){
            Nao_e_igual = 1;
          }
          else{
            break;
          }
          k=0;
          iguais=0;
        }
      }
      k=0;
      iguais=0;
    }
    Ja_escolhida[i]= leitura;

    //Apos a leitura correta, conferir se a letra faz parte da palvra chave.

    if(jogador_da_vez == 1){
    
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt1--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 2){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt2--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 3){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt3--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    jogador_da_vez++;

    //Analisa qual o proximo jogador a jogar.
    if(jogador_da_vez == 1 && jogadores.pt1 == 0){
      jogador_da_vez = 2;
    }
    else if(jogador_da_vez == 2 && jogadores.pt2 == 0){
      jogador_da_vez = 3;
    }
    else if(jogador_da_vez == 3 && jogadores.pt3 == 0){
      jogador_da_vez = 1;
    }
    else if(jogador_da_vez == 4){
      jogador_da_vez = 1;
    }
    
  } while(TerminouJogo_3_player(jogadores, Leitura_Certa_Letras_Player) != 0);

  Printa_vencedor_3player(jogadores, jogo, jogo_da_vez);

  opcao = Continua_ou_para();

  if(opcao == 1){
    jogo_da_vez++;
  }
}

void JogaJogo4(tJogadores jogadores, tSorteada palavras, char Leitura_Certa_Letras_Player[], char
Ja_escolhida[], int jogador_da_vez, int opcao, tJogo jogo[]){
  int i = 0, j = 0, Leu_certo = 0, segunda_rodada = 0, jogo_da_vez = 0;
  int pt1=6, pt2=6, pt3=6, pt4=6;
  char leitura;

  jogadores = DefinePontos(pt1,  pt2,  pt3,  pt4); // Define a pontucao dos players.
  TransformaString(palavras, Leitura_Certa_Letras_Player);// Transforma em underline.
  Transforma_Letra_Ja_Escolhida(palavras, Ja_escolhida);// Trasnforma em barra-zero.

  flush_in();

  do {
    jogo4players(jogadores, palavras, Leitura_Certa_Letras_Player, Ja_escolhida, jogador_da_vez);
    
    scanf("%c%*c", &leitura);
  
    // se errar na entrada refazer a leitura.
    
    if(!(((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z')))){
  
      printf("Opcao invalida! Digite uma letra novamente: \n\n");
      
      do {
        scanf("%c%*c", &leitura);

        
        if(!((leitura >='a') && (leitura <='z')) || ((leitura >='A') && (leitura <='Z'))){
          printf("Opcao invalida! Digite uma letra novamente: \n\n");
          Leu_certo =0;
        }
        else{
          Leu_certo =1;
          break;
        }
      }while(Leu_certo == 0);
    }
    
    //transforma em minuscula caso nao seja.
    if(leitura >= 'A' && leitura <= 'Z'){
      leitura = leitura+32;
    }

    //A partir da segunda rodada confere se a letra ja foi escolhida anteriormente.

    
    int k=0, iguais =0, Nao_e_igual = 1;

    if(segunda_rodada >0){
      
      while(Ja_escolhida[k] != '\0'){
        if (leitura == Ja_escolhida[k]){
          iguais++;
        }
        k++;
      }
      
      if(iguais >0){
        printf("Essa letra ja foi escolhida. Escolha outra letra:\n\n");

        iguais = 0;

        while(Nao_e_igual != 0){

          scanf("%c%*c", &leitura);

          while(Ja_escolhida[k] != '\0'){
            if (leitura == Ja_escolhida[k]){
              iguais++;
            }
            k++;
          }
          
          if(iguais > 0){
            Nao_e_igual = 1;
          }
          else{
            break;
          }
          k=0;
          iguais=0;
        }
      }
      k=0;
      iguais=0;
    }
    Ja_escolhida[i]= leitura;

    //Apos a leitura correta, conferir se a letra faz parte da palvra chave.

    if(jogador_da_vez == 1){
    
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt1--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 2){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt2--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 3){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt3--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    else if(jogador_da_vez == 4){
      j=0;
      int acertou =0;
      while(palavras.palavra_chave[j] != '\0'){
        
        if(leitura == palavras.palavra_chave[j]){
          Leitura_Certa_Letras_Player[j] = leitura;
          acertou++;
        }
        j++;
      }
      if(acertou ==0){
        jogadores.pt4--;
      }
      j=0;
      segunda_rodada++;
      i++;
      acertou=0;
    }
    jogador_da_vez++;

    //Analisa qual o proximo jogador a jogar.
    if(jogador_da_vez == 1 && jogadores.pt1 == 0){
      jogador_da_vez = 2;
    }
    else if(jogador_da_vez == 2 && jogadores.pt2 == 0){
      jogador_da_vez = 3;
    }
    else if(jogador_da_vez == 3 && jogadores.pt3 == 0){
      jogador_da_vez = 4;
    }
    else if(jogador_da_vez == 4 && jogadores.pt4 == 0){
      jogador_da_vez = 1;
    }
    else if(jogador_da_vez == 5){
      jogador_da_vez = 1;
    }
    
  } while(TerminouJogo_4_player(jogadores, Leitura_Certa_Letras_Player) != 0);

  Printa_vencedor_4player(jogadores, jogo, jogo_da_vez);

  opcao = Continua_ou_para();

  if(opcao == 1){
    jogo_da_vez++;
  }
}

int TerminouJogo_1_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]){
  int num=0, i=0, qtd_=0;
  // Se a pontuação do jogadore for deiferente de zero.
  // se não tiver mais _ na palavra certa
  while(Leitura_Certa_Letras_Player[i] != '\0'){
    if(Leitura_Certa_Letras_Player[i] == '_'){
      qtd_++;
    }
    i++;
  }
  if(qtd_ == 0){
    return 0;
  }
  else if(jogadores.pt1 >0 || qtd_ >0){
    return 1;
  }
  else{
    return 0;
  }
  qtd_=0;

  return 0;
}

int TerminouJogo_2_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]){
  int num=0, i=0, qtd_=0;
  // Se a pontuação do jogadore for deiferente de zero.
  // se não tiver mais _ na palavra certa
  while(Leitura_Certa_Letras_Player[i] != '\0'){
    if(Leitura_Certa_Letras_Player[i] == '_'){
      qtd_++;
    }
    i++;
  }
  if(qtd_ == 0){
    return 0;
  }
  else if(jogadores.pt1 >0 && jogadores.pt2 == 0){
    return 0;
  }
  else if(jogadores.pt1 ==0 && jogadores.pt2 > 0){
    return 0;
  }
  else if(jogadores.pt1 >0 && jogadores.pt2 > 0){
    return 1;
  }
  else{
    return 0;
  }
  qtd_=0;

  return 0;
}

int TerminouJogo_3_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]){
  int num=0, i=0, qtd_=0;
  // Se a pontuação do jogadore for deiferente de zero.
  // se não tiver mais _ na palavra certa
  while(Leitura_Certa_Letras_Player[i] != '\0'){
    if(Leitura_Certa_Letras_Player[i] == '_'){
      qtd_++;
    }
    i++;
  }
  if(qtd_ == 0){
    return 0;
  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 > 0 && jogadores.pt3 == 0){
    return 0;
  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 == 0 && jogadores.pt3 > 0){
    return 0;
  }
  else if(jogadores.pt1 > 0 && jogadores.pt2 == 0 && jogadores.pt3 == 0){
    return 0;
  }
    else if(jogadores.pt1 > 0 && jogadores.pt2 > 0 && jogadores.pt3 > 0){
    return 1;
  }
  else{
    return 1;
  }
  qtd_=0;

  return 0;
}

int TerminouJogo_4_player(tJogadores jogadores, char Leitura_Certa_Letras_Player[]){
  int num=0, i=0, qtd_=0;
  // Se a pontuação do jogadore for deiferente de zero.
  // se não tiver mais _ na palavra certa.
  while(Leitura_Certa_Letras_Player[i] != '\0'){
    if(Leitura_Certa_Letras_Player[i] == '_'){
      qtd_++;
    }
    i++;
  }
  if(qtd_ == 0){
    return 0;
  }
  if(jogadores.pt1 > 0 && jogadores.pt2 == 0 && jogadores.pt3 == 0 && jogadores.pt4 == 0){
    return 0;
  }
  else if(jogadores.pt1 ==0 && jogadores.pt2 > 0 && jogadores.pt3 == 0 && jogadores.pt4 == 0){
    return 0;
  }
  else if(jogadores.pt1 ==0 && jogadores.pt2 == 0 && jogadores.pt3 > 0 && jogadores.pt4 == 0){
    return 0;
  }
  else if(jogadores.pt1 ==0 && jogadores.pt2 == 0 && jogadores.pt3 == 0 && jogadores.pt4 > 0){
    return 0;
  }
  else if(jogadores.pt1 > 0 && jogadores.pt2 > 0 && jogadores.pt3 > 0 && jogadores.pt4 > 0){
    return 1;
  }
  else{
    return 1;
  }
  return 0;
}

void Printa_vencedor_1player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez){
  system("clear");

  int j=0;
  
  if(jogadores.pt1 > 0){
    printf("Parabens %s !! Voce venceu.\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else{
    printf("Que pena %s !! Voce perdeu. Sorte na Proxima!\n\n", jogadores.nome_1);
  }
}

void Printa_vencedor_2player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez){
  system("clear");

  int j=0;
  
  if(jogadores.pt1 > 0 && jogadores.pt2 == 0){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 > jogadores.pt2){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 < jogadores.pt2){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 > 0){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else if(jogadores.pt1 == jogadores.pt2){
    printf("Os jogadores 1 e 2 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2);
  }
}

void Printa_vencedor_3player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez){
  system("clear");

  int j=0;

  if(jogadores.pt1 > jogadores.pt2 && jogadores.pt1 > jogadores.pt3){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt2 > jogadores.pt1 && jogadores.pt2 > jogadores.pt3){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt3 > jogadores.pt1 && jogadores.pt3 > jogadores.pt2){
    printf("O jogador 3 venceu!!! %s se salvou!!\n\n", jogadores.nome_3);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 > 0 && jogadores.pt2 == 0 && jogadores.pt3 == 0){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 > 0 && jogadores.pt3 == 0){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 == 0 && jogadores.pt3 > 0){
    printf("O jogador 3 venceu!!! %s se salvou!!\n\n", jogadores.nome_3);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }  
  else if(jogadores.pt1 == jogadores.pt2 && jogadores.pt1 > 0 && jogadores.pt1 > jogadores.pt3){
    printf("Os jogadores 1 e 2 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2);
  }
  else if(jogadores.pt1 == jogadores.pt3 && jogadores.pt1 > 0 && jogadores.pt1 > jogadores.pt2){
    printf("Os jogadores 1 e 3 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_3);
  }
  else if(jogadores.pt3 == jogadores.pt2 && jogadores.pt3 > 0 && jogadores.pt3 > jogadores.pt1){
    printf("Os jogadores 3 e 2 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_3, jogadores.nome_2);
  }
  else if(jogadores.pt2 == jogadores.pt1 && jogadores.pt2 == jogadores.pt3){
    printf("Os jogadores 1, 2 e 3 empataram!!! %s, %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2, jogadores.nome_3);
  }
  
}

void Printa_vencedor_4player(tJogadores jogadores, tJogo jogo[], int jogo_da_vez){
  system("clear");

  int j=0;

  if(jogadores.pt1 > jogadores.pt2 && jogadores.pt1 > jogadores.pt3 && jogadores.pt1 > jogadores.pt4){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt2 > jogadores.pt1 && jogadores.pt2 > jogadores.pt3 && jogadores.pt2 > jogadores.pt4){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
  else if(jogadores.pt3 > jogadores.pt1 && jogadores.pt3 > jogadores.pt2 && jogadores.pt3 > jogadores.pt4){
    printf("O jogador 3 venceu!!! %s se salvou!!\n\n", jogadores.nome_3);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
    else if(jogadores.pt4 > jogadores.pt1 && jogadores.pt4 > jogadores.pt2 && jogadores.pt4 > jogadores.pt3){
    printf("O jogador 4 venceu!!! %s se salvou!!\n\n", jogadores.nome_4);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else if(jogadores.pt1 > 0 && jogadores.pt2 == 0 && jogadores.pt3 == 0 && jogadores.pt4 == 0){
    printf("O jogador 1 venceu!!! %s se salvou!!\n\n", jogadores.nome_1);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 > 0 && jogadores.pt3 == 0 && jogadores.pt4 == 0){
    printf("O jogador 2 venceu!!! %s se salvou!!\n\n", jogadores.nome_2);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else if(jogadores.pt1 == 0 && jogadores.pt2 == 0 && jogadores.pt3 > 0 && jogadores.pt4 == 0){
    printf("O jogador 3 venceu!!! %s se salvou!!\n\n", jogadores.nome_3);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

    
  }
    else if(jogadores.pt1 == 0 && jogadores.pt2 == 0 && jogadores.pt3 == 0 && jogadores.pt4 > 0){
    printf("O jogador 4 venceu!!! %s se salvou!!\n\n", jogadores.nome_4);
    printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");

  }
  else if(jogadores.pt1 == jogadores.pt2 && jogadores.pt1 > 0 && jogadores.pt1 > jogadores.pt3 && jogadores.pt1 > jogadores.pt4){
    printf("Os jogadores 1 e 2 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2);
  }
  else if(jogadores.pt1 == jogadores.pt3 && jogadores.pt1 > 0 && jogadores.pt1 > jogadores.pt2 && jogadores.pt1 > jogadores.pt4){
    printf("Os jogadores 1 e 3 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_3);
  }
    else if(jogadores.pt1 == jogadores.pt4 && jogadores.pt1 > 0 && jogadores.pt1 > jogadores.pt2 && jogadores.pt1 > jogadores.pt3){
    printf("Os jogadores 1 e 4 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_4);
  }
  else if(jogadores.pt3 == jogadores.pt2 && jogadores.pt3 > 0 && jogadores.pt2 > jogadores.pt1 && jogadores.pt2 > jogadores.pt4){
    printf("Os jogadores 3 e 2 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_3, jogadores.nome_2);
  }
  else if(jogadores.pt3 == jogadores.pt4 && jogadores.pt3 > 0 && jogadores.pt4 > jogadores.pt2 && jogadores.pt4 > jogadores.pt1){
    printf("Os jogadores 3 e 4 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_3, jogadores.nome_4);
  }
  else if(jogadores.pt2 == jogadores.pt4 && jogadores.pt2 > 0 && jogadores.pt4 > jogadores.pt1 && jogadores.pt4 > jogadores.pt3){
    printf("Os jogadores 2 e 4 empataram!!! %s e %s se salvaram!!\n\n", jogadores.nome_2, jogadores.nome_4);
  }
    else if(jogadores.pt2 == jogadores.pt1 && jogadores.pt2 == jogadores.pt3 && jogadores.pt1 > jogadores.pt4 ){
    printf("Os jogadores 1, 2 e 3 empataram!!! %s, %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2, jogadores.nome_3);
  }
      else if(jogadores.pt1 == jogadores.pt4 && jogadores.pt1 == jogadores.pt3 && jogadores.pt1 > jogadores.pt2){
    printf("Os jogadores 1, 3 e 4 empataram!!! %s, %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_3, jogadores.nome_4);
  }
  else if(jogadores.pt2 == jogadores.pt4 && jogadores.pt2 == jogadores.pt3 && jogadores.pt2 > jogadores.pt1){
    printf("Os jogadores 2, 3 e 4 empataram!!! %s, %s e %s se salvaram!!\n\n", jogadores.nome_2, jogadores.nome_3, jogadores.nome_4);
  }
  else if(jogadores.pt2 == jogadores.pt1 && jogadores.pt2 == jogadores.pt4 && jogadores.pt1 > jogadores.pt3){
    printf("Os jogadores 1, 2 e 4 empataram!!! %s, %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2, jogadores.nome_4);
  }
  else if(jogadores.pt2 == jogadores.pt1 && jogadores.pt2 == jogadores.pt4 && jogadores.pt2 == jogadores.pt3){
    printf("Os jogadores 1, 2, 3 e 4 empataram!!! %s, %s, %s e %s se salvaram!!\n\n", jogadores.nome_1, jogadores.nome_2, jogadores.nome_3, jogadores.nome_4);
  }
  
}

int Continua_ou_para(){
  int opcao;

  printf("Deseja Jogar novemente ?\n\n1- Sim\n2- Nao\n\n");

  scanf("%d", &opcao);

  return opcao;
  
}

void Printa_Vencedores(tJogo jogo[], int jogo_da_vez){
  int i=0;

  for(i=0; i<= jogo_da_vez; i++){
    printf("Jogador(es) Vencedor(es):\n\n%s.\n", jogo[i].nome_vencedor);
  }
  
}
