#include <cstdio>
#define MAX_LEN 8

int main(){
	for(int i = 0; i < 3; ++i){
		char n[9];
		scanf("%s", n);
		int max_streak = 0;
		int idx = 0;
		while(idx < MAX_LEN){
			int streak = 0;
			char c = n[idx];
			while(idx < MAX_LEN && n[idx] == c){
				++streak;
				++idx;
			}
			if(streak > max_streak){
				max_streak = streak;
			}
		}
		printf("%d\n", max_streak);
	}
	return 0;
}
