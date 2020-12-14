#include <iostream>
#include <vector>

using namespace std;

int ads(vector<int> &c, vector<int> &b, vector<bool> &allowed, int n, int k){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		if(allowed[c[i] - 1] && b[c[i] - 1] <= k){
			++ret;
			k -= b[c[i] - 1];
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> b(6);
	for(int i = 0; i < 6; ++i){
		cin >> b[i];
	}
	vector<int> c(n);
	for(int j = 0; j < n; ++j){
		cin >> c[j];
	}
	int ans = 0;
	for(int x = 0; x < (1 << 6); ++x){
		vector<bool> allowed(6);
		int y = x;
		for(int i = 0; i < 6; ++i){
			if(y % 2 == 1){
				allowed[i] = true;
			}
			y /= 2;
		}
		int cmp = ads(c, b, allowed, n, k);
		if(ans < cmp){
			ans = cmp;
		}
	}
	cout << ans;
	return 0;
}
