#include <cstdio>
#include <cstdlib>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int min = 101, max = -1;
		int sum = 0;
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			if(x < min){
				min = x;
			}
			if(x > max){
				max = x;
			}
			sum += x;
		}
		double a = (min + max) / 2.0, b = sum / (double)n;
		printf("%s\n", abs(a - b) < 1 ? "Yes" : "No");
	}
	return 0;
}
