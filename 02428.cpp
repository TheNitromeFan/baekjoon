#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int highest_index(vector<int> &v, int n, int idx){
	int low = idx + 1, high = n - 1, middle = idx;
	int ret = middle;
	while(low <= high){
		middle = (low + high) / 2;
		if(10 * v[idx] >= 9 * v[middle]){
			low = middle + 1;
			ret = middle;
		}else{
			high = middle - 1;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i + 1 < n; ++i){
		ans += highest_index(v, n, i) - i;
	}
	cout << ans;
	return 0;
}
