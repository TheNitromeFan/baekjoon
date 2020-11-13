#include <cstdio>
#include <cmath>

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	int max = 0, m;
	for(int i = 0; i < n; ++i){
		scanf("%d", &m);
		if(m > max){
			max = m;
		}
	}
	printf("%d", (int)ceil(max * s / 1000.0));
	return 0;
}
