#include <cstdio>

int main(){
	int m, t, u, f, d;
	scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);
	int i;
	for(i = 0; i < t; ++i){
		char slope;
		scanf(" %c", &slope);
		if(slope == 'f'){
			if(m < 2 * f){
				break;
			}
			m -= 2 * f;
		}else{
			if(m < u + d){
				break;
			}
			m -= u + d;
		}
	}
	printf("%d", i);
	return 0;
}
