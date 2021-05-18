#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++t;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].first >> v[i].second;
		}
		v.push_back(v[0]);
		v.push_back(v[1]);
		int xmin = MIN, xmax = MAX, ymin = MIN, ymax = MAX;
		for(int i = 1; i <= n; ++i){
			if(v[i - 1].first > v[i].first && v[i + 1].second > v[i].second){
				xmin = max(xmin, v[i].first);
				ymin = max(ymin, v[i].second);
			}else if(v[i - 1].second < v[i].second && v[i + 1].first > v[i].first){
				xmin = max(xmin, v[i].first);
				ymax = min(ymax, v[i].second);
			}else if(v[i - 1].second > v[i].second && v[i + 1].first < v[i].first){
				xmax = min(xmax, v[i].first);
				ymin = max(ymin, v[i].second);
			}else if(v[i - 1].first < v[i].first && v[i + 1].second < v[i].second){
				xmax = min(xmax, v[i].first);
				ymax = min(ymax, v[i].second);
			}
		}
		cout << "Floor #" << t << '\n';
		if(xmin <= xmax && ymin <= ymax){
			cout << "Surveillance is possible.\n";
		}else{
			cout << "Surveillance is impossible.\n";
		}
		cout << '\n';
	}
	return 0;
}
