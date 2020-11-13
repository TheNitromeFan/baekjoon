#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 0, pos = -1;
	for(int i = 0; i < n; ++i){
		if(v[i].first > pos){
			pos = v[i].first;
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
