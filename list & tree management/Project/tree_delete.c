void tree_delete(tree_node *t)
{
	if (t == NULL) return;
	tree_delete(t->left);
	tree_delete(t->right);
	free(t);
}
