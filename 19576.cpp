#include <iostream>
#include <algorithm>
#define MAX 5000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	int dp[MAX] = {};
	int ans = n;
	for(int i = 0; i < n; ++i){
		for(int j = i; j >= 0; --j){
			if(a[i] % a[j] == 0){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = min(ans, n - dp[i]);
	}
	cout << ans;
	return 0;
}
