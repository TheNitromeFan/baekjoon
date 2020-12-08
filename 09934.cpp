#include <iostream>

using namespace std;

void traverse(int tree[2000], int a[2000], int k, int level, int pos, int &idx){
	if(level == k){
		tree[pos] = a[idx];
		++idx;
		return;
	}
	traverse(tree, a, k, level + 1, 2 * pos, idx);
	tree[pos] = a[idx];
	++idx;
	traverse(tree, a, k, level + 1, 2 * pos + 1, idx);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	int a[2000];
	for(int i = 0; i < (1 << k) - 1; ++i){
		cin >> a[i];
	}
	int tree[2000];
	int idx = 0;
	traverse(tree, a, k, 1, 1, idx);
	for(int level = 0; level < k; ++level){
		for(int i = 0; i < (1 << level); ++i){
			cout << tree[(1 << level) + i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
