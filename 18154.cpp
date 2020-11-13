#include <cstdio>
#define MAX 100

int main(){
	int n;
	scanf("%d", &n);
	int t[MAX], d[MAX];
	scanf("%d %d", &t[0], &d[0]);
	int speed = 0;
	for(int i = 1; i < n; ++i){
		scanf("%d %d", &t[i], &d[i]);
		int interval = (d[i] - d[i-1]) / (t[i] - t[i-1]);
		if(speed < interval){
			speed = interval;
		}
	}
	printf("%d", speed);
	return 0;
}
