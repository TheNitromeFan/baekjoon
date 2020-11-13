#include <cstdio>
#define INTERMISSION 5

int main(){
	int n, len, d;
	scanf("%d %d %d", &n, &len, &d);
	int time = 0;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j <= len; ++j){
			++time;
		}
		for(int j = 1; j <= INTERMISSION; ++j){
			if(time % d == 0){
				printf("%d", time);
				return 0;
			}
			++time;
		}
	}
	for(int j = 1; j <= len; ++j){
		++time;
	}
	while(time % d != 0){
		++time;
	}
	printf("%d", time);
	return 0;
}
