#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXNM 1400
#define MAXCHAR 70

int C, L;    /* Numero de Colunas, Numero de Linhas (da matriz)*/
unsigned int MAXcor;


/*							    */
/*			ESTRUTURA PIXEL			    */
/*							    */
typedef struct pixel{
	unsigned char r, g, b;
}Pixel;


/*							    */
/*		    BRANCOS E COMENTARIOS		    */
/*							    */
void brancosEcomentarios(){
	char c;
	c = getchar();
	while (isspace(c) || c == '#'){
		if (isspace(c))
			c = getchar();
		else{
			putchar(c);
			while ((c=getchar()) != '\n')
				putchar(c);
			putchar(c);
		}
	}
	ungetc(c, stdin);
}

/*							    */
/*			CABECALHO			    */
/*							    */
void cabecalho(char comentario[], int M, int N){	
	char c ;
	brancosEcomentarios();
	
	c=getchar(); putchar(c);
	c=getchar(); putchar(c);
	
	printf("\n%s\n", comentario); 

	brancosEcomentarios();
	
	scanf("%d",&C); printf("%d ",C*N);

	brancosEcomentarios();
	
	scanf("%d",&L); printf("%d\n",L*M);

	brancosEcomentarios();

	scanf("%u", &MAXcor);
	
	printf("%u\n",MAXcor);

}


/*							    */
/*				NEGATIVO		    */
/*							    */
void negativo(){
	int num, cont = 0, contC = 0;
	int linha = 1, coluna = 1;
	int numcars = log10(MAXcor)+1;
	while(linha <= L || coluna <= C){
		scanf("%d", &num);
		
		num = MAXcor - num;
		printf("%*d", numcars, num);
		if (cont < 2){
			printf(" ");
			cont++;
		}
		else if (cont == 2 && contC != C-1){
			printf("   ");
			cont = 0;
			contC++;
			coluna++;
		}
		else if (cont == 2 && contC == C-1){
			printf("\n");
			cont = 0;
			contC = 0;
			linha++;
		}
	}
}


/*							    */
/*				ESPELHO			    */
/*							    */
void espelho(){
	Pixel linha[MAXNM], pix;
	int i, j, k, num, contC= 0;
	unsigned int cor;
	int numcars = log10(MAXcor)+1;
	for (i = 0; i < L; i++){
		for (j = 0; j < C; j++){
			scanf("%u", &cor);
			
			pix.r = (unsigned char)cor;
			scanf("%u", &cor);
			
			pix.g = (unsigned char)cor;
			scanf("%u", &cor);
			
			pix.b = (unsigned char)cor;
			linha[j] = pix;
		}
		for (k = C-1; k > -1; k--){
			num = linha[k].r;
     			printf("%*d ", numcars, num);
			num = linha[k].g;
	     		printf("%*d ", numcars, num);
			num = linha[k].b;
			printf("%*d", numcars, num);
			contC++;
			if (contC == C){
				printf("%c", '\n');
				contC = 0;
			}
			else
				printf("%3c", ' ');
		}
	}
}

/*							    */
/*				PADRAO			    */
/*							    */
void padrao(int M, int N){
	int m, n, c, l, i, j;
	unsigned int cor;
	Pixel matriz[MAXNM][MAXNM];
	int numcars = log10(MAXcor)+1;
	for (i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			scanf("%u", &cor);
			
			matriz[i][j].r = (unsigned char)cor;
			scanf("%u", &cor);
			
			matriz[i][j].g = (unsigned char)cor;
			scanf("%u", &cor);
			
			matriz[i][j].b = (unsigned char)cor;
			
		}
	}
	for(m = 0; m<M; m++){
		for(l = 0; l < L; l++){
			for(n = 0; n<N; n++){
				for(c = 0; c < C; c++){
					printf("%*d ", numcars, matriz[l][c].r);	
			     	printf("%*d ", numcars, matriz[l][c].g);
					printf("%*d", numcars, matriz[l][c].b);
					if (c != C-1 || n != N-1)
						printf("   ");
					else if (c == C-1 && n == N-1)
						printf("\n");
				}	
			}
		}
	}		
}




/*							    */
/*				MAIN			    */
/*							    */
int main(int argc, char *argv[]){	
	char comentario[MAXCHAR];
	switch(argv[1][0]) {
	case 'n':{
		strcpy(comentario, "# negativo");
		cabecalho(comentario, 1, 1);
		negativo();
		break;
	}
	 case 'e':{
	 	strcpy(comentario, "# espelho");
		cabecalho(comentario, 1, 1);
		espelho();
		break;
	}
	case 'p':{
		strcpy(comentario, "# padrao ");
		strcat(comentario, argv[2]);
		strcat(comentario, "x");
		strcat(comentario, argv[3]);
		cabecalho(comentario, atoi(argv[2]), atoi(argv[3]) );
		padrao(atoi(argv[2]), atoi(argv[3]));
		break;
	}
 }	
	return 0;
}


