#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		unsigned n;
		cin >> n;
		vector<pair<int, int>> p(n);
		for(unsigned i = 0; i < n; ++i){
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end());
		if(p[0].second != 0){
			unsigned j = 0;
			while(j < n && p[j].second != 0){
				++j;
			}
			reverse(p.begin(), p.begin() + j + 1);
		}
		unsigned i = 1;
		while(i < n){
			if(p[i - 1].first != p[i].first && p[i - 1].second != p[i].second){
				unsigned j = i;
				while(j < n && p[i].first == p[j].first){
					++j;
				}
				reverse(p.begin() + i, p.begin() + j);
			}
			++i;
		}
		int m;
		cin >> m;
		for(int a1 = 0; a1 < m; ++a1){
			int k;
			cin >> k;
			cout << p[k - 1].first << ' ' << p[k - 1].second << '\n';
		}
	}
	return 0;
}
