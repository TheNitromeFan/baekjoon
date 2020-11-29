#include <cstdio>

void evaluate(int a[12], int n, int add, int sub, int mult, int div,
			  int pos, int cur, int &min, int &max){
	if(pos == n){
		if(cur > max){
			max = cur;
		}
		if(cur < min){
			min = cur;
		}
		return;
	}
	if(add > 0){
		evaluate(a, n, add - 1, sub, mult, div, pos + 1, cur + a[pos + 1], min, max);
	}
	if(sub > 0){
		evaluate(a, n, add, sub - 1, mult, div, pos + 1, cur - a[pos + 1], min, max);
	}
	if(mult > 0){
		evaluate(a, n, add, sub, mult - 1, div, pos + 1, cur * a[pos + 1], min, max);
	}
	if(div > 0){
		evaluate(a, n, add, sub, mult, div - 1, pos + 1, cur / a[pos + 1], min, max);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[12];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int add, sub, mult, div;
	scanf("%d %d %d %d", &add, &sub, &mult, &div);
	int min = 1000000001, max = -1000000001;
	evaluate(a, n, add, sub, mult, div, 1, a[1], min, max);
	printf("%d\n%d", max, min);
	return 0;
}
