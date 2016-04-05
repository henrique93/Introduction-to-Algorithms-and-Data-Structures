/**********************************/
/*         Grupo 005              */
/*   Maria Serralha nº 78661      */
/*	 Vilma Neves nº 78699         */
/*	 Henrique Lourenco nº 77459   */
/*                                */
/**********************************/

#include "funcoes.h"

/*							    */
/*				MAIN			*/
/*							    */
int main(void) {
	int maxHashtags;
	char command[CMDCHAR] = "";
	chat* hashtable;
	scanf("%d",&maxHashtags);
	maxHashtags = maxHashtags * 5;
	hashtable = (chat*)calloc(sizeof(chat), maxHashtags);
	while(strcmp(command,"quit")) {
		scanf("%s",command);
		if(!strcmp(command,"send")) {
			sendBitaite(maxHashtags, hashtable); /* Recebe o ponteiro para filas */
		}
		else if(!strcmp(command,"list")) {
			list(maxHashtags, hashtable); /* Recebe o ponteiro para filas */
		}
		else if(!strcmp(command,"close")) {
			close(maxHashtags, hashtable); /* Recebe o ponteiro para filas */
		}
		else if(!strcmp(command,"quit")) {
			quit(maxHashtags, hashtable); /* Recebe o ponteiro para filas */
		}
		else {
			printf("ERROR: Unknown command\n");
		}
	} 
	return 0;
}
