#include <cstdio>

int main(){
	long long n;
	scanf("%lld", &n);
	if(n >= 6){
		printf("Love is open door");
		return 0;
	}
	int start;
	scanf("%d", &start);
	for(long long i = 1; i < n; ++i){
		if(i % 2 == 1){
			printf("%d\n", 1 - start);
		}else{
			printf("%d\n", start);
		}
	}
	return 0;
}
