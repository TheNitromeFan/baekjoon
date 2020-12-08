#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> flowers(n);
	for(int i = 0; i < n; ++i){
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		flowers[i] = make_pair(100 * x + y, 100 * z + w);
	}
	sort(flowers.begin(), flowers.end());
	int ans = 0;
	int last = 0;
	int idx = -1;
	for(int day = 301; day <= 1130 && idx < n; day = last){
		bool flag = false;
		++idx;
		for(int j = idx; j < n; ++j){
			if(flowers[j].first > day){
				break;
			}
			if(flowers[j].second > last){
				last = flowers[j].second;
				idx = j;
				flag = true;
			}
		}
		if(flag){
			++ans;
		}else{
			ans = 0;
			break;
		}
	}
	cout << ans;
	return 0;
}
