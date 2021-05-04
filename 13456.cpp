#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> u(n), v(n);
		for(int i = 0; i < n; ++i){
			cin >> u[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		int dist = 0;
		for(int i = 0; i < n; ++i){
			if(u[i] != v[i]){
				++dist;
			}
		}
		cout << dist << '\n';
	}
	return 0;
}
