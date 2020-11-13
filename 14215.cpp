#include <cstdio>

bool triangle(int a, int b, int c){
	return a + b > c && b + c > a && c + a > b;
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans = 0;
	for(int x = 1; x <= a; ++x){
		for(int y = 1; y <= b; ++y){
			for(int z = 1; z <= c; ++z){
				if(triangle(x, y, z) && ans < x + y + z){
					ans = x + y + z;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
