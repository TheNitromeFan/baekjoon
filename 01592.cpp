#include <cstdio>

int main(){
	int n, m, ell;
	scanf("%d %d %d", &n, &m, &ell);
	int received[1001] = {};
	int tosses = 0;
	int player = 1;
	while(true){
		++received[player];
		if(received[player] == m){
			break;
		}else if(received[player] % 2 == 1){
			player += ell;
			if(player > n){
				player -= n;
			}
		}else{
			player -= ell;
			if(player < 1){
				player += n;
			}
		}
		++tosses;
	}
	printf("%d", tosses);
	return 0;
}
