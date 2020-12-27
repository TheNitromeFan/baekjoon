#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> degrees(n + 1, 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		++degrees[u];
		++degrees[v];
	}
	int ans = 0;
	for(int v = 1; v <= n; ++v){
		if(ans < degrees[v]){
			ans = degrees[v];
		}
	}
	cout << ans;
	return 0;
}
