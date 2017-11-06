void list_insert(list_node** ll, int x)
{
	list_node* n;
	n = malloc(sizeof(struct list_node));
	n->next = *ll;
	n->data = x;
	*ll = n;
}
