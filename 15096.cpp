#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int atbats = 0;
	int bases = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == -1){
			continue;
		}
		++atbats;
		bases += x;
	}
	printf("%lf", bases / (double)atbats);
	return 0;
}
