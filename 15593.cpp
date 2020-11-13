#include <cstdio>
#include <vector>
#include <utility>
#define MAX (1000 + 1)

using namespace std;

int time(int watched[MAX]){
	int ret = 0;
	for(int i = 0; i < MAX; ++i){
		if(watched[i]){
			++ret;
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> guards;
	guards.resize(n);
	int watched[MAX] = {};
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &guards[i].first, &guards[i].second);
		for(int j = guards[i].first; j < guards[i].second; ++j){
			++watched[j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = guards[i].first; j < guards[i].second; ++j){
			--watched[j];
		}
		int cmp = time(watched);
		if(ans < cmp){
			ans = cmp;
		}
		for(int j = guards[i].first; j < guards[i].second; ++j){
			++watched[j];
		}
	}
	printf("%d", ans);
	return 0;
}
