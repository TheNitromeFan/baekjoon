#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long k;
	cin >> k;
	vector<vector<int>> level(100000);
	level[0].push_back(0);
	long long max_level = 0;
	int n = 1;
	while(k > 0){
		long long i = min(k, max_level + 1);
		k -= i;
		level[i].push_back(n);
		++n;
		max_level = max(max_level, i);
	}
	cout << n << '\n';
	for(int i = 0; i <= max_level; ++i){
		for(int x : level[i]){
			cout << x << ' ';
			if(i == 0){
				cout << -1 << '\n';
			}else{
				cout << level[i - 1][0] << '\n';
			}
		}
	}
	return 0;
}
