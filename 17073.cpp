#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	vector<int> degree(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		++degree[u];
		++degree[v];
	}
	int leaves = 0;
	for(int u = 2; u <= n; ++u){
		if(degree[u] == 1){
			++leaves;
		}
	}
	cout << fixed << setprecision(6) << w / (double)leaves;
	return 0;
}
