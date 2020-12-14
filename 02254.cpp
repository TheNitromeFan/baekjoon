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

bool inside(vector<pair<int, int>> &hull, pair<int, int> p){
	int cmp = ccw(p, hull[hull.size() - 1], hull[0]);
	for(unsigned i = 0; i + 1 < hull.size(); ++i){
		if(cmp != ccw(p, hull[i], hull[i + 1])){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	pair<int, int> p;
	cin >> n >> p.first >> p.second;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	int ans = 0;
	while(v.size() >= 3){
		sort(v.begin(), v.end());
		sort(v.begin() + 1, v.end(), Cmp());
		vector<bool> used(v.size());
		stack<unsigned> hull;
		hull.push(0);
		used[0] = true;
		hull.push(1);
		used[1] = true;
		for(unsigned i = 2; i < v.size(); ++i){
			while(hull.size() >= 2){
				int b = hull.top();
				hull.pop();
				used[b] = false;
				int a = hull.top();
				if(ccw(v[a], v[b], v[i]) > 0){
					hull.push(b);
					used[b] = true;
					break;
				}
			}
			hull.push(i);
			used[i] = true;
		}
		if(hull.size() < 3){
			break;
		}
		vector<pair<int, int>> vt;
		while(!hull.empty()){
			vt.push_back(v[hull.top()]);
			hull.pop();
		}
		if(inside(vt, p)){
			++ans;
		}
		vector<pair<int, int>> tmp;
		for(unsigned idx = 0; idx < v.size(); ++idx){
			if(!used[idx]){
				tmp.push_back(v[idx]);
			}
		}
		v = tmp;
	}
	cout << ans;
	return 0;
}
