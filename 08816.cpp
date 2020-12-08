#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int n;
		cin >> n;
		int ans = 1;
		for(int j = n - 1; j >= 1; j -= 2){
			ans *= j;
			ans %= 1000;
		}
		cout << ans << '\n';
	}
	return 0;
}
