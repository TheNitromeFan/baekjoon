#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	bool wild_card = false;
	for(int i = 0; i < k; ++i){
		int x;
		cin >> x;
		if(x == 0){
			wild_card = true;
		}else{
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	if(wild_card){
		--k;
	}
	vector<pair<int, int>> intervals;
	int idx = 0;
	while(idx < k){
		int start = idx;
		while(idx < n && v[idx] - v[start] == idx - start){
			++idx;
		}
		intervals.push_back(make_pair(v[start], v[idx - 1]));
	}
	int max_length = 0;
	for(pair<int, int> p : intervals){
		max_length = max(max_length, p.second - p.first + 1);
	}
	if(wild_card){
		++max_length;
		for(unsigned j = 0; j + 1 < intervals.size(); ++j){
			pair<int, int> p = intervals[j], q = intervals[j + 1];
			if(p.second + 2 == q.first){
				max_length = max(max_length, q.second - p.first + 1);
			}
		}
	}
	cout << max_length;
	return 0;
}
