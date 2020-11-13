#include <cstdio>


void decreasing(long n){
	
	char a[102] = {0};
	a[101] = '\0';
	int end = 100;
	char ones = '0';
	a[end] = ones;
	int len = 1;
	int flag;
	for(long count = 0; count < n; count++){
		flag = 0;
		for(int i = end; i > end-len; i--)
			if(a[i-1] == 0 || a[i-1] > a[i] + 1){
				if(a[i] >= '9'){
					flag = 1;
					break;
				}else{
					ones = '0';
					for(int t = end; t > i; t--)
						a[t] = ones++;
					a[i]++;
					break;
				}
			}
		if(flag){
			len++;
			ones = '0';
			for(int i = end; i > end-len; i--) a[i] = ones++;
			if(ones > '9' + 1){
				printf("-1");
				return;
			}
		}
	}
	for(int i = end-len+1; i <= end; i++) printf("%c", a[i]);
}

int main(void){
	
	long n;
	scanf("%ld", &n);
	decreasing(n);
	return 0;
}
