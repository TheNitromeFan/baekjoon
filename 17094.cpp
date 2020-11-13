#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s[100001];
	scanf("%s", s);
	int two = 0, e = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '2'){
			++two;
		}else{
			++e;
		}
	}
	if(two > e){
		printf("2");
	}else if(two < e){
		printf("e");
	}else{
		printf("yee");
	}
	return 0;
}
