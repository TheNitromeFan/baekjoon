#include <iostream>

using namespace std;

bool win(long long x, long long z, long long v, long long vn){
	return v * (vn + x - z) < vn * x;
}

long long min_boost(long long x, long long y, long long v, long long vn){
	long long low = 1, high = y;
	while(low < high){
		long long mid = (low + high) / 2;
		if(win(x, mid, v, vn)){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		long long x, y;
		cin >> n >> x >> y;
		long long v = 0;
		for(int i = 0; i < n - 1; ++i){
			long long vi;
			cin >> vi;
			if(v < vi){
				v = vi;
			}
		}
		long long vn;
		cin >> vn;
		if(vn > v){
			cout << 0 << '\n';
		}else if(!win(x, y, v, vn)){
			cout << -1 << '\n';
		}else{
			cout << min_boost(x, y, v, vn) << '\n';
		}
	}
	return 0;
}
