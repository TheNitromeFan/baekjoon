#include <cstdio>
#include <algorithm>

struct meeting{
	int t;
	int p;
} days[16];

int max_revenue(int start, int end){
	if(start > end){
		return 0;
	}
	else if(start + days[start].t - 1 > end){
		return max_revenue(start+1, end);
	}else{
		return std::max(max_revenue(start + days[start].t, end) + days[start].p, max_revenue(start+1, end));
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &days[i].t, &days[i].p);
	}
	printf("%d", max_revenue(1, n));
	return 0;
}
