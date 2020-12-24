#include <iostream>
#include <vector>

using namespace std;

int minimum_days(vector<int> &a, int x){
	int ret = 7;
	for(int i = 0; i < 7; ++i){
		int j = i;
		int cnt = 0, cmp = 0;
		while(cnt < x){
			if(a[j] == 1){
				++cnt;
			}
			j = (j + 1) % 7;
			++cmp;
		}
		if(ret > cmp){
			ret = cmp;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int k;
		cin >> k;
		vector<int> a(7);
		int d = 0;
		for(int j = 0; j < 7; ++j){
			cin >> a[j];
			d += a[j];
		}
		int q = k / d, r = k % d;
		if(r == 0){
			--q;
			r += d;
		}
		int ans = 7 * q;
		ans += minimum_days(a, r);
		cout << ans << '\n';
	}
	return 0;
}
