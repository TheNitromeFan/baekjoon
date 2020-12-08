#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << n / 2 + m / 2;
	for(int i = 2; i <= n; i += 2){
		cout << '\n' << i << ' ' << 1 << ' ' << i << ' ' << m;
	}
	for(int j = 2; j <= m; j += 2){
		cout << '\n' << 1 << ' ' << j << ' ' << n << ' ' << j;
	}
	return 0;
}
