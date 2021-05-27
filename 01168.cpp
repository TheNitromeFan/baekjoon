#include <iostream>
#define MAX (1 << 18)

using namespace std;

int segtree[MAX];

int initialize(int node, int s, int e){
	if(s == e){
		segtree[node] = 1;
		return 1;
	}
	int mid = (s + e) / 2;
	segtree[node] = initialize(2 * node, s, mid) + initialize(2 * node + 1, mid + 1, e);
	return segtree[node];
}

int update(int node, int s, int e, int del){
	--segtree[node];
	if(s == e){
		return 0;
	}
	int mid = (s + e) / 2;
	if(del <= mid){
		return update(2 * node, s, mid, del);
	}else{
		return update(2 * node + 1, mid + 1, e, del);
	}
}

int query(int node, int s, int e, int k){
	if(s == e){
		return s;
	}
	int mid = (s + e) / 2;
	if(k <= segtree[2 * node]){
		return query(2 * node, s, mid, k);
	}else{
		return query(2 * node + 1, mid + 1, e, k - segtree[2 * node]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	initialize(1, 1, n);
	int idx = 1;
	cout << '<';
	for(int i = 0; i < n; ++i){
		int sz = n - i;
		idx += k - 1;
		idx %= sz;
		if(idx == 0){
			idx = sz;
		}
		int m = query(1, 1, n, idx);
		update(1, 1, n, m);
		cout << m;
		if(i < n - 1){
			cout << ',' << ' ';
		}
	}
	cout << '>';
	return 0;
}
