#include <cstdio>

int main(){
	int t, p;
	scanf("%d %d", &t, &p);
	double ans;
	if(p < 20){
		ans = t * p / (60.0 - p);
	}else{
		ans = t * (p + 20) / (100.0 - p);
	}
	printf("%f", ans);
	return 0;
}
