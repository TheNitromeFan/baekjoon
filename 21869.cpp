#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n > 1){
		cout << 2 * n - 2 << '\n';
		for(int i = 1; i <= n; ++i){
			cout << 1 << ' ' << i << '\n';
		}
		for(int i = 2; i < n; ++i){
			cout << n << ' ' << i << '\n';
		}
	}else{
		cout << 1 << '\n' << 1 << ' ' << 1 << '\n';
	}
	return 0;
}
