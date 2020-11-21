#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	pair<int, int> s[100];
	int sum = 0, max_s = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &s[i].first);
		sum += s[i].first;
		if(max_s < s[i].first){
			max_s = s[i].first;
		}
		s[i].second = i + 1;
	}
	if(max_s <= sum - max_s){
		sort(s, s + n, greater<pair<int, int>>());
		for(int i = 0; i < n; ++i){
			printf("%d ", s[i].second);
		}
	}else{
		printf("impossible");
	}
	return 0;
}
