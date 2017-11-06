
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
