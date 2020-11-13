#include <cstdio>

struct test{
	int i;
	int j;
	int k;
	int r;
} tests[1000];

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int working[301];
	for(int part = 1; part <= a + b + c; ++part){
		working[part] = 2;
	}
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		scanf("%d %d %d %d", &tests[a0].i, &tests[a0].j, &tests[a0].k, &tests[a0].r);
		if(tests[a0].r == 1){
			working[tests[a0].i] = 1;
			working[tests[a0].j] = 1;
			working[tests[a0].k] = 1;
		}
	}
	for(int a0 = 0; a0 < n; ++a0){
		/*
		for(int part = 1; part <= a + b + c; ++part){
			printf("%d ", working[part]);
		}
		printf("\n");
		*/
		for(int a1 = 0; a1 < n; ++a1){
			if(tests[a1].r == 0){
				if(working[tests[a1].i] == 1 && working[tests[a1].j] == 1){
					working[tests[a1].k] = 0;
				}else if(working[tests[a1].i] == 1 && working[tests[a1].k] == 1){
					working[tests[a1].j] = 0;
				}else if(working[tests[a1].j] == 1 && working[tests[a1].k] == 1){
					working[tests[a1].i] = 0;
				}
			}
		}
	}
	for(int part = 1; part <= a + b + c; ++part){
		printf("%d\n", working[part]);
	}
	return 0;
}
