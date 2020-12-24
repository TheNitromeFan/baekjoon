#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<long long> &v, int len, long long target){
	int low = 1, high = len;
	while(low <= high){
		int mid = (low + high) / 2;
		if(v[mid] == target){
			return true;
		}else if(v[mid] > target){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m, a, c, x0;
	cin >> n >> m >> a >> c >> x0;
	vector<long long> v(n + 1);
	v[0] = x0;
	for(int i = 1; i <= n; ++i){
		v[i] = (a * v[i - 1] + c) % m;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(binary_search(v, n, v[i])){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
