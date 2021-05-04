#include <iostream>
#define MAX 1000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	static int a[MAX][MAX];
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	cout << m << '\n';
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[(i + j) % m][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
