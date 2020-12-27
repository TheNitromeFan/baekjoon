#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int launches(vector<int> &x, int n, int r){
	int ret = 0;
	int pos = -2000000000;
	for(int i = 0; i < n; ++i){
		if(x[i] > pos + r){
			++ret;
			pos = x[i] + r;
		}
	}
	return ret;
}

int minimum_radius(vector<int> &x, int n, int k){
	int low = 1, high = 1000000001;
	while(low < high){
		int mid = (low + high) / 2;
		if(launches(x, n, mid) <= k){
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
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	cout << minimum_radius(x, n, k);
	return 0;
}
