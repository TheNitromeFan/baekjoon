#include <iostream>
#include <string>
#define MAX 60

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[MAX][MAX];
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[i][j];
		}
	}
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; ++a0){
		string query;
		int k, val;
		cin >> query >> k >> val;
		if(query == "row"){
			for(int j = 1; j <= m; ++j){
				a[k][j] += val;
			}
		}else{
			for(int i = 1; i <= n; ++i){
				a[i][k] += val;
			}
		}
	}
	int sum = 0, max = -10000000, min = 10000000;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			sum += a[i][j];
			if(a[i][j] > max){
				max = a[i][j];
			}
			if(a[i][j] < min){
				min = a[i][j];
			}
		}
	}
	cout << sum << ' ' << min << ' ' << max;
	return 0;
}
