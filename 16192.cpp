#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> p(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	for(int a0 = 0; a0 < q; ++a0){
		int x, y;
		cin >> x >> y;
		vector<int> ans;
		int min_dist = 1000000000;
		for(int i = 1; i <= n; ++i){
			int d = dist(x, y, p[i].first, p[i].second);
			if(min_dist > d){
				min_dist = d;
				ans.clear();
				ans.push_back(i);
			}else if(min_dist == d){
				ans.push_back(i);
			}
		}
		if(ans.size() == 1){
			cout << "REGION " << ans[0];
		}else if(ans.size() == 2){
			cout << "LINE " << ans[0] << " " << ans[1];
		}else{
			cout << "POINT";
		}
		cout << "\n";
	}
	return 0;
}
