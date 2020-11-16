#include <cstdio>

bool overlap(int n, int pos, int p, int r){
	for(int i = pos, j = 0; j < r; ++i, ++j){
		if((i + 1) / 2 == p || i / 2 == p){
			return true;
		}
		if(i == 2 * n){
			i = 0;
		}
	}
	return false;
}

int main(){
	int n, p, t;
	scanf("%d %d %d", &n, &p, &t);
	int q = (t - 1) / (4 * n - 2), r = (t - 1) % (4 * n - 2) + 1;
	int pos = 1 + q * (2 * n - 1) % (2 * n);
	for(int i = 1; i < r; ++i){
		if(i <= 2 * n){
			pos = (pos + i) % (2 * n);
		}else{
			pos = (pos + 4 * n - i) % (2 * n);
		}
	}
	if(r > 2 * n){
		r = 4 * n - r;
	}
	// printf("%d %d %d %d\n", n, pos, p, r);
	if(overlap(n, pos, p, r)){
		printf("Dehet YeonJwaJe ^~^");
	}else{
		printf("Hing...NoJam");
	}
	return 0;
}
