#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a = 0, b = 0;
	int winner = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		a += x;
		b += y;
		if((a + x / 2 >= k && b < k) || (a >= k && b >= k)){
			winner = 1;
			break;
		}else if(b >= k){
			winner = -1;
			break;
		}else if(a + x / 2 - b >= 50){
			winner = 1;
			break;
		}
	}
	printf("%d", winner);
	return 0;
}
