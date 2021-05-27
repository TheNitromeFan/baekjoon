#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int a0 = 0; a0 < z; ++a0){
		int n, k;
		cin >> n >> k;
		vector<long long> t(n);
		for(int i = 0; i < n; ++i){
			cin >> t[i];
		}
		sort(t.begin(), t.end(), greater<long long>());
		long long gold = 0;
		for(int i = k; i < n; ++i){
			gold += t[i];
		}
		cout << max(gold, t[0]) << '\n';
	}
	return 0;
}
