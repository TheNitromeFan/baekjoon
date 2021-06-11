#include <iostream>
#include <queue>
#define MAX 200001

using namespace std;

bool fill_ancestors(int heap[MAX], bool used[MAX], int n, int k, int p){
	heap[p] = k;
	used[k] = true;
	while(p > 1){
		p /= 2;
		--k;
		if(k == 0){
			return false;
		}
		heap[p] = k;
		used[k] = true;
	}
	return true;
}

bool fill_descendants(int heap[MAX], bool used[MAX], int n, int k, int p){
	queue<int> q;
	if(2 * p <= n){
		q.push(2 * p);
	}
	if(2 * p + 1 <= n){
		q.push(2 * p + 1);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++k;
		if(k > n){
			return false;
		}
		heap[u] = k;
		used[k] = true;
		if(2 * u <= n){
			q.push(2 * u);
		}
		if(2 * u + 1 <= n){
			q.push(2 * u + 1);
		}
	}
	return true;
}

void fill_rest(int heap[MAX], bool used[MAX], int n){
	int x = 1;
	while(x <= n && used[x]){
		++x;
	}
	for(int pos = 1; pos <= n; ++pos){
		if(heap[pos]){
			continue;
		}
		heap[pos] = x;
		used[x] = true;
		++x;
		while(x <= n && used[x]){
			++x;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, p;
	cin >> n >> k >> p;
	int heap[MAX] = {};
	bool used[MAX] = {};
	if(!fill_ancestors(heap, used, n, k, p)){
		cout << -1;
		return 0;
	}
	if(!fill_descendants(heap, used, n, k, p)){
		cout << -1;
		return 0;
	}
	fill_rest(heap, used, n);
	for(int i = 1; i <= n; ++i){
		cout << heap[i] << '\n';
	}
	return 0;
}
