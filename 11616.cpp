#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string number;
	cin >> n >> m >> number;
	long long r = 0, ans = 1;
	for(int i = 0; i + 1 < n; ++i){
		char c = number[i];
		r = r * 10 + (c - '0');
		r %= m;
		if(r == 0){
			ans *= 2;
			ans %= MOD;
		}
	}
	r = r * 10 + (number[n - 1] - '0');
	r %= m;
	if(r == 0){
		cout << ans;
	}else{
		cout << 0;
	}
	return 0;
}
