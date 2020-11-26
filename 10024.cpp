#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[101], b[101], order[101];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
		for(int j = 1; j <= n; ++j){
			if(a[j] == b[i]){
				order[j] = i;
				break;
			}
		}
	}
	bool visited[101] = {};
	int idx = 1;
	int cycles = 0;
	int largest = 0;
	while(idx <= n){
		if(order[idx] == idx){
			++idx;
			continue;
		}
		if(!visited[idx]){
			int cnt = 0;
			++cycles;
			while(!visited[idx]){
				visited[idx] = true;
				idx = order[idx];
				++cnt;
				if(largest < cnt){
					largest = cnt;
				}
			}
		}
		++idx;
	}
	if(cycles > 0){
		printf("%d %d", cycles, largest);
	}else{
		printf("0 -1");
	}
	return 0;
}
