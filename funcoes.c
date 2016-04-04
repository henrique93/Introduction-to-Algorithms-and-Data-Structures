#include "funcoes.h"

/*			funcoes.c			   */
/*   Contem todas as funcoes utilizadas pela funcao main   */
/*							   */



/*							    */
/*			    SEND			*/
/*							    */
/* regista  um bitaite e associa-o a um hashtag */
void sendBitaite(int maxHashtags, chat* hashtable) {
	char user[USERCHAR], hashtag[HASHTAGCHAR], bitaite[BITAITECHAR];
	link x;
	int index;
	scanf("%s", user);
	scanf("%s", hashtag);
	getchar();
	fgets(bitaite,BITAITECHAR,stdin);
	x = newlink(user, hashtag, bitaite);
	index = hash(hashtag, maxHashtags);
	if (hashtable[index].fila == NULL)
		hashtable[index].fila = calloc(sizeof(struct queue),1);
	else {
		while (hashtable[index].fila != NULL) {
			if (strcmp(hashtable[index].fila -> begin -> item -> hashtag, hashtag))
				index += hashtwo(hashtag, maxHashtags) % maxHashtags;
			else
				break;
		}
		if (hashtable[index].fila == NULL)
			hashtable[index].fila = calloc(sizeof(struct queue), 1);
	}
	insertEnd(hashtable[index].fila, x);
}


/*							    */
/*			    LIST			*/
/*							    */
/* Imprime todos os bitaites associados a um determinado
		hashtag					    */
void list(int maxHashtags, chat* hashtable) {
	int i, index;
	char hashtag[HASHTAGCHAR];
	link node;
	scanf("%s", hashtag);
	index = hash(hashtag, maxHashtags);
	if (hashtable[index].fila == NULL)
		printf("NULL\n");
	else {
		node = hashtable[index].fila -> begin;
		if (node == NULL)
			printf("NULL\n");
		else {
			while (strcmp(node -> item -> hashtag, hashtag))
				index += hashtwo(hashtag, maxHashtags) % maxHashtags;
			for (i = 0; i < hashtable[index].fila -> cont; i++){
				showlink(node);
				node = node -> next;
			}
		}
	}
}


/*							    */
/*			    CLOSE			*/
/*							    */
/* Apaga os bitaites de um determinado hashtag caso seja o 		utilizador em questao seja o criador do hashtag     */
void close(int maxHashtags, chat* hashtable) {
    int index;
	char emissor[USERCHAR], hashtag[HASHTAGCHAR];
	scanf("%s", emissor);
	scanf("%s", hashtag);
	/* A partir daqui e preciso encontrar a fila coorrespondente ao hashtag
	ver se o emissor do primeiro bitaite coorresponde ao emissor scanado e
	se sim, apahar a fila toda */
	index = hash(hashtag, maxHashtags);
	if (hashtable[index].fila == NULL) { }
	else {
		while (strcmp(hashtable[index].fila -> begin -> item -> hashtag, hashtag))
			index = hashtwo(hashtag, maxHashtags) % maxHashtags;
		if (!strcmp(emissor, hashtable[index].fila -> begin -> item -> user)) {
			deleteHashtag(hashtable[index].fila);
			free(hashtable[index].fila);
			hashtable[index].fila = NULL;
		}
	}
}


/*							    */
/*			    QUIT			    */
/*							    */
/* Apaga todos os hashtags e bitaites associados 	    */
void quit(int maxHashtags, chat* hashtable) {
	int i;
	for (i = 0; i < maxHashtags; i++) {
		if (hashtable[i].fila != NULL)
			deleteHashtag(hashtable[i].fila);
	}
	free(hashtable);
}