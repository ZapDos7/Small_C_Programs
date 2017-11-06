void tree_print(tree_node *t)
{
	if (t == NULL) return;
	tree_print(t->left);
	printf("%d\n", t->data);
	tree_print(t->right);
{
