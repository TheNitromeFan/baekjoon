#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<1>(a) > get<1>(b) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	map<int, tuple<int, int>> cnt;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(cnt.find(x) == cnt.end()){
			cnt[x] = make_tuple(1, i);
		}else{
			++get<0>(cnt[x]);
		}
	}
	vector<tuple<int, int, int>> v;
	for(auto p : cnt){
		v.push_back(make_tuple(p.first, get<0>(p.second), get<1>(p.second)));
	}
	sort(v.begin(), v.end(), cmp);
	for(auto p : v){
		for(int j = 0; j < get<1>(p); ++j){
			printf("%d ", get<0>(p));
		}
	}
	return 0;
}
