#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<long long> rows(n + 1), cols(n + 1);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				int a;
				cin >> a;
				rows[i] += a;
				cols[j] += a;
			}
		}
		for(int a1 = 0; a1 < m; ++a1){
			int r1, c1, r2, c2, val;
			cin >> r1 >> c1 >> r2 >> c2 >> val;
			for(int i = r1; i <= r2; ++i){
				rows[i] += (c2 - c1 + 1) * val;
			}
			for(int j = c1; j <= c2; ++j){
				cols[j] += (r2 - r1 + 1) * val;
			}
		}
		for(int i = 1; i <= n; ++i){
			cout << rows[i] << ' ';
		}
		cout << '\n';
		for(int j = 1; j <= n; ++j){
			cout << cols[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
