#include <iostream>
#include <vector>

using namespace std;

long long slices(vector<int> &v, int n, int len){
	long long ret = 0;
	for(int i = 0; i < n; ++i){
		ret += v[i] / len;
	}
	return ret;
}

int onion(vector<int> &v, int n, int m){
	int low = 0, high = 2000000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(slices(v, n, mid) >= m){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int r = onion(v, n, m);
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += v[i];
	}
	ans -= (long long)m * r;
	cout << ans;
	return 0;
}
