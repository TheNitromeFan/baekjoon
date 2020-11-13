#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	int time = v[0].first;
	int wait = v[0].second;
	for(int i = 1; i < n; ++i){
		if(v[i].first - time < wait){
			wait -= v[i].first - time;
		}else{
			wait = 0;
		}
		time = v[i].first;
		wait += v[i].second;
	}
	printf("%d", time + wait);
	return 0;
}
