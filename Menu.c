#include "lab.h"
#define BOT 2
#define HUMAN 1

typedef struct BARALHO {
	char cartas[81]; //L,T,W,w,R,C
	int size;
}baralho;
typedef struct  APOSTA{
	char apo[5]; //L,T,W,R,C
	int tam;
}aposta;
typedef struct  TAB {
	char caminho[13]; //I, ,R,F
	int metros;
}tab;
typedef struct  PLAYER {
	int tipo; //N-0,H-1,B-2
	int pont;
	int turn;
	char nome[20];
	char maoP[8];
	char aposP[4];
	char maoB[8];
	char aposB[4];
	int sizeMaoB;
	int sizeAposB;
	int sizeMaoP;
	int sizeAposP;
}jog;
typedef struct CORRIDA {
	char cartasJ[8]; 
	int t;
}corrida;
typedef struct Mesa {
	char cartasj[8];
	int sizej;
	char descarte[79];
	int sizeDes;
	int contagem[6];
}mesa;
typedef struct Corredores {
	char personagem[5];
	int pos[5];
	int contagem[5];
}core;

void resetBaralho(baralho* myDeck) {
	int i = 0;
	for (i = 0; i < 81; i++) {
		myDeck->cartas[i] = 'x';
	}
	myDeck->size = 0;
}
void resetBet(aposta* myBet) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		myBet->apo[i] = 'x';
	}
	myBet->tam = 0;
}
void resetCam(tab* Tabuleiro) {
	int i = 0;
	for (i = 0; i < 13; i++) {
		Tabuleiro->caminho[i] = 'x';
	}
	Tabuleiro->metros = 0;
}
void initBaralho(baralho* myDeck) {
	int i = 0;
	myDeck->size = 0;
	for (i = 0; i < 18; i++) {
		myDeck->cartas[i] = 'L';
		myDeck->size++;
	}
	for (i = 18; i < 35; i++) {
		myDeck->cartas[i] = 'T';
		myDeck->size++;
	}
	for (i = 35; i < 48; i++) {
		myDeck->cartas[i] = 'W';
		myDeck->size++;
	}
	for (i = 48; i < 51; i++) {
		myDeck->cartas[i] = 'w';
		myDeck->size++;
	}
	for (i = 51; i < 66; i++) {
		myDeck->cartas[i] = 'R';
		myDeck->size++;
	}
	for (i = 66; i < 81; i++) {
		myDeck->cartas[i] = 'C';
		myDeck->size++;
	}
	myDeck->size--;
}
void initBet(aposta* myBet) {
	myBet->tam = 0;
	myBet->apo[0] = 'L';
	myBet->tam++;
	myBet->apo[1] = 'T';
	myBet->tam++;
	myBet->apo[2] = 'W';
	myBet->tam++;
	myBet->apo[3] = 'R';
	myBet->tam++;
	myBet->apo[4] = 'C';
}
void initCam(tab* Tabuleiro) {
	int i = 0;
	Tabuleiro->metros = 0;
	for (i = 0; i < 1; i++) {
		Tabuleiro->caminho[i] = 'I';
		Tabuleiro->metros++;
	}
	for (i = 1; i < 10; i++) {
		Tabuleiro->caminho[i] = ' ';
		Tabuleiro->metros++;
	}
	for (i = 10; i < 12; i++) {
		Tabuleiro->caminho[i] = 'R';
		Tabuleiro->metros++;
	}
	for (i = 12; i < 13; i++) {
		Tabuleiro->caminho[i] = 'F';
		Tabuleiro->metros++;
	}
}
void printBaralho(baralho myDeck) {
	int i = 0;
	printf("(");
	for (i = 0; i < 81; i++) {
		printf("%c,", myDeck.cartas[i]);
	}
	printf(")");
	myDeck.size;
}
void printCartasP(jog jogador) {
	int j = 0;
	printf("(");
	for (j = 0; j < jogador.sizeMaoP; j++) {
		printf("%c,", jogador.maoP[j]);
	}
	printf(")");
}
void printMaoP(jog jogador) {
	gotoxy(4, 12); printf("1-%c", jogador.maoP[0]);
	gotoxy(8, 12); printf("2-%c", jogador.maoP[1]);
	gotoxy(12, 12); printf("3-%c", jogador.maoP[2]);
	gotoxy(4, 13); printf("4-%c", jogador.maoP[3]);
	gotoxy(8, 13); printf("5-%c", jogador.maoP[4]);
	gotoxy(12, 13); printf("6-%c", jogador.maoP[5]);
	gotoxy(4, 14); printf("7-%c", jogador.maoP[6]);
	gotoxy(24, 12); printf("1-%c", jogador.aposP[0]);
	gotoxy(24, 13); printf("2-%c", jogador.aposP[1]);
}
int MaoP(){
	int i;
	setlocale(LC_ALL, "Portuguese");
	gotoxy(4, 16); printf("Escolhe uma carta para adicionar ás cartas de aposta:");
	scanf("%d", &i);
	setlocale(LC_ALL, "C");
	return i;
}
//void Nome(jog* jogador) {
//	printf("Nome: ");
//	getchar(&jogador->nome);
//}
void ApostasP(jog* jogador){
	int ca=0;
	while (ca >= 8 || ca <= 0) {
		ca = MaoP();
		gotoxy(4, 16); printf("                                                                             ");
	}
	gotoxy(4, 12); printf("       ");
	gotoxy(8, 12); printf("       ");
	gotoxy(12, 12); printf("       ");
	gotoxy(4, 13); printf("       ");
	gotoxy(8, 13); printf("       ");
	gotoxy(12, 13); printf("       ");
	gotoxy(4, 14); printf("       ");
	gotoxy(24, 12); printf("       ");
	gotoxy(24, 13); printf("       ");
	jogador->aposP[2] = jogador->maoP[ca - 1];
	jogador->sizeAposP++;
	jogador->sizeMaoP--;
	switch (ca) {
	case 1:
	{
		jogador->maoP[0] = jogador->maoP[1];
		jogador->maoP[1] = jogador->maoP[2];
		jogador->maoP[2] = jogador->maoP[3];
		jogador->maoP[3] = jogador->maoP[4];
		jogador->maoP[4] = jogador->maoP[5];
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 2:
	{
		jogador->maoP[1] = jogador->maoP[2];
		jogador->maoP[2] = jogador->maoP[3];
		jogador->maoP[3] = jogador->maoP[4];
		jogador->maoP[4] = jogador->maoP[5];
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 3:
	{
		jogador->maoP[2] = jogador->maoP[3];
		jogador->maoP[3] = jogador->maoP[4];
		jogador->maoP[4] = jogador->maoP[5];
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 4:
	{
		jogador->maoP[3] = jogador->maoP[4];
		jogador->maoP[4] = jogador->maoP[5];
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 5:
	{
		jogador->maoP[4] = jogador->maoP[5];
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 6:
	{
		jogador->maoP[5] = jogador->maoP[6];
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	case 7:
	{
		gotoxy(4, 12); printf("1-%c", jogador->maoP[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoP[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoP[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoP[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoP[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoP[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposP[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposP[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposP[2]);
		break;
	}
	default:
	{
		break;
	}
	}
}
void ApostasB(jog* jogador) {
	int ca = 0;
	srand(time(NULL));
	ca = randomNumber(1, 7);
	ca--;
	jogador->aposB[2] = jogador->maoB[ca - 1];
	jogador->sizeAposB++;
	jogador->sizeMaoB--;
	switch (ca) {
	case 1:
	{
		jogador->maoB[0] = jogador->maoB[1];
		jogador->maoB[1] = jogador->maoB[2];
		jogador->maoB[2] = jogador->maoB[3];
		jogador->maoB[3] = jogador->maoB[4];
		jogador->maoB[4] = jogador->maoB[5];
		jogador->maoB[5] = jogador->maoB[6];
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[1]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[2]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[3]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[4]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[5]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	case 2:
	{
		jogador->maoB[1] = jogador->maoB[2];
		jogador->maoB[2] = jogador->maoB[3];
		jogador->maoB[3] = jogador->maoB[4];
		jogador->maoB[4] = jogador->maoB[5];
		jogador->maoB[5] = jogador->maoB[6];
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[2]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[3]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[4]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[5]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	case 3:
	{
		jogador->maoB[2] = jogador->maoB[3];
		jogador->maoB[3] = jogador->maoB[4];
		jogador->maoB[4] = jogador->maoB[5];
		jogador->maoB[5] = jogador->maoB[6];
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[3]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[4]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[5]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	case 4:
	{
		jogador->maoB[3] = jogador->maoB[4];
		jogador->maoB[4] = jogador->maoB[5];
		jogador->maoB[5] = jogador->maoB[6];
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[4]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[5]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	case 5:
	{
		jogador->maoB[4] = jogador->maoB[5];
		jogador->maoB[5] = jogador->maoB[6];
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[5]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	case 6:
	{
		jogador->maoB[5] = jogador->maoB[6];
		//gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		//gotoxy(8, 12); printf("2-%c", jogador->maoB[1]);
		//gotoxy(12, 12); printf("3-%c", jogador->maoB[2]);
		//gotoxy(4, 13); printf("4-%c", jogador->maoB[3]);
		//gotoxy(8, 13); printf("5-%c", jogador->maoB[4]);
		//gotoxy(12, 13); printf("6-%c", jogador->maoB[6]);
		//gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		//gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		//gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);
		break;
	}
	case 7:
	{
		/*gotoxy(4, 12); printf("1-%c", jogador->maoB[0]);
		gotoxy(8, 12); printf("2-%c", jogador->maoB[1]);
		gotoxy(12, 12); printf("3-%c", jogador->maoB[2]);
		gotoxy(4, 13); printf("4-%c", jogador->maoB[3]);
		gotoxy(8, 13); printf("5-%c", jogador->maoB[4]);
		gotoxy(12, 13); printf("6-%c", jogador->maoB[5]);
		gotoxy(24, 12); printf("1-%c", jogador->aposB[0]);
		gotoxy(24, 13); printf("2-%c", jogador->aposB[1]);
		gotoxy(24, 14); printf("3-%c", jogador->aposB[2]);*/
		break;
	}
	default:
	{
		break;
	}
	}
}
void printApostaP(jog jogador) {
	int j = 0;
	printf("(");
	for (j = 0; j < jogador.sizeAposP; j++) {
		printf("%c,", jogador.aposP[j]);
	}
	printf(")");
}
void printBet(aposta myBet) {
	int i = 0;
	printf("(");
	for (i = 0; i < 5; i++) {
		printf("%c,", myBet.apo[i]);
	}
	printf(")");
	myBet.tam;
}
void printCam(tab Tabuleiro) {
	int i = 0;
	printf("(");
	for (i = 0; i < 13; i++) {
		printf("[%c],", Tabuleiro.caminho[i]);
	}
	printf(")");
	Tabuleiro.metros;
}
void saveBaralho(FILE* fp, baralho myDeck) {
	//Ficheiro já vem aberto e na posição de escrita
	int i = 0;
	fprintf(fp, "(");
	for (i = 0; i < 80; i++) {
		fprintf(fp, "%c,", myDeck.cartas[i]);
	}
	fprintf(fp, "%c", myDeck.cartas[80]);
	fprintf(fp, ")");
}
void readBaralho(FILE* fp, baralho* myDeck) {
	//Ficheiro já vem aberto e na posição de escrita
	int i = 0;
	fgetc(fp);
	for (i = 0; i < 80; i++) {
		myDeck->cartas[i] = fgetc(fp);
		fgetc(fp); //descarta a ','
	}
	myDeck->cartas[i] = fgetc(fp);
	fgetc(fp); //descarta a ')'
}
void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void baralharBaralho(baralho* myDeck) {
	int i, r;
	srand(time(NULL));
	for (i = 0; i < myDeck->size; i++) {
		r = rand() % (i + 1);
		swap(&(myDeck->cartas[i]), &(myDeck->cartas[r]));
	}
}
void barBet(aposta* myBet) {
	int i, r;
	srand(time(NULL));
	for (i = 0; i < myBet->tam; i++) {
		r = rand() % (i + 1);
		swap(&(myBet->apo[i]), &(myBet->apo[r]));
	}
}
void barCam(tab* Tabuleiro) {
	int i, r;
	srand(time(NULL));
	for (i = 1; i < 13 - 1; i++) {	// Começa do segundo elemento e vai até o penúltimo
		r = i + rand() % (13 - i - 1); // Gera um índice aleatório dentro do intervalo
		swap(&(Tabuleiro->caminho[i]), &(Tabuleiro->caminho[r]));
	}
}
void fazerCaminho(tab Tabuleiro,core* corredor) {
	int i,j;
	system("cls");
	gotoxy(4, 6);
	for (j = 0; j < 5; j++) {
		for (i = 0; i < Tabuleiro.metros; i++) {
			if (Tabuleiro.caminho[i] == 'I') {
				printf("[%c]", Tabuleiro.caminho[i]);
			}
			else if (Tabuleiro.caminho[i] == ' ') {
				printf("[%c]", Tabuleiro.caminho[i]);
			}
			else if (Tabuleiro.caminho[i] == 'R') {
				printf("[ ");
				setColor(MY_COLOR_BLACK, MY_COLOR_CYAN);
				printf(" ");
				setColor(MY_COLOR_BLACK, MY_COLOR_DARK_GRAY);
				printf(" ]");
			}
			else if (Tabuleiro.caminho[i] == 'F') {
				printf("[%c]", Tabuleiro.caminho[i]);
			}
		}
		gotoxy(4, 7+j);
	}
	gotoxy(3, 6); printf("L"); corredor->personagem[0] = 'L'; corredor->pos[0] = 0;
	gotoxy(3, 7); printf("T"); corredor->personagem[1] = 'T'; corredor->pos[1] = 0;
	gotoxy(3, 8); printf("W"); corredor->personagem[2] = 'W'; corredor->pos[2] = 0;
	gotoxy(3, 9); printf("R"); corredor->personagem[3] = 'R'; corredor->pos[3] = 0;
	gotoxy(3, 10); printf("C"); corredor->personagem[4] = 'C'; corredor->pos[4] = 0;
}
void disCartas(baralho* myDeck, jog* jogador) {
	int i,k;
	srand(time(NULL));
	jogador->maoP[7] = '?';
	jogador->maoB[7] = '\0';
	jogador->tipo = rand() % 2 + 1;
	for (k = 0; k < 2; k++) {
		if (jogador->tipo == HUMAN) {
			for (i = 0; i < 7; i++) {
				jogador->maoP[i] = myDeck->cartas[myDeck->size - i]; // Distribui as 7 ultimas cartas para o jogador
			}
			jogador->sizeMaoP = 7;
			myDeck->size -= 7;
			jogador->tipo++;
		}
		else {
			for (i = 0; i < 7; i++) {
				jogador->maoB[i] = myDeck->cartas[myDeck->size - i]; // Distribui as 7 ultimas cartas para o bot
			}
			jogador->sizeMaoB = 7;
			myDeck->size -= 7;
			jogador->tipo--;
		}
	}
}
void disApostas(aposta* myBet, jog* jogador) {
	int i, k;
	srand(time(NULL));
	jogador->aposP[3] = '\0';
	jogador->aposB[3] = '\0';
	jogador->tipo = rand() % 2 + 1;
	for (k = 0; k < 2; k++) {
		if (jogador->tipo == HUMAN) {
			for (i = 0; i < 2; i++) {
				jogador->aposP[i] = myBet->apo[myBet->tam - i]; // Distribui as 7 ultimas cartas para o jogador
			}
			jogador->sizeAposP = 2;
			myBet->tam -= 2;
			jogador->tipo++;
		}
		else {
			for (i = 0; i < 2; i++) {
				jogador->aposB[i] = myBet->apo[myBet->tam - i]; // Distribui as 7 ultimas cartas para o bot
			}
			jogador->sizeMaoB = 2;
			myBet->tam -= 2;
			jogador->tipo--;
		}
	}
}
void CartasMesa(mesa* mesa,jog* jogador, baralho* myDeck){
	int i=0,c1=0,c2=0,c3=0,c5=0;
	//if (mesa->sizej>0) {
			setlocale(LC_ALL, "Portuguese");
			while (i >= 5 || i <= 0 || i + mesa->sizej > 8) {
				gotoxy(4, 16); printf("                                                                               ");
				gotoxy(4, 16); printf("Escolhe quantas cartas queres jogar(1-4):");
				scanf("%d", &i);
				if (mesa->sizej == 8) {
					return 0;
				}
			}
			setlocale(LC_ALL, "C");
			switch (i) {
			case 1: {
				while (c1 >= 7 || c1 <= 0) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe a carta para jogar:");
					scanf("%d", &c1);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->sizeMaoP--;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				break;
			}
			case 2: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d", &c1);
					scanf("%d", &c2);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				break;
			}
			case 3: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0) || (c3 >= 7 || c3 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d", &c1);
					scanf("%d", &c2);
					scanf("%d", &c3);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				mesa->sizej++;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				mesa->cartasj[mesa->sizej] = jogador->maoP[c3 - 1];
				mesa->sizej++;
				jogador->maoP[c3 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c3 < 4) {
					if (c3 == 1) {
						gotoxy(4, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 2) {
						gotoxy(8, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 3) {
						gotoxy(12, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				else {
					if (c3 == 4) {
						gotoxy(4, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 5) {
						gotoxy(8, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 6) {
						gotoxy(12, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				break;
			}
			case 4: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0) || (c3 >= 7 || c3 <= 0) || (c5 >= 7 || c5 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d", &c1);
					scanf("%d", &c2);
					scanf("%d", &c3);
					scanf("%d", &c5);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				mesa->cartasj[mesa->sizej] = jogador->maoP[c3 - 1];
				mesa->sizej++;
				jogador->maoP[c3 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c3 < 4) {
					if (c3 == 1) {
						gotoxy(4, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 2) {
						gotoxy(8, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 3) {
						gotoxy(12, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				else {
					if (c3 == 4) {
						gotoxy(4, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 5) {
						gotoxy(8, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 6) {
						gotoxy(12, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c5 - 1];
				mesa->sizej++;
				jogador->maoP[c5 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c5 < 4) {
					if (c5 == 1) {
						gotoxy(4, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c5 == 2) {
						gotoxy(8, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
				}
				break;
			}
			default: {
				break;
			}
			}
		//}
		/*else {
			mesa->sizej = 0;
			setlocale(LC_ALL, "Portuguese");
			while (i >= 5 || i <= 0 || i + mesa->sizej > 8) {
				gotoxy(4, 16); printf("                                                                               ");
				gotoxy(4, 16); printf("Escolhe quantas cartas queres jogar(1-4):");
				scanf("%d", &i);
				if (mesa->sizej == 8) {
					return 0;
				}
			}
			setlocale(LC_ALL, "C");
			switch (i) {
			case 1: {
				while (c1 >= 7 || c1 <= 0) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe a carta para jogar:");
					scanf("%d", &c1);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->sizeMaoP--;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				break;
			}
			case 2: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d %d", &c1, &c2);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				break;
			}
			case 3: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0) || (c3 >= 7 || c3 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d %d %d", &c1, &c2, &c3);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				mesa->sizej++;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				mesa->cartasj[mesa->sizej] = jogador->maoP[c3 - 1];
				mesa->sizej++;
				jogador->maoP[c3 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c3 < 4) {
					if (c3 == 1) {
						gotoxy(4, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 2) {
						gotoxy(8, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 3) {
						gotoxy(12, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				else {
					if (c3 == 4) {
						gotoxy(4, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 5) {
						gotoxy(8, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 6) {
						gotoxy(12, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				break;
			}
			case 4: {
				while ((c1 >= 7 || c1 <= 0) || (c2 >= 7 || c2 <= 0) || (c3 >= 7 || c3 <= 0) || (c5 >= 7 || c5 <= 0)) {
					gotoxy(4, 16); printf("                                                                               ");
					gotoxy(4, 16); printf("Escolhe as cartas para jogares (Do mesmo personagem):");
					scanf("%d %d %d %d", &c1, &c2, &c3, &c5);
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c1 - 1];
				mesa->sizej++;
				jogador->maoP[c1 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c1 < 4) {
					if (c1 == 1) {
						gotoxy(4, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 2) {
						gotoxy(8, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c1, jogador->maoP[c1 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c2 - 1];
				mesa->sizej++;
				jogador->maoP[c2 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				if (c2 < 4) {
					if (c2 == 1) {
						gotoxy(4, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 2) {
						gotoxy(8, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 3) {
						gotoxy(12, 12); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				else {
					if (c2 == 4) {
						gotoxy(4, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 5) {
						gotoxy(8, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
					else if (c2 == 6) {
						gotoxy(12, 13); printf("%d-%c", c2, jogador->maoP[c2 - 1]);
					}
				}
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				mesa->cartasj[mesa->sizej] = jogador->maoP[c3 - 1];
				mesa->sizej++;
				jogador->maoP[c3 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c3 < 4) {
					if (c3 == 1) {
						gotoxy(4, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 2) {
						gotoxy(8, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 3) {
						gotoxy(12, 12); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				else {
					if (c3 == 4) {
						gotoxy(4, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 5) {
						gotoxy(8, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
					else if (c3 == 6) {
						gotoxy(12, 13); printf("%d-%c", c3, jogador->maoP[c3 - 1]);
					}
				}
				mesa->cartasj[mesa->sizej] = jogador->maoP[c5 - 1];
				mesa->sizej++;
				jogador->maoP[c5 - 1] = myDeck->cartas[myDeck->size - 1];
				myDeck->size--;
				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
				if (c5 < 4) {
					if (c5 == 1) {
						gotoxy(4, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c5 == 2) {
						gotoxy(8, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 3) {
						gotoxy(12, 12); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
				}
				else {
					if (c1 == 4) {
						gotoxy(4, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 5) {
						gotoxy(8, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
					else if (c1 == 6) {
						gotoxy(12, 13); printf("%d-%c", c5, jogador->maoP[c5 - 1]);
					}
				}
				break;
			}
			default: {
				break;
			}
			}
		}*/
	}
int fazerContagem(mesa* mesa) {
	int i = 0;

	for (i = 0; i < 6; i++) { // Correção: Removido ponto e vírgula do final do for
		mesa->contagem[i] = 0;
	}

	i = 0;
	while (i < mesa->sizej) {
		switch (mesa->cartasj[i]) {
		case 'L': {
			mesa->contagem[0]++;
			break;
		}
		case 'T': {
			mesa->contagem[1]++;
			break;
		}
		case 'W': {
			mesa->contagem[2]++;
			break;
		}
		case 'w': {
			mesa->contagem[3]++;
			break;
		}
		case 'R': {
			mesa->contagem[4]++;
			break;
		}
		case 'C': {
			mesa->contagem[5]++;
			break;
		}
		default: {
			break;
		}
		}
		i++;
	}
		return 0;
	}
void renderizarTabuleiro(tab* Tabuleiro, core* corredor) {
	int i, j, k;
	for (i=0 ; i < 6; i++) {
		gotoxy(4, 6 + i); printf("                                                                     ");
	}
	i = 0;
	gotoxy(4, 6);
	for ( j = 0; j < 5; j++) {
		for ( i = 0; i < Tabuleiro->metros; i++) {
			if (Tabuleiro->caminho[i] == 'I' || Tabuleiro->caminho[i] == ' ' || Tabuleiro->caminho[i] == 'F') {
				int found = 0;
				for ( k = 0; k < 5; k++) {
					if (corredor->pos[k] == i) {
						printf("[%c]", corredor->personagem[k]);
						found = 1;
						break;
					}
				}
				if (found == 0) {
					printf("[ ]"); // Espaço vazio se não houver personagem na posição
				}
			}
			else if (Tabuleiro->caminho[i] == 'R') {
				printf("[");
				for (int k = 0; k < 5; k++) {
					if (corredor->pos[k] == i) {
						printf("%c", corredor->personagem[k]); // Mostra o número do personagem
						break;
					}
				}
			}
			setColor(MY_COLOR_BLACK, MY_COLOR_CYAN);
			printf(" ");
			setColor(MY_COLOR_BLACK, MY_COLOR_DARK_GRAY);
			printf("]");
		}
		gotoxy(4, 7 + j);
	}
}
int avancarAnimais(mesa mesa, core* corredor, jog jogador, tab* Tabuleiro) {
	int j, i;
	if (mesa.contagem[3] > 0) {
		if ((mesa.contagem[2] + mesa.contagem[3]) <= 2) {
			corredor->pos[2] += 1;
			renderizarTabuleiro(Tabuleiro, corredor);
			gotoxy(4, 18); system("pause");
			return 0;
		}
		else {
			corredor->pos[2] += (mesa.contagem[2] + mesa.contagem[3]) - 1;
			renderizarTabuleiro(Tabuleiro, corredor);
			gotoxy(4, 18); system("pause");
			return 0;
		}
		if (mesa.contagem[0] > 0) {
			if (mesa.contagem[0] == 4 && (corredor->pos[0] > corredor->pos[1] && corredor->pos[0] > corredor->pos[2] && corredor->pos[0] > corredor->pos[3] && corredor->pos[0] > corredor->pos[4])) {
				corredor->pos[0] += 0;
			}
			corredor->pos[0] += 2;
		}
		if (mesa.contagem[1] > 0) {
			corredor->pos[1] += 1;
			if (mesa.contagem[1] == 4) {
				corredor->pos[1]++;
			}
			if (mesa.contagem[2] > 0) {
				if (mesa.contagem[2] == 1 || mesa.contagem[2] == 2) {
					corredor->pos[2]++;
				}
				if (mesa.contagem[2] == 3 || mesa.contagem[2] == 4) {
					corredor->pos[2] += (mesa.contagem[2] - 1);
				}
			}
			if (mesa.contagem[4] > 0) {
				corredor->pos[3] += mesa.contagem[4];
			}
			if (mesa.contagem[5] > 0) {
				for (i = 0; i < mesa.contagem[5] + 1; i++) {
					corredor->pos[4]++;
					if (Tabuleiro->caminho[corredor->pos[4]]) {
						i = mesa.contagem[5] + 1;
					}
				}
			}
		}
		renderizarTabuleiro(Tabuleiro, corredor);
		gotoxy(4, 18); system("pause");
		return 0;
	}
}
void CartasMesaBot(mesa* mesa, jog* jogador, baralho* myDeck) {
	int carta1, /*carta2,*/ rep = 0, tu = 1;
	char personagem,uper;// Variável para armazenar o personagem das cartas escolhidas pelo bot
	uper = 'w';
	srand(time(NULL));
	//if (mesa->sizej >= 1) {
		//do {
			carta1 = rand() % 5 + 0;
			//personagem = jogador->maoB[carta1];
		//} while (personagem != 'L' && personagem != 'T' && personagem != 'R' && personagem != 'C' && personagem != 'W' && personagem != 'w');
		mesa->cartasj[carta1] = jogador->maoB[carta1];
		mesa->sizej++;
		jogador->maoB[carta1] = myDeck->cartas[myDeck->size - 1];
		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[carta1]);
		//if (mesa->sizej == 7) {
		//	mesa->cartasj[mesa->sizej] = jogador->maoB[carta1 - 1];
		//	mesa->sizej++;
		//	jogador->maoB[carta1 - 1] = myDeck->cartas[myDeck->size - 1];
		//	gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
		//}
		//else {
		//	if (personagem == 'w') {
		//		uper = personagem;
		//		personagem = 'W';
		//		do {
		//			carta2 = rand() % 6 + 1;
		//			rep++;
		//			while (rep > 5) {
		//				mesa->cartasj[mesa->sizej] = jogador->maoB[carta1 - 1];;
		//				mesa->sizej++;
		//				jogador->maoB[carta1 - 1] = myDeck->cartas[myDeck->size - 1];
		//				gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
		//			}
		//			if (jogador->maoB[carta2 - 1] == 'w' && personagem=='W') {
		//				personagem = uper;
		//			}
		//		} while (carta2 == carta1 || jogador->maoB[carta2 - 1] != personagem);
		//		mesa->cartasj[mesa->sizej] = uper;
		//		mesa->sizej++;
		//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
		//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta2 - 1];
		//		mesa->sizej++;
		//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);

		//		// Atualiza a mão do bot após jogar as cartas na mesa
		//		jogador->maoB[carta1] = myDeck->cartas[myDeck->size - 1];
		//		jogador->maoB[carta2] = myDeck->cartas[myDeck->size - 2];
		//		jogador->sizeMaoB -= 2;
		//	}
		//	else {
		//		do {
		//			carta2 = rand() % 6 + 1;
		//			rep++;
		//			if (rep > 10) {
		//				personagem = 'w';
		//			}
		//		} while (carta2 == carta1 || jogador->maoB[carta2 - 1] != personagem);
		//		// Adiciona as cartas escolhidas pelo bot na mesa
		//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta1 - 1];
		//		mesa->sizej++;
		//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
		//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta2 - 1];
		//		mesa->sizej++;
		//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);

		//		// Atualiza a mão do bot após jogar as cartas na mesa
		//		jogador->maoB[carta1-1] = myDeck->cartas[myDeck->size - 1];
		//		jogador->maoB[carta2-1] = myDeck->cartas[myDeck->size - 2];
		//		jogador->sizeMaoB -= 2;
		//	}
		//}
	//}
	//else {
		//mesa->sizej = 0;
		//	//do {
		//		carta1 = rand() % 5 + 0;
		//		personagem = jogador->maoB[carta1];
		//	//} while (personagem != 'L' && personagem != 'T' && personagem != 'R' && personagem != 'C' && personagem != 'W' && personagem != 'w');
		//	mesa->cartasj[mesa->sizej] = jogador->maoB[carta1];
		//	mesa->sizej++;
		//	gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[carta1]);
			//if (mesa->sizej == 7) {
			//	mesa->cartasj[mesa->sizej] = jogador->maoB[carta1 - 1];;
			//	mesa->sizej++;
			//	gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
			//}
			//else {
			//	if (personagem == 'w') {
			//		uper = personagem;
			//		personagem = 'W';
			//		do {
			//			carta2 = rand() % 6 + 1;
			//			if (jogador->maoB[carta2 - 1] == 'w') {
			//				personagem = uper;
			//			}
			//		} while (carta2 == carta1 || jogador->maoB[carta2 - 1] != personagem);
			//		mesa->cartasj[mesa->sizej] = uper;
			//		mesa->sizej++;
			//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
			//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta2 - 1];
			//		mesa->sizej++;
			//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);

			//		// Atualiza a mão do bot após jogar as cartas na mesa
			//		jogador->maoB[carta1] = myDeck->cartas[myDeck->size - 1];
			//		jogador->maoB[carta2] = myDeck->cartas[myDeck->size - 2];
			//		jogador->sizeMaoB -= 2;
			//	}
			//	else {
			//		do {
			//			carta2 = rand() % 6 + 1;
			//			rep++;
			//			if (rep > 10) {
			//				uper = personagem;
			//				personagem = 'w';
			//			}
			//		} while (carta2 == carta1 || jogador->maoB[carta2 - 1] != personagem);
			//		// Adiciona as cartas escolhidas pelo bot na mesa
			//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta1 - 1];;
			//		mesa->sizej++;
			//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);
			//		mesa->cartasj[mesa->sizej] = jogador->maoB[carta2 - 1];
			//		mesa->sizej++;
			//		gotoxy(50, 3 + mesa->sizej); printf("%d-%c", mesa->sizej, mesa->cartasj[mesa->sizej - 1]);

			//		// Atualiza a mão do bot após jogar as cartas na mesa
			//		jogador->maoB[carta1] = myDeck->cartas[myDeck->size - 1];
			//		jogador->maoB[carta2] = myDeck->cartas[myDeck->size - 2];
			//		jogador->sizeMaoB -= 2;
			//	}
			//}
	//}
}

void intro()
{
	gotoxy(10, 10); printf("Jogo A Lebre e a Tartaruga");
	gotoxy(10, 11); printf("Feito por : Pedro Martins e Bernardo Mota");

	gotoxy(10, 18); system("pause");
}
char menu()
{
	char a;
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	gotoxy(10, 10); printf("A.Iniciar um novo jogo.");
	gotoxy(10, 11); printf("B.Continuar o jogo anterior.");
	gotoxy(10, 12); printf("C.Informações sobre o jogo.");
	gotoxy(10, 13); printf("D.Sair.");
	gotoxy(10, 14); printf("Escolha:");
	scanf("%c", &a);
	setlocale(LC_ALL, "C");
	return a;
}
void info() {
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	gotoxy(10, 10); printf("Descrição do Jogo:");
	gotoxy(10, 11); printf("Jogo competitivo que baseia-se no conto do mesmo nome, onde vários jogadores apostam");
	gotoxy(10, 12); printf("em corredores e de seguida procuram influenciar o resultado da corrida a seu favor.");
	gotoxy(10, 13); printf("Os corredores são 5 animais: a Lebre, a Tartaruga, o Lobo, a Raposa e o Cordeiro.");
	gotoxy(10, 18); system("pause");
	system("cls");
	gotoxy(10, 10); printf("Composição:");
	gotoxy(10, 11); printf("Tabuleiro: constituí­do pelo espaço da partida, 9 espaços de caminho 'normais' e");
	gotoxy(10, 12); printf("           2 espaços de caminho com ribeiro e o espaço da chegada.");
	gotoxy(10, 13); printf("Corredores (Animais): uma letra diferente marca cada corredor");
	gotoxy(10, 14); printf("Cartas de aposta: uma carta de cada animal, todas diferentes.");
	gotoxy(10, 15); printf("Cartas de corrida: 81 cartas distribuÃ­das pelos 5 animais: 18 para a lebre,");
	gotoxy(10, 16); printf("                   17 para a tartaruga, 16 para o lobo, 15 para a raposa e 15 para o cordeiro.");
	gotoxy(10, 17); printf("                   Das cartas de lobo 3 têm uma marca especial que são “ o lobo a uivar.");
	gotoxy(10, 18); printf("Uma marca para o 1º Jogador da ronda.");
	gotoxy(10, 20); system("pause");
	system("cls");
	gotoxy(10, 10); printf("Objetivo:");
	gotoxy(10, 11); printf("O objetivo do jogo é obter o maior número de pontos possível pelas apostas realizadas.");
	gotoxy(10, 12); printf("Os pontos obtidos são a soma dos pontos obtidos por cada uma das nossas apostas. ");
	gotoxy(10, 13); printf("   1º lugar recebe“ 5 pontos");
	gotoxy(10, 14); printf("   2º lugar recebe“ 3 pontos");
	gotoxy(10, 15); printf("   3º lugar recebe“ 2 pontos");
	gotoxy(10, 16); printf("   Restantes - 0 pontos");
	gotoxy(10, 18); system("pause");
	system("cls");
	gotoxy(10, 10); printf("Regras:");
	gotoxy(10, 11); printf("Os jogadores só podem usar, por rodada, um total de 8 cartas, ou 4 cartas do mesmo corredor.");
	gotoxy(10, 12); printf("Os jogadores , no início, irão receber 2 cartas de apostas, e terão de usar uma das suas 7 cartas para . ");
	gotoxy(10, 13); printf("apostar, ficando ,assim, com 3 cartas de aposta no total. ");
	gotoxy(10, 14); printf("Sempre que um jogador usar uma quantidade de cartas terá de repor a mesma quantidade de cartas usadas. ");
	gotoxy(10, 15); printf("Os jogadores só podem jogar quando o indicador o disser, até lá não pode agir.");
	gotoxy(10, 18); system("pause");
	system("cls");
	gotoxy(10, 10); printf("Movimentos:");
	gotoxy(10, 11); printf("Lebre: Se forem apostadas de 1 a 4 cartas a lebre avança 2 casas,");	
	gotoxy(10, 12); printf(" mas se estiver em primeiro lugar nao avança a menos que esteja empatada com alguem.");
	gotoxy(10, 13); printf("Tartaruga: Se as cartas apostadas forem de 1 a 3 avança 1 casa, se forem 4 avança 2,");
	gotoxy(10, 14); printf(" no final de cada rodada avança sempre uma.");
	gotoxy(10, 15); printf("Lobo/Wolf: Se forem apostadas de 1 a 2 cartas avança 1 casa, se forem de 3 a 4 avança o numero de cartas");
	gotoxy(10, 16); printf("apostadas menos 1. Este corredor possuí o uivo ('w') que impede qualquer personagem alem dele possa avançar. ");
	gotoxy(10, 17); printf("Raposa: Este corredor avança exatamente o mesmo numero de cartas que forem apostadas nele.");
	gotoxy(10, 18); printf("Cordeiro: Este corredor avança o mesmo numero de cartas que forem apostadas nele mais 1,");
		gotoxy(10, 19); printf("contudo sempre que aparecer uma ribeira para e nao avança mais.");
		gotoxy(10, 20); system("pause");
		setlocale(LC_ALL, "C");
}
int novoJogo() {
	baralho myDeck;
	aposta myBet;
	tab Tabuleiro;
	jog jogador;
	mesa mesa;
	core corredor;
	int ApontaJ;
	resetBaralho(&myDeck);
	resetBet(&myBet);
	resetCam(&Tabuleiro);
	initBaralho(&myDeck);
	initBet(&myBet);
	initCam(&Tabuleiro);
	baralharBaralho(&myDeck);
	barBet(&myBet);
	barCam(&Tabuleiro);
	disCartas(&myDeck, &jogador);
	disApostas(&myBet, &jogador);
	ApontaJ = jogador.tipo;
	/*Nome(&jogador);*/
	fazerCaminho(Tabuleiro,&corredor);
	if (ApontaJ == 1) {
		jogador.turn = 1;
		mesa.sizej = 0;
		printMaoP(jogador);
		ApostasP(&jogador);
		ApostasB(&jogador);
		CartasMesa(&mesa, &jogador, &myDeck);
		if (mesa.sizej == 4) {
			fazerContagem(&mesa);
			avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
			gotoxy(4, 18); system("pause");
		}
		else {
			do {

				CartasMesaBot(&mesa, &jogador, &myDeck);
				if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
				}
				else {
					if (mesa.sizej == 8) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
						gotoxy(4, 18); system("pause");
					}
					/*if (mesa.cartasj[0] == mesa.cartasj[3]) {
						avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
						gotoxy(4, 18); system("pause");
					}*/
					else {
						CartasMesa(&mesa, &jogador, &myDeck);
					}
					/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
						gotoxy(4, 18); system("pause");
					}*/
				}
			} while (mesa.sizej < 8);
			fazerContagem(&mesa);
			avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
			gotoxy(4, 18); system("pause");
		}
		jogador.turn++;
		do{
		if (jogador.turn % 2 == 0) {
			CartasMesaBot(&mesa, &jogador, &myDeck);
			do {
				CartasMesa(&mesa, &jogador, &myDeck);
				if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
				}
				else {
					/*if (mesa.cartasj[0] == mesa.cartasj[3]){
					//fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
					gotoxy(4, 18); system("pause");
					}*/
					if (mesa.sizej == 8) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
						gotoxy(4, 18); system("pause");
					}
					else {
						CartasMesaBot(&mesa, &jogador, &myDeck);
					}
					/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
					gotoxy(4, 18); system("pause");
					}*/
				}
			} while (mesa.sizej < 8);
			fazerContagem(&mesa);
			avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
			gotoxy(4, 18); system("pause");
		}
		else {
			CartasMesa(&mesa, &jogador, &myDeck);
			if (mesa.sizej == 4) {
				fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
				gotoxy(4, 18); system("pause");
			}
			else {
				do {

					CartasMesaBot(&mesa, &jogador, &myDeck);
					if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
						gotoxy(4, 18); system("pause");
					}
					else {
						if (mesa.sizej == 8) {
							fazerContagem(&mesa);
							avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
							gotoxy(4, 18); system("pause");
						}
						/*if (mesa.cartasj[0] == mesa.cartasj[3]) {
							avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
							gotoxy(4, 18); system("pause");
						}*/
						else {
							CartasMesa(&mesa, &jogador, &myDeck);
						}
						/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
							fazerContagem(&mesa);
							avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
							gotoxy(4, 18); system("pause");
						}*/
					}
				} while (mesa.sizej < 8);
				fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
				gotoxy(4, 18); system("pause");
			}
			
		}
		jogador.turn++;
		} while (corredor.pos[0] == 12);
	}
	else {
		mesa.sizej = 0;
		ApostasB(&jogador);
		gotoxy(4, 18); system("pause");
		gotoxy(10, 18); printMaoP(jogador);
		ApostasP(&jogador);
		CartasMesaBot(&mesa, &jogador, &myDeck);
		do {
			CartasMesa(&mesa, &jogador, &myDeck);
			if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
				fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
			}
			else {
				/*if (mesa.cartasj[0] == mesa.cartasj[3]){
				//fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
				gotoxy(4, 18); system("pause");
				}*/
				if (mesa.sizej == 8) {
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
				}
				else {
					CartasMesaBot(&mesa, &jogador, &myDeck);
				}
				/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
				fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
				gotoxy(4, 18); system("pause");
				}*/
			}
		} while (mesa.sizej < 8);
		fazerContagem(&mesa);
		avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
		gotoxy(4, 18); system("pause");
		jogador.turn++;
		do {
			if (jogador.turn % 2 == 0) {
				CartasMesa(&mesa, &jogador, &myDeck);
				if (mesa.sizej == 4) {
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
				}
				else {
					do {

						CartasMesaBot(&mesa, &jogador, &myDeck);
						if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
							fazerContagem(&mesa);
							avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
							gotoxy(4, 18); system("pause");
						}
						else {
							if (mesa.sizej == 8) {
								fazerContagem(&mesa);
								avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
								gotoxy(4, 18); system("pause");
							}
							/*if (mesa.cartasj[0] == mesa.cartasj[3]) {
								avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
								gotoxy(4, 18); system("pause");
							}*/
							else {
								CartasMesa(&mesa, &jogador, &myDeck);
							}
							/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
								fazerContagem(&mesa);
								avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
								gotoxy(4, 18); system("pause");
							}*/
						}
					} while (mesa.sizej < 8);
					fazerContagem(&mesa);
					avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
					gotoxy(4, 18); system("pause");
				}
			}
			else {
				CartasMesaBot(&mesa, &jogador, &myDeck);
				do {
					CartasMesa(&mesa, &jogador, &myDeck);
					if (mesa.sizej == 4 && mesa.cartasj[0] == mesa.cartasj[3]) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
						gotoxy(4, 18); system("pause");
					}
					else {
						/*if (mesa.cartasj[0] == mesa.cartasj[3]){
						//fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
						gotoxy(4, 18); system("pause");
						}*/
						if (mesa.sizej == 8) {
							fazerContagem(&mesa);
							avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
							gotoxy(4, 18); system("pause");
						}
						else {
							CartasMesaBot(&mesa, &jogador, &myDeck);
						}
						/*if ((mesa.cartasj[2] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[5]) || (mesa.cartasj[0] == mesa.cartasj[1] && mesa.cartasj[0] == mesa.cartasj[3])) {
						fazerContagem(&mesa);
						avancarAnimais(mesa, &corredor, jogador, Tabuleiro);
						gotoxy(4, 18); system("pause");
						}*/
					}
				} while (mesa.sizej < 8);
				fazerContagem(&mesa);
				avancarAnimais(mesa, &corredor, jogador, &Tabuleiro);
				gotoxy(4, 18); system("pause");
			}
			jogador.turn++;
		} while (corredor.pos[0] == 12);
	}
	gotoxy(4, 18); system("pause");
	FILE* fp = NULL;
	fopen_s(&fp, "deck.txt", "w");
	if (fp) {
		saveBaralho(fp, myDeck);
		fclose(fp);
	}
	return 0;
}
void carregarJogo() {
	baralho myDeck;
	FILE* fp = NULL;
	fopen_s(&fp, "deck.txt", "r");
	if (fp) {
		readBaralho(fp, &myDeck);
		fclose(fp);
	}
	printBaralho(myDeck);
}
int main() {
	setColor(MY_COLOR_BLACK, MY_COLOR_DARK_GRAY);	//dá a cor de background
	system("cls");
	intro();
	char opcao = '0';
	int end = 0;
	do
	{
		opcao = menu();
		switch (opcao)
		{
		case 'A':
		{
			system("cls");
			novoJogo();
			gotoxy(10, 18); system("pause");
			break;
		}
		case 'B':
		{
			system("cls");
			gotoxy(10, 10); printf("Work in Progress");
			gotoxy(10, 18); system("pause");
			break;
		}
		case 'C':
		{
			info();
			break;
		}
		case 'D':
		{
			end = 1;	//acaba o ciclo e fecha o projeto
			system("cls");
			gotoxy(10, 10); printf("Saindo");
			gotoxy(10, 18); system("pause");
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	} while (end == 0);
	return 0;
}