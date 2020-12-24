#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long max_circ(vector<long long> &l, int n, long long sum){
	for(int i = n - 1; i >= 2; --i){
		if(sum - l[i] > l[i]){
			return sum;
		}
		sum -= l[i];
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int n;
		cin >> n;
		vector<long long> l(n);
		long long sum = 0;
		for(int j = 0; j < n; ++j){
			cin >> l[j];
			sum += l[j];
		}
		sort(l.begin(), l.end());
		cout << max_circ(l, n, sum) << '\n';
	}
	return 0;
}
