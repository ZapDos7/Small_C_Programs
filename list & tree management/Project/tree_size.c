int tree_size(tree_node *t)
{
	int l, r;
        if (t == NULL) return 0;
        l = tree_size(t->left);
        r = tree_size(t->right);
        return l + r + 1;
}
