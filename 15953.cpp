#include <cstdio>

int prev_rank(int x){
	if(x == 1){
		return 1;
	}else if(x <= 3){
		return 2;
	}else if(x <= 6){
		return 3;
	}else if(x <= 10){
		return 4;
	}else if(x <= 15){
		return 5;
	}else if(x <= 21){
		return 6;
	}else{
		return 0;
	}
}

int cur_rank(int x){
	if(x == 1){
		return 1;
	}else if(x <= 3){
		return 2;
	}else if(x <= 7){
		return 3;
	}else if(x <= 15){
		return 4;
	}else if(x <= 31){
		return 5;
	}else{
		return 0;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int prev[7] = {0, 500, 300, 200, 50, 30, 10};
	int cur[6] = {0, 512, 256, 128, 64, 32};
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 0){
			a = 100;
		}
		if(b == 0){
			b = 64;
		}
		printf("%d\n", (prev[prev_rank(a)] + cur[cur_rank(b)]) * 10000);
	}
	return 0;
}
