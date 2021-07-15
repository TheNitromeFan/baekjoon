#include <iostream>

using namespace std;

int search(int arr[], int x, int n){
	for(int i = 0; i < n; ++i){
		if(arr[i] == x){
			return i;
		}
	}
	return -1;
}

void postorder(int pre[], int in[], int n){
	int root = search(in, pre[0], n);
	if(root != 0){
		postorder(pre + 1, in, root);
	}
	if(root != n - 1){
		postorder(pre + root + 1, in + root + 1, n - 1 - root);
	}
	cout << pre[0] << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		int preorder[1001], inorder[1001];
		for(int i = 0; i < n; ++i){
			cin >> preorder[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> inorder[i];
		}
		postorder(preorder, inorder, n);
		cout << '\n';
	}
	return 0;
}
