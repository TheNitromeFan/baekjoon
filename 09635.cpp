#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		bool easy = false, hard = false;
		int first;
		scanf("%d", &first);
		if(first == x){
			easy = true;
		}
		int last;
		for(int i = 1; i < n; ++i){
			scanf("%d", &last);
		}
		if(last == y){
			hard = true;
		}
		if(easy && hard){
			printf("BOTH\n");
		}else if(easy){
			printf("EASY\n");
		}else if(hard){
			printf("HARD\n");
		}else{
			printf("OKAY\n");
		}
	}
	return 0;
}
