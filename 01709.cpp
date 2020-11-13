#include <cstdio>

int main(){
	long long n;
	scanf("%lld", &n);
	long long tiles = 0;
	long long prev_a = n / 2;
	for(long long cnt = 0; cnt < n / 2; ++cnt){
		long long a = prev_a;
		long long b = (n / 2) * (n / 2) - (cnt + 1) * (cnt + 1);
		if(b > (a - 1) * (a - 1)){
			++tiles;
			continue;
		}
		while(b <= (a - 1) * (a - 1) && a != 1){
			--a;
		}
		if(b == a * a){
			tiles += prev_a - a;
		}else{
			tiles += prev_a - a + 1;
		}
		prev_a = a;
	}
	tiles *= 4;
	printf("%lld", tiles);
	return 0;
}
