#include <iostream>
#define MAX 501

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = n * (n - 1) / 2;
	bool edges[MAX][MAX] = {};
	edges[1][n] = true;
	edges[n][1] = true;
	int u = 0;
	for(int i = 0; i < cnt; ++i){
		for(int v = 1; v <= n; ++v){
			if(u != v && !edges[u][v]){
				edges[u][v] = true;
				edges[v][u] = true;
				u = v;
				break;
			}
		}
		cout << 'a' << u << ' ';
	}
	cout << 'a' << 1;
	return 0;
}
