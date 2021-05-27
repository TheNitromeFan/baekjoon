#include <iostream>
#include <vector>

using namespace std;

long long pieces(vector<int> &a, int p){
	long long ret = 0;
	for(int ai : a){
		ret += ai / p;
	}
	return ret;
}

int binary_search(vector<int> &a, int m){
	int low = 1, high = 2000000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(pieces(a, mid) >= m){
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
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> a;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x >= 2 * k){
			a.push_back(x - 2 * k);
		}else if(x > k){
			a.push_back(x - k);
		}
	}
	int ans = binary_search(a, m);
	cout << (ans ? ans : -1);
	return 0;
}
