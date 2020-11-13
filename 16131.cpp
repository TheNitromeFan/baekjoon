#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::swap;

int main(){
	int n, a, b, m;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	int room[1001];
	int cnt = 0, maxConsec = 0, consec = 0;
	int hong = 1, cho = a;
	if(abs(hong - cho) <= b){
		++cnt;
		++consec;
	}
	for(int i = 2; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &room[j]);
		}
		for(int j = 1; j <= n; ++j){
			int x;
			scanf("%d", &x);
			room[j] -= x;
			// printf("%d ", room[j]);
		}
		// printf("%d %d\n", hong, cho);
		for(int j = 1; j < n; ++j){
			/*
			for(int k = 1; k <= n; ++k){
				printf("%d ", room[k]);
			}
			printf("\n");
			*/
			if((room[j] >= 0 && room[j + 1] >= 0 && room[j + 1] >= room[j] + 2)
			|| (room[j] < 0 && room[j + 1] >= 0)
			|| (room[j] < 0 && room[j + 1] < 0 && room[j + 1] >= room[j] + 4)){
				swap(room[j], room[j + 1]);
				room[j] -= 2;
				room[j + 1] += 2;
				if(hong == j){
					hong = j + 1;
				}else if(hong == j + 1){
					hong = j;
				}
				if(cho == j){
					cho = j + 1;
				}else if(cho == j + 1){
					cho = j;
				}
			}
		}
		// printf("%d %d\n", hong, cho);
		if(abs(hong - cho) <= b){
			++cnt;
			++consec;
		}else{
			if(consec > maxConsec){
				maxConsec = consec;
			}
			consec = 0;
		}
	}
	if(consec > maxConsec){
		maxConsec = consec;
	}
	printf("%d %d", cnt, maxConsec);
	return 0;
}
