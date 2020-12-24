#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_difference(vector<int> &v, int n){
	int ret = v[0];
	for(int i = 0; i + 1 < n; ++i){
		ret = max(ret, v[i + 1] - v[i]);
	}
	return ret;
}

bool play(vector<int> &v, int n, int d){
	if(v[1] <= d){
		return false;
	}
	for(int i = 0; i + 2 < n; ++i){
		if(v[i + 2] - v[i] <= d){
			return false;
		}
	}
	return true;
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
	int d = max_difference(v, n);
	cout << (play(v, n, d) ? d : 0);
	return 0;
}
