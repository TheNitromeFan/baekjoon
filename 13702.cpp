#include <iostream>
#include <vector>

using namespace std;

long long servings(vector<long long> &wine, int n, int size){
	long long ret = 0;
	for(int i = 0; i < n; ++i){
		ret += wine[i] / size;
	}
	return ret;
}

long long serve(vector<long long> &wine, int n, int k){
	long long low = 1, high = 1LL << 32;
	while(low < high){
		long long mid = (low + high) / 2;
		if(servings(wine, n, mid) >= k){
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
	vector<long long> wine(n);
	for(int i = 0; i < n; ++i){
		cin >> wine[i];
	}
	cout << serve(wine, n, k);
	return 0;
}
