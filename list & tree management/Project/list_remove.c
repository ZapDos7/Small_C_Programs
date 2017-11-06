void list_remove(list_node **ll)
{
	list_node* l = *ll;
	*ll = l->next;
	free(l);
}
