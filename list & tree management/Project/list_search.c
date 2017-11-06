int list_search(list_node *l, int x)    /*anazhthsh tou akeraiou x sth lista m*/
{
	while (l != NULL) {             /*As long as o deikths m dn deixnei se NULL*/
		if (l->data == x)           /*An auto pou deixnei o deikths einai o x, */
			return 1;           /*tote to vrhkame (pame na fugoume)*/
		l = l->next;            /*metakinhse to deikth ston epono komvo ths listas*/
	}
	return 0;           /*an telika de to vroume, epistrefoume 0*/
}
