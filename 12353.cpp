#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char gender;
		int f1, i1, f2, i2;
		scanf(" %c %d'%d\" %d'%d\"", &gender, &f1, &i1, &f2, &i2);
		int height = (12 * f1 + i1 + 12 * f2 + i2 + (gender == 'B' ? 5 : -5));
		int low = height / 2 - 4, high = height / 2 + 4;
		if(height % 2 == 1){
			++low;
		}
		printf("Case #%d: %d'%d\" to %d'%d\"\n", i, low / 12, low % 12, high / 12, high % 12);
	}
	return 0;
}
