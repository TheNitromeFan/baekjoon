#include <iostream>
#include <vector>
#include <cmath>
#define MAX (65536 + 1)

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void update(vector<int>& tree, int node, int start, int end, int index, int value){
	if(index < start || index > end){
		return;
	}
	if(start == end){
		tree[node] += value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int kth(vector<int>& tree, int node, int start, int end, int k){
	if(start == end){
		return start;
	}else if(k <= tree[node*2]){
		return kth(tree, node * 2, start, (start + end) / 2, k);
	}else{
		return kth(tree, node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	int cnt = (k + 1) / 2;
	vector<int> tree(1 << 18, 0);
	vector<int> a(n+1, 0);
	long long ans = 0ll;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		update(tree, 1, 0, MAX, a[i], 1);
		if(i > k){
			update(tree, 1, 0, MAX, a[i - k], -1);
		}
		if(i >= k){
			ans += kth(tree, 1, 0, MAX, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}
