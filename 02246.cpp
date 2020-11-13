#include <cstdio>

struct hotel{
	int dist;
	int cost;
	bool cand;
} h[10000];

int main(){
	int n;
	scanf("%d", &n);
	if(n == 0){
		return 0;
	}
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &h[i].dist, &h[i].cost);
		h[i].cand = true;
	}
	for(int i = 0; i < n; ++i){
		if(!h[i].cand){
			continue;
		}
		for(int j = 0; j < n; ++j){
			if((h[j].dist < h[i].dist && h[j].cost <= h[i].cost) || (h[j].cost < h[i].cost && h[j].dist <= h[i].dist)){
				h[i].cand = false;
				break;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(h[i].cand){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
