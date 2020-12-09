#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int square(int x){
	return x * x;
}

bool touch(vector<tuple<int, int, int>> &v, int i, int j){
	return square(get<0>(v[i]) - get<0>(v[j])) + square(get<1>(v[i]) - get<1>(v[j]))
	<= square(get<2>(v[i]) + get<2>(v[j]));
}

void visit(vector<tuple<int, int, int>> &a, vector<bool> &visited, int n, int u){
	visited[u] = true;
	for(int v = 0; v < n; ++v){
		if(!visited[v] && touch(a, u, v)){
			visit(a, visited, n, v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<tuple<int, int, int>> a(n);
		for(int i = 0; i < n; ++i){
			cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
		}
		vector<bool> visited(n);
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(!visited[i]){
				++cnt;
				visit(a, visited, n, i);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
