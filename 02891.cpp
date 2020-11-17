#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::sort;

int main(){
	int n, s, r;
	scanf("%d %d %d", &n, &s, &r);
	int damaged[10], reserve[10];
	for(int i = 0; i < s; ++i){
		scanf("%d", &damaged[i]);
	}
	for(int j = 0; j < r; ++j){
		scanf("%d", &reserve[j]);
	}
	sort(damaged, damaged + s);
	sort(reserve, reserve + r);
	int cnt = s;
	int idx1 = 0, idx2 = 0;
	while(idx1 < s || idx2 < r){
		if(idx1 < s && idx2 < r && abs(damaged[idx1] - reserve[idx2]) <= 1){
			--cnt;
			++idx1;
			++idx2;
		}else if(idx2 == r || damaged[idx1] < reserve[idx2]){
			++idx1;
		}else{
			++idx2;
		}
	}
	printf("%d", cnt);
	return 0;
}
