#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<long long> max_dist(n);
	for(int i = 0; i < n; ++i){
		int p;
		cin >> p;
		long long cmp = 0;
		for(int j = 0; j < p; ++j){
			long long x, y;
			cin >> x >> y;
			if(cmp < x * x + y * y){
				cmp = x * x + y * y;
			}
		}
		max_dist[i] = cmp;
	}
	sort(max_dist.begin(), max_dist.end());
	cout << max_dist[k - 1] << ".00";
	return 0;
}
