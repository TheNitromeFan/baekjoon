#include <cstdio>

int main(){
	int n, d, k, c;
	scanf("%d %d %d %d", &n, &d, &k, &c);
	int belt[30000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &belt[i]);
	}
	int cnt = 0;
	int eaten[3001] = {};
	for(int i = 0; i < k; ++i){
		if(eaten[belt[i]] == 0){
			++cnt;
		}
		++eaten[belt[i]];
	}
	int max = cnt + (eaten[c] == 0);
	int i = k, j = 0;
	do{
		--eaten[belt[j]];
		if(eaten[belt[j]] == 0){
			--cnt;
		}
		if(eaten[belt[i]] == 0){
			++cnt;
		}
		++eaten[belt[i]];
		if(max < cnt + (eaten[c] == 0)){
			max = cnt + (eaten[c] == 0);
		}
		// printf("%d: %d\n", j, cnt);
		i = (i + 1) % n;
		j = (j + 1) % n;
	}while(!(i == k && j == 0));
	printf("%d", max);
	return 0;
}
