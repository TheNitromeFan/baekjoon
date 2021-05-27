#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool wire(vector<long long> &v, int n){
	sort(v.begin(), v.end());
	long long sum = v[0];
	for(int i = 1; i < n; ++i){
		if(sum >= v[i]){
			return true;
		}
		sum += v[i];
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 0; a0 < k; ++a0){
		int n;
		cin >> n;
		vector<long long> v(n);
		for(int i = 0; i < n; ++i){
			double x;
			cin >> x;
			v[i] = (long long)(x * 1000);
		}
		cout << (wire(v, n) ? "YES" : "NO") << '\n';
	}
	return 0;
}
