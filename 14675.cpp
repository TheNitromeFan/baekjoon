#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> degree(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		++degree[u];
		++degree[v];
	}
	int q;
	cin >> q;
	for(int j = 0; j < q; ++j){
		int t, k;
		cin >> t >> k;
		if(t == 1){
			cout << (degree[k] > 1 ? "yes" : "no");
		}else{
			cout << "yes";
		}
		cout << '\n';
	}
	return 0;
}
