#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int fact[11];
	fact[0] = 1;
	for(int i = 1; i <= 10; ++i){
		fact[i] = fact[i - 1] * i;
	}
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 10; i >= 0; --i){
		ans += n / fact[i];
		n %= fact[i];
	}
	cout << ans;
	return 0;
}
