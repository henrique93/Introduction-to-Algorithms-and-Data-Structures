#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define USERCHAR 21 /* Maximo de caracteres, nao brancos, que 			       o nome do utilizador pode ter */

#define BITAITECHAR 201 /* Maximo de caracteres que o bitaite 				   pode conter (incluindo espacos) */

#define HASHTAGCHAR 41 /* Maximo de caracteres, nao brancos, 				  que o hashtag pode ter */

#define CMDCHAR 6 /* Maximo de caracteres que o comando pode 			     conter */


/*							    */
/*			ESTRUTURAS			*/
/*							    */
/* Estrutura de mensagens que contem o emissor, o hashtag e
		a mensagem a enviar			    */
typedef struct mensagem {
	char user[USERCHAR];
	char hashtag[HASHTAGCHAR];
	char bitaite[BITAITECHAR];
	} *Item;



/* Estrutura de node que contem um item e um ponteiro para
		o proximo node				    */
typedef struct node {
	Item item;
	struct node *next;
	} *link;


/* Estrutura queue que contem o inicio da lista(begin), o
		fim da lista(end) e um contador que guarda
		o numero de elementos na lista(cont)	    */
typedef struct queue{
	link begin;
	link end;
	int cont;
} *queue_ptr;


typedef struct chat {
	queue_ptr fila;
	char* key;
} chat;

/*			DECLARACAO DE			    */
/*		FUNCOES UTILIZADAS PELA MAIN	*/
/*							    		*/
void sendBitaite(int maxHashtags, chat* hashtable);
void list(int maxHashtags, chat* hashtable);
void close(int maxHashtags, chat* hashtable);
void quit(int maxHashtags, chat* hashtable);


/*			DECLARACAO DE			    */
/*		     FUNCOES AUXILIARES 		*/
/*							    		*/
link newlink(char* user,char* hashtag, char* bitaite);
void showlink(link x);
void deletelink(link x);
void insertEnd(queue_ptr list, link text);
void deleteBitaite(queue_ptr list);
void deleteHashtag(queue_ptr list);
int hash(char *v, int M);
int hashtwo(char *v, int M);

#endif