void tree_insert(tree_node **tt, int x)
{
	while (*tt != NULL)
		if (x < (*tt)->data)
			tt = &((*tt)->left);
		else if (x > (*tt)->data)
			tt = &((*tt)->right);
		else return;
	*tt = malloc(sizeof(tree_node));
	(*tt)->data = x;
	(*tt)->left = NULL;
	(*tt)->right = NULL;
