#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 0; i < m; ++i){
		cout << '\n';
		for(int j = 1; j <= k; ++j){
			cout << j << ' ';
		}
		cout << endl;
		for(int j = 1; j <= n - k; ++j){
			int x;
			cin >> x;
		}
	}
	return 0;
}
