#include <iostream>

using namespace std;

int a[1000000];
long long cnt[1000];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		a[i] %= m;
	}
	int sum = 0;
	cnt[0] = 1;
	for(int i = 0; i < n; ++i){
		sum = (sum + a[i]) % m;
		cnt[sum] += 1;
	}
	long long ans = 0;
	for(int j = 0; j < m; ++j){
		ans += cnt[j] * (cnt[j]-1) / 2;
	}
	cout << ans;
	return 0;
}
