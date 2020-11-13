#include <cstdio>
#define MAX (1000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX] = {};
	for(int i = 0; i < n; ++i){
		int pos, h;
		scanf("%d %d", &pos, &h);
		a[pos] = h;
	}
	int i = 0, j = MAX - 1;
	int left = a[0], right = a[MAX - 1];
	int area = 0;
	while(i < j){
		if(a[i] < a[j]){
			area += left;
			++i;
			if(left < a[i]){
				left = a[i];
			}
		}else{
			area += right;
			--j;
			if(right < a[j]){
				right = a[j];
			}
		}
	}
	area += a[i];
	printf("%d", area);
	return 0;
}
