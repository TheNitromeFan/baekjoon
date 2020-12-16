#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int flip(int low, int high, int x){
	if(x >= low && x <= high){
		return (low + high) - x;
	}
	return x;
}

int cycle_length(int a1, int a2, int b1, int b2, int x){
	int ret = 0;
	int y = x;
	do{
		y = flip(a1, a2, y);
		y = flip(b1, b2, y);
		++ret;
	}while(x != y);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, a1, a2, b1, b2;
	cin >> n >> k >> a1 >> a2 >> b1 >> b2;
	vector<int> ans(n + 1);
	for(int x = 1; x <= n; ++x){
		int c = cycle_length(a1, a2, b1, b2, x);
		int y = x;
		for(int i = 0; i < k % c; ++i){
			y = flip(a1, a2, y);
			y = flip(b1, b2, y);
		}
		ans[y] = x;
	}
	for(int x = 1; x <= n; ++x){
		cout << ans[x] << '\n';
	}
	return 0;
}
