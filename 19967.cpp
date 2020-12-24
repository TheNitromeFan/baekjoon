#include <iostream>

using namespace std;

int tables(int n, int m){
	return ((n - 1) / 3 + 1) * ((m - 1) / 3 + 1);
}

void fill_map(int n, int m, int k){
	int t = tables(n, m);
	if(k + t > n * m){
		cout << "Impossible";
		return;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(((n % 3 == 0 && i % 3 == 1) || (n % 3 != 0 && i % 3 == 0))
			&& ((m % 3 == 0 && j % 3 == 1) || (m % 3 != 0 && j % 3 == 0))){
				cout << "T";
			}else if(k > 0){
				cout << "h";
				--k;
			}else{
				cout << ".";
			}
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	fill_map(n, m, k);
	return 0;
}
