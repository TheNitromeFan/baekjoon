#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::swap;

int main(){
	int n, a, b, m;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	int numberToRoom[1001], roomToNumber[1001];
	for(int j = 1; j <= n; ++j){
		numberToRoom[j] = j;
		roomToNumber[j] = j;
	}
	int cnt = 0, maxConsec = 0, consec = 0;
	if(abs(numberToRoom[1] - numberToRoom[a]) <= b){
		++cnt;
		++consec;
	}
	int points[1001] = {};
	for(int i = 2; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &points[j]);
		}
		for(int j = 1; j <= n; ++j){
			int x;
			scanf("%d", &x);
			points[j] -= x;
		}
		for(int j = 1; j < n; ++j){
			int x = roomToNumber[j], y = roomToNumber[j + 1];
			if((points[x] >= 0 && points[y] >= 0 && points[y] >= points[x] + 2)
			|| (points[x] < 0 && points[y] >= 0)
			|| (points[x] < 0 && points[y] < 0 && points[y] >= points[x] + 4)){
				roomToNumber[j] = y;
				roomToNumber[j + 1] = x;
				numberToRoom[y] = j;
				numberToRoom[x] = j + 1;
				points[y] -= 2;
				points[x] += 2;
			}
		}
		// printf("%d %d\n", hong, cho);
		if(abs(numberToRoom[1] - numberToRoom[a]) <= b){
			++cnt;
			++consec;
		}else{
			consec = 0;
		}
		if(consec > maxConsec){
			maxConsec = consec;
		}
	}
	if(consec > maxConsec){
		maxConsec = consec;
	}
	printf("%d %d", cnt, maxConsec);
	return 0;
}
