#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_pack.h"
#include "tree_pack.h"

typedef struct list_node list_node;

struct list_node {          /*Aplws perigrafei th domh (lista)*/
	list_node *next;
	int data;
};

typedef struct tree_node tree_node;

struct tree_node {          /*Aplws perigrafei th domh (dentro)*/
	tree_node *left;
	tree_node *right;
	int data;
};


int main(int argc, char *argv[])
{
	int i, tc = 0, lc = 0;
	tree_node *t = NULL;            /*arxikopoihsh tou deikth pou deixnei sto dentro se NULL*/
	list_node *l = NULL;            /*arxikopoihsh tou deikth pou deixnei sth lista se NULL*/
	int n = atoi (argv[1]);         /*metatroph tou 1ou orismatos se akeraio n*/
	int m = atoi (argv[2]);         /*metatroph tou 2ou orismatos se akeraio m*/
	srand ((unsigned int) time(NULL));  /*dinw ws futro to time(NULL) dld ta secs apo 1/1/70 mexri shmera*/
	for (i = 0; i < n; i++)
		list_insert(&l, rand()%n);  /*gemisma ths listas (dinw dieu8unsh tou deikth pou deixnei sth lista*/
	printf("List insert done!\n");
	for (i = 0; i < n; i++)
		tree_insert(&t, rand()%n);
	printf("Tree insert done!\n");
	for (i = 0; i < m; i++)
		if (list_search(l, rand()%n))
			lc++;
	printf("list search done!\n");
	printf("Found %d out of %d\n",lc, m);
	for (i = 0; i < m; ++i)
		if (tree_search(t,rand()%n))
			tc++;
	printf("list search done!\n");
	printf("Found %d out of %d\n",lc, m);
	return 0;
}
