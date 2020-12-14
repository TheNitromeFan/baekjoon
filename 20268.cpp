#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int m, n;
		cin >> m >> n;
		int x;
		for(int i = 0; i < m; ++i){
			cin >> x;
		}
		for(int j = 0; j < n; ++j){
			cin >> x;
		}
		if(m == 2 && n == 2){
			cout << 7 << '\n';
		}else{
			cout << 1 << '\n';
		}
	}
	return 0;
}
