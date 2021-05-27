#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		ans = min(ans + 1, x);
		cout << ans << ' ';
	}
	return 0;
}
