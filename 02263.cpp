#include <cstdio>
#define MAX (100000 + 1)

void preorder(int inorder[MAX], int postorder[MAX], int inorder_index[MAX], int instart, int inend, int poststart, int postend){
	if(instart > inend || poststart > postend){
		return;
	}
	int root = postorder[postend];
	printf("%d ", root);
	int pos = inorder_index[root];
	preorder(inorder, postorder, inorder_index, instart, pos - 1, poststart, poststart + pos - instart - 1);
	preorder(inorder, postorder, inorder_index, pos + 1, inend, poststart + pos - instart, postend - 1);
}

int main(){
	int inorder[MAX], postorder[MAX], inorder_index[MAX];
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &inorder[i]);
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &postorder[i]);
	}
	for(int i = 1; i <= n; ++i){
		inorder_index[inorder[i]] = i;
	}
	preorder(inorder, postorder, inorder_index, 1, n, 1, n);
	return 0;
}
