#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p;
	cin >> p;
	for(int a0 = 0; a0 < p; ++a0){
		int k;
		cin >> k;
		int prev;
		cin >> prev;
		int ans = 0;
		for(int i = 1; i < 15; ++i){
			int cur;
			cin >> cur;
			if(cur < prev){
				++ans;
			}
			prev = cur;
		}
		cout << k << ' ' << ans << '\n';
	}
	return 0;
}
