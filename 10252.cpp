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
		cout << 1 << '\n';
		if(m % 2 == 0){
			for(int i = 0; i < m; ++i){
				if(i % 2 == 0){
					for(int j = 0; j < n; ++j){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}else{
					for(int j = n - 1; j >= 0; --j){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}
			}
		}else if(n % 2 == 0){
			for(int j = 0; j < n; ++j){
				if(j % 2 == 0){
					for(int i = 0; i < m; ++i){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}else{
					for(int i = m - 1; i >= 0; --i){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}
			}
		}else{
			for(int j = 0; j < n; ++j){
				cout << '(' << 0 << ',' << j << ')' << '\n';
			}
			for(int j = n - 1; j >= 0; --j){
				if(j % 2 == 0){
					for(int i = 1; i < m; ++i){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}else{
					for(int i = m - 1; i > 0; --i){
						cout << '(' << i << ',' << j << ')' << '\n';
					}
				}
			}
		}
	}
	return 0;
}
