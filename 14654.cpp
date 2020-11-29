#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[300], b[300];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &b[i]);
	}
	int winningTeam = 0;
	int maxStreak = 1;
	int streak = 0;
	for(int i = 0; i < n; ++i){
		if(winningTeam == 1 && (a[i] - b[i] + 3) % 3 == 1){
			// printf("1 ");
			++streak;
			if(maxStreak < streak){
				maxStreak = streak;
			}
		}else if((a[i] - b[i] + 3) % 3 == 1){
			// printf("2 ");
			streak = 1;
			winningTeam = 1;
		}else if(winningTeam == 2 && (b[i] - a[i] + 3) % 3 == 1){
			// printf("3 ");
			++streak;
			if(maxStreak < streak){
				maxStreak = streak;
			}
		}else if((b[i] - a[i] + 3) % 3 == 1){
			// printf("4 ");
			streak = 1;
			winningTeam = 2;
		}else{
			// printf("5 ");
			streak = 1;
			winningTeam = 1 + 2 - winningTeam;
		}
		// printf("%d %d\n", winningTeam, streak);
	}
	printf("%d", maxStreak);
	return 0;
}
