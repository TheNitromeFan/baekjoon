#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	vector<int> a;
	while(cin >> x){
		a.push_back(x);
	}
	int sum = a.back();
	a.pop_back();
	sort(a.begin(), a.end());
	vector<pair<int, int>> ans;
	for(unsigned i = 0; i < a.size(); ++i){
		for(unsigned j = i + 1; j < a.size(); ++j){
			if(j > i + 1 && a[j] == a[j - 1]){
				continue;
			}
			if(a[i] + a[j] == sum){
				ans.push_back(make_pair(a[i], a[j]));
			}
		}
	}
	for(pair<int, int> p : ans){
		printf("%d %d\n", p.first, p.second);
	}
	printf("%llu", ans.size());
	return 0;
}
