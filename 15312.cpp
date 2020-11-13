#include <cstdio>
#include <cstring>

int lines[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2,
				 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int proceed(int a[4001], int len){
	for(int i = len - 1; i >= 2; --i){
		for(int j = 0; j < i; ++j){
			a[j] = (a[j] + a[j + 1]) % 10;
		}
	}
	return 10 * a[0] + a[1];
}

int main(){
	char a[2001], b[2001];
	scanf("%s", a);
	int len = strlen(a);
	scanf("%s", b);
	int together[4001];
	for(int i = 0; i < 2 * len; ++i){
		if(i % 2 == 0){
			together[i] = lines[a[i / 2] - 'A'];
		}else{
			together[i] = lines[b[i / 2] - 'A'];
		}
	}
	int ans = proceed(together, 2 * len);
	if(ans / 10 == 0){
		printf("0");
	}
	printf("%d", ans);
	return 0;
}
