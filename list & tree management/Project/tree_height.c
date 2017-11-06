int tree_height(tree_node *t)
{
	int l, r;
	if (t == NULL) return 0;
	l = tree_height(t->left);
	r = tree_height(t->right);
	return (l > r ? l:r)+1;
}
