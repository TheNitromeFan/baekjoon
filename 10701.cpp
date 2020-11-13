#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	for(int i = 0; i + 1 < n; ++i){
		if((v[i].first > v[i + 1].first && v[i].second == 1 && v[i + 1].second == 0)
		|| (v[i].first < v[i + 1].first && v[i].second == 0 && v[i + 1].second == 1)){
			swap(v[i].first, v[i + 1].first);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if((v[i].first <= x && v[i].second == 1) || (v[i].first > x && v[i].second == 0)){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}

