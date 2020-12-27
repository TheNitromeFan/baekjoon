#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> parents(n + 1);
	for(int i = 1; i <= n; ++i){
		int mom, pops;
		cin >> mom >> pops;
		parents[i] = make_pair(mom, pops);
	}
	vector<bool> vanished(n + 1);
	int m;
	cin >> m;
	for(int j = 0; j < m; ++j){
		int x;
		cin >> x;
		vanished[x] = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int mom = parents[i].first, pops = parents[i].second;
		if(mom != 0 && pops != 0 && !vanished[i] && !vanished[mom] && !vanished[pops]){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
