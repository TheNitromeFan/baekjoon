#include <cstdio>

int main(){
	int p;
	scanf("%d", &p);
	int n;
	scanf("%d", &n);
	int stone[101] = {};
	for(int i = 0; i < n; ++i){
		int pos;
		char dir;
		scanf("%d %c", &pos, &dir);
		if(dir == 'R'){
			for(int x = pos + 1; x <= 100; ++x){
				++stone[x];
				stone[x] %= 3;
			}
		}else{
			for(int x = pos - 1; x > 0; --x){
				++stone[x];
				stone[x] %= 3;
			}
		}
	}
	int a[3] = {};
	for(int x = 1; x <= 100; ++x){
		++a[stone[x]];
	}
	for(int i = 0; i < 3; ++i){
		printf("%.2lf\n", p * a[i] / 100.0);
	}
	return 0;
}
