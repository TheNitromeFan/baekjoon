#include <cstdio>

// upper: 4 digits (0, 1, 4, 7)
// lower: 3 digits (0, 2, 4)
// both: 2 digits (0, 4)

int main(){
	int n;
	scanf("%d", &n);
	long long powOf8 = 1;
	for(int i = 0; i < n; ++i){
		powOf8 *= 8;
	}
	printf("%lld", powOf8);
	return 0;
}
