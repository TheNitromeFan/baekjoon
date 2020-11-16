#include <cstdio>
#include <cstring>
#define MAX 100001

void print_decimal(int n, int d){
	printf("%d.", n / d);
	n %= d;
	int index[MAX];
	memset(index, -1, sizeof(index));
	int quo[MAX];
	int sp = 0;
	bool repeat = false;
	int cindex = -1;
	while(n > 0){
		if(sp > 0 && index[n] >= 0){
			repeat = true;
			cindex = index[n];
			break;
		}
		quo[sp] = n;
		++sp;
		++cindex;
		index[n] = cindex;
		n *= 10;
		n %= d;
	}
	for(int i = 0; i < sp; ++i){
		if(repeat && cindex == i){
			printf("(");
		}
		printf("%d", (quo[i] * 10) / d);
	}
	if(repeat){
		printf(")\n");
	}else{
		printf("(0)\n");
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, d;
		scanf("%d %d", &n, &d);
		print_decimal(n, d);
	}
	return 0;
}
