#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int list_count(list_node* l, int x)   /*metraw poses fores exw tn akeraio x sth lista m*/
{
	int cnt = 0;            /*arxikopoihsh metrhth*/
	while (l != NULL) {         /*As long as o deikths m dn deixnei se NULL*/
		if (l->data == x)       /*An auto pou deixnei o deikths einai o x, */
			cnt++;              /*tote au3hse to metrhth kata ena*/
		l = l->next;            /*metakinhse to deikth sto epomeno stoixeio ths listas*/
	}
	return cnt;             /*epestrepse to metrhth*/
}

int list_search(list_node *l, int x)    /*anazhthsh tou akeraiou x sth lista m*/
{
	while (l != NULL) {             /*As long as o deikths m dn deixnei se NULL*/
		if (l->data == x)           /*An auto pou deixnei o deikths einai o x, */
			return 1;           /*tote to vrhkame (pame na fugoume)*/
		l = l->next;            /*metakinhse to deikth ston epono komvo ths listas*/
	}
	return 0;           /*an telika de to vroume, epistrefoume 0*/
}

void list_insert_at_start(list_node** ll, int x)
{	
	list_node* temp;        /*To temp einai deikths se domh tupou list_node*/
	temp = malloc(sizeof(struct list_node));    /*Desmeuw thn apaitoumenh mnhmh gia th domh*/
	temp->next = *ll;           /*to next tou temp 8a einai o deikths ston opoio deixnei o deikths ths main mas*/
	temp->data = x;     /*to data 8a einai to stoixeio pou 8eloume na eisagoume dld to x*/
	*ll = temp; /*to temp einai deikths pou deixnei sth nea mas lista, auton ton metaferoume sto deikth ths main*/
}

void list_remove_first_node(list_node **ll)     /*diagrafh prwtou komvou*/
{
	list_node* temp = *ll;      /*Estw temp deikths pou deixnei sth lista mas*/
	*ll = temp->next;           /*metakinw to deikth ths main ston epomeno komvo*/
	free(temp);         /*O temp deixnei sto prwhn arxiko komvo ths listas, opote kai ton kanoume free*/
}

int tree_search(tree_node* t ,int x)    /*anazhthsh stoixeiou sto dentro (pernw to deikth tou dentrou kai to stoixeio pou psaxnw*/
{
	while(t != NULL)            /*Oso o deikths de deixnei se NULL, dld oso exoume stoixeia na psa3oume*/
		if (x < t->data)        /*Ean to stoixeio pou psaxnoume einai mikrotero apo to trexon stoixeio*/
			t = t->left;        /*tote metakinhse to deikth sto aristero paidi*/
		else if (x > t->data)   /*alliws an to stoixeio pou psaxnoume einai megalutero apo to trexon stoixeio*/
			t = t->right;       /*tote metakinhse to deikth sto deksio paidi*/
		else                    /*alliws*/
			return 1;           /*profanestata vrhkame to stoixeio pou psaxnoume (epituxia)*/
	return 0;                   /*An de to vroume, tote dn uparxei (apotuxia)*/
}

void tree_delete(tree_node *t)      /*Diagrafh oloklhrou tou dentrou*/
{
	if (t == NULL) return;
	tree_delete(t->left);       /*diegrapse to aristero paidi*/
	tree_delete(t->right);      /*diegrapse to de3i paidi*/
	free(t);                    /*diegrapse to komvo (o opoios de prepei na exei kanena paidi*/
}

int tree_height(tree_node *t)           /*Ypologismos tou upsous tou dentrou*/
{
	int l, r;                           /*l=left, r=right*/
	if (t == NULL) return 0;            /*An o deikths tou dentrou deixnei se NULL, epestrepse 0*/
	l = tree_height(t->left);           /*upologise to upsos tou aristerou paidiou*/
	r = tree_height(t->right);          /*upologise to upsos tou de3iou paidiou*/
	return (l > r ? l:r)+1;             /*epestrepse to pshlotero apo ta 2 paidia + 1(o goneas)*/
}

int tree_size(tree_node *t)             /*plh8os komvwn*/
{
	int l, r;                           /*l=left, r=right*/
    if (t == NULL) return 0;            /*Ean dexnw se NULL, epestrepse 0*/
	l = tree_size(t->left);             /*upologise plh8os komvwn tou aristerou paidiou*/
	r = tree_size(t->right);            /*upologise plh8os komvwn tou de3iou paidiou*/
	return l + r + 1;                   /*epestrepse plh8os komvwn tou aristerou kai tou de3iou paidiou + 1(goneas)*/
}

void tree_print(tree_node *t)           /*ektupwsh tou dentrou*/
{
	if (t == NULL) return;              /*Ean deixnw se NULL epestrepse sth sunarthsh pou me kalese*/
	tree_print(t->left);                /*ektupwse to aristero paidi*/
	printf("%d\n", t->data);            /*ektupwse to gonea*/
	tree_print(t->right);               /*ektupwse to de3io paidi*/
}

void tree_insert(tree_node **tt, int x)
{
	while (*tt != NULL){                /*Oso o deikths de deixnei se NULL*/
 		if (x < (*tt)->data)            /*ean auto pou 8elw na valw sto dentro einai mikrotero tou trexontos komvou*/
			tt = &((*tt)->left);        /*dwse sto deikth th dieu8unsh tou aristerou paidiou*/
		else if (x > (*tt)->data)       /*alliws an auto pou 8elw na valw einai megalutero tou trexontos komvou*/
			tt = &((*tt)->right);       /*dwse sto deikth th dieu8unsh tou de3iou paidiou*/
		else return;}                   /*alliws (an einai isa dld) tote epestrepse ekei ap' opou me kaleses*/
	*tt = malloc(sizeof(tree_node));    /*Afou vrw pou prepei na valw to stoixeio, desmeuw thn apaitoumenh mnhmh*/
	(*tt)->data = x;                    /*o neos komvos 8a einai goneas ston opoio vazw to stoixeio pou 8elw*/
	(*tt)->left = NULL;                 /*to aristero paidi 8a deixnei se NULL*/
	(*tt)->right = NULL;		        /*to idio isxuei kai gia to de3i paidi*/
}


int main(int argc, char *argv[])
{
	int i, tc = 0, lc = 0;          /*i=index, tc=tree_count, lc=list_count*/
	tree_node *t = NULL;            /*arxikopoihsh tou deikth pou deixnei sto dentro se NULL*/
	list_node *l = NULL;            /*arxikopoihsh tou deikth pou deixnei sth lista se NULL*/
	int n = atoi (argv[1]);         /*metatroph tou 1ou orismatos se akeraio n=apo posa stoixeia 8a apoteleitai h lista kai to dentro*/
	int m = atoi (argv[2]);         /*metatroph tou 2ou orismatos se akeraio m=posa tuxaia stoixeia 8a psa3w*/
	srand ((unsigned int) time(NULL));  /*dinw ws futro to time(NULL) dld ta secs apo 1/1/70 mexri shmera*/
	for (i = 0; i < n; i++)
		list_insert_at_start(&l, rand()%n);  /*gemisma ths listas (dinw dieu8unsh tou deikth pou deixnei sth lista kai enan akeraio [0,n-1]*/
	printf("List insert done!\n");
	for (i = 0; i < n; i++)         /*gemisma tou dentrou me ton idio tropo*/
		tree_insert(&t, rand()%n);
	printf("Tree insert done!\n");
	for (i = 0; i < m; i++)             /*anazhthsh m tuxaiwn stoixeiwn sth lista*/
		if (list_search(l, rand()%n))   /*an vreis kapoio tuxaio stoixeio meta3u [0,n-1] sth lista*/
			lc++;                       /*au3hse to metrhth lc kata ena*/
	printf("list search done!\n");
	printf("Found %d out of %d\n",lc, m);   /*vrhkes osa  exei o metrhths apo ta m  pou epsaxnes*/
	for (i = 0; i < m; ++i)             /*anazhthsh m tuxaiwn stoixeiwn sto dentro*/
		if (tree_search(t,rand()%n))	/*an vreis kapoio tuxaio stoixeio meta3u [0,n-1] sto dentro*/
			tc++;                       /*au3hse to metrhth tc kata ena*/
	printf("tree search done!\n");
	printf("Found %d out of %d\n",lc, m);   /*vrhkes osa  exei o metrhths apo ta m  pou epsaxnes*/
	return 0;
}
