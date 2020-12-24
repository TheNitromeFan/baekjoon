#include <iostream>
#include <vector>

using namespace std;

int servings(vector<int> &wine, int n, int size){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		ret += wine[i] / size;
	}
	return ret;
}

int serve(vector<int> &wine, int n, int k){
	int low = 1, high = 1000000000;
	while(low < high){
		int mid = (low + high) / 2;
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
	vector<int> wine(n);
	for(int i = 0; i < n; ++i){
		cin >> wine[i];
	}
	cout << serve(wine, n, k);
	return 0;
}
