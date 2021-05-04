#include <iostream>
#define MAX 15

using namespace std;

bool addition_table(int a[][MAX], int n){
	for(int i1 = 0; i1 < n; ++i1){
		for(int i2 = 0; i2 < i1; ++i2){
			for(int j1 = 0; j1 < n; ++j1){
				for(int j2 = 0; j2 < j1; ++j2){
					if(a[i1][j1] + a[i2][j2] != a[i1][j2] + a[i2][j1]){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 1; a0 <= k; ++a0){
		int n;
		cin >> n;
		int a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a[i][j];
			}
		}
		cout << a0 << ". " << (addition_table(a, n) ? "YES" : "NO") << "\n";
	}
	return 0;
}
