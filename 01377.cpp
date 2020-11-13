#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		v.push_back(make_pair(i, x));
	}
	stable_sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int tmp = v[i].first - i;
		if(tmp > ans){
			ans = tmp;
		}
	}
	printf("%d", ans + 1);
	return 0;
}
