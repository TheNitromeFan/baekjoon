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
		vector<pair<int, int>> v;
		while(true){
			int s, f;
			cin >> s >> f;
			if(s == 0 && f == 0){
				break;
			}
			v.push_back(make_pair(s, f));
		}
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		});
		int x = -1;
		int ans = 0;
		for(pair<int, int> p : v){
			if(p.first >= x){
				++ans;
				x = p.second;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
