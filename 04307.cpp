#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int len, n;
		cin >> len >> n;
		int a = 0, b = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			int low = min(x, len - x), high = max(x, len - x);
			if(a < low){
				a = low;
			}
			if(b < high){
				b = high;
			}
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}
