#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cnts[101] = {};
	int maxVotes = 0, candidate = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		++cnts[x];
		if(x != 0 && cnts[x] > maxVotes){
			maxVotes = cnts[x];
			candidate = x;
		}else if(x != 0 && cnts[x] == maxVotes){
			candidate = 0;
		}
	}
	if(candidate == 0){
		printf("skipped");
	}else{
		printf("%d", candidate);
	}
	return 0;
}
