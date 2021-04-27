#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int prev = 100000;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cur;
		cin >> cur;
		if(cur > prev){
			ans += cur - prev;
			cur = prev;
		}
		prev = cur;
	}
	cout << ans;
	return 0;
}
