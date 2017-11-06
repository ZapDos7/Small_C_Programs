int tree_search(tree_node* t ,int x)
{
	while(t != NULL)
		if (x < t->data)
			t = t->left;
		else if (x > t->data)
			t = t->right;
		else
			return 1;
	return 0;
}
