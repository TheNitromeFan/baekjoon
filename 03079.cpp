#include <iostream>
#include <vector>

using namespace std;

long long people(vector<long long> &t, int n, long long queue){
	long long ret = 0;
	for(int i = 0; i < n; ++i){
		ret += queue / t[i];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> t(n);
	long long maxT = 0;
	for(int i = 0; i < n; ++i){
		cin >> t[i];
		if(maxT < t[i]){
			maxT = t[i];
		}
	}
	long long low = 0, high = maxT * m;
	long long ans = high;
	while(low <= high){
		long long mid = (low + high) / 2;
		if(people(t, n, mid) >= m){
			ans = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
