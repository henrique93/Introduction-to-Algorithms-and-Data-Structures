#include "funcoes.h"

/*		         aux.c				    */
/* Ficheiro que inclui as funcoes auxiliares as funcoes do  */
/*		programa principal			    */



/*							    */
/*			newLink				*/
/*							    */
/* Cria um novo node(item e ponteiro para proximo node).    */
link newlink(char *emissor,char *hashtag, char *bitaite) {
	link novo = (link) malloc(sizeof(struct node));
	novo -> item = (Item)malloc(sizeof(struct mensagem));
	strcpy(novo -> item -> user, emissor);
	strcpy(novo -> item -> hashtag, hashtag);
	strcpy(novo -> item -> bitaite, bitaite);
	novo -> next = NULL;
	return novo;
}


/*							    */
/*			showLink			*/
/*							    */
/* Mostra um bitaite associado a um hashtag.		    */
void showlink (link x) {
	printf("%s ", x -> item -> user);
	printf("%s : ", x -> item -> hashtag);
	printf("%s", x -> item -> bitaite);
}


/*							    */
/*			deleteLink			*/
/*							    */
/* Destroi todos os valores do link recebido.		    */
void deleteLink (link x) {
	free(x -> item);
	free(x);
}


/*							    */
/*			insertEnd			*/
/*							    */
/* Insere um link como ultimo elemento da struct bitaite.   */
void insertEnd(queue_ptr list, link bitaite) {
	if(list -> begin == NULL){
		list -> begin = bitaite;
		list -> end = bitaite;
	}
	else {
		list -> end -> next = bitaite;
		list -> end = bitaite;
	}
	list -> cont++;
}


/*							    */
/*			deleteBitaite		*/
/*							    */
/* Apaga um bitaite associado a um hashtag.		    */
void deleteBitaite(queue_ptr list) {
	link aux = list -> begin;
	list -> begin = list -> begin -> next;
	deleteLink(aux);
	list -> cont--;
}


/*							    */
/*			deleteHashtag		*/
/*							    */
/* Apaga todos os bitaite associado a um hashtag.	    */
void deleteHashtag(queue_ptr list) {
	while (list -> begin != NULL) {
		deleteBitaite(list);
	}
}


/*							    */
/*			hash				*/
/*							    */
/* Funcao de dispersao	    */
int hash(char *v, int M) {
	int h = 0, a = 127;
	for (; *v != '\0'; v++)
		h = (a*h + *v) % M;
	return h;
}


int hashtwo(char *v, int M) {
	int h = 1 + 3 * M;
	return h;
}