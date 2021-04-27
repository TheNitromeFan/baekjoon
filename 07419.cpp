#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long pieces(vector<int> &v, int len){
	long long ret = 0;
	for(int vi : v){
		ret += vi / len;
	}
	return ret;
}

int cable(vector<int> &v, int k){
	int low = 1, high = 1000000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(pieces(v, mid) >= k){
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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		char c;
		cin >> x >> c >> y;
		v[i] = 100 * x + y;
	}
	cout << setprecision(2) << fixed << cable(v, k) / 100.0;
	return 0;
}
