#include <cstdio>

using namespace std;

class Node{
	public:
		int val;
		int count;
		Node *left;
		Node *right;
		
		Node(int num1, int num2){
			val = num1;
			count = num2;
			left = NULL;
			right = NULL;
		}
		
};

int addNode(Node*& root, int value, int less){
	if(root == NULL){
		root = new Node(value, 0);
		return less;
	}
	if(root->val < value){
		return root->count + addNode(root->right, value, less + 1);
	}else{
		++root->count;
		return addNode(root->left, value, less);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	Node* root = NULL;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		printf("%d\n", addNode(root, x, 0));
	}
	return 0;
}
