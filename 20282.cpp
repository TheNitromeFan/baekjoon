#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int payout = 100;
	int ans = payout;
	for(int i = 0; i < n; ++i){
		int c;
		cin >> c;
		payout += c;
		ans = max(ans, payout);
	}
	cout << ans << '\n';
	return 0;
}
