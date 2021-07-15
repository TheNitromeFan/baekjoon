#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if(m >= n - 1 && m <= 2 * n - 3){
		for(int v = 2; v <= n; --m, ++v){
			cout << 1 << ' ' << v << '\n';
		}
		for(int u = 2; m && u <= n - 1; --m, ++u){
			cout << u << ' ' << n << '\n';
		}
	}else{
		cout << -1 << '\n';
	}
	return 0;
}
