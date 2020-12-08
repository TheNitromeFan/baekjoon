#include <iostream>
#include <vector>

using namespace std;

int count_draws(vector<int> &d, int n, int amt){
	int ret = 0;
	int cur = 0;
	for(int i = 0; i < n; ++i){
		if(cur < d[i]){
			++ret;
			cur = amt;
		}
		cur -= d[i];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	int maxD = 0, sumD = 0;
	for(int i = 0; i < n; ++i){
		cin >> d[i];
		if(maxD < d[i]){
			maxD = d[i];
		}
		sumD += d[i];
	}
	int low = maxD, high = sumD;
	int k = high;
	while(low <= high){
		int mid = (low + high) / 2;
		if(count_draws(d, n, mid) <= m){
			k = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	cout << k;
	return 0;
}
