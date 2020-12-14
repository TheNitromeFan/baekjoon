#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool triangle(vector<long long> &v, int n){
	for(int i = 0; i + 3 <= n; ++i){
		if(v[i + 2] < v[i] + v[i + 1]){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << (triangle(v, n) ? "possible" : "impossible");
	return 0;
}
