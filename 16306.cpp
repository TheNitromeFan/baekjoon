#include <cstdio>

int main(){
	int v;
	scanf("%d", &v);
	int minArea = 2000000000;
	for(int a = 1; a * a * a <= v; ++a){
		if(v % a != 0){
			continue;
		}
		for(int b = a; a * b * b <= v; ++b){
			if(v % (a * b) != 0){
				continue;
			}
			int c = v / (a * b);
			int area = 2 * (a * b + b * c + c * a);
			if(minArea > area){
				minArea = area;
			}
		}
	}
	printf("%d", minArea);
	return 0;
}
