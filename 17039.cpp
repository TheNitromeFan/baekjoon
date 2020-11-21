#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sliding_window(vector<int> &v, int n){
	if((v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2)
	|| (v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2)){
		return 2;
	}
	int ret = 0, end = 0;
	for(int start = 0; start < n; ++start){
		while(end < n - 1 && v[end + 1] - v[start] <= n - 1){
			++end;
		}
		ret = max(ret, end - start + 1);
	}
	return n - ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 3;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans_max = max(v[n - 2] - v[0], v[n - 1] - v[1]) - (n - 2);
	int ans_min = sliding_window(v, n);
	cout << ans_min << '\n' << ans_max;
	return 0;
}
