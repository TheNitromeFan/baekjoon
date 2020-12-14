#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

vector<pair<int, int>> v;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	long long cmp = (long long)(b.first - a.first) * (c.second - a.second)
					- (long long)(c.first - a.first) * (b.second - a.second);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			int cmp = ccw(v[0], a, b);
			return cmp > 0 || (cmp == 0 && a < b);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	sort(v.begin() + 1, v.end(), Cmp());
	stack<pair<int, int>> hull;
	hull.push(v[0]);
	hull.push(v[1]);
	for(int i = 2; i < n; ++i){
		while(hull.size() >= 2){
			pair<int, int> b = hull.top();
			hull.pop();
			pair<int, int> a = hull.top();
			if(ccw(a, b, v[i]) > 0){
				hull.push(b);
				break;
			}
		}
		hull.push(v[i]);
	}
	cout << hull.size();
	return 0;
}
