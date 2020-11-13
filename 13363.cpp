#include <cstdio>

int main(){
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int pos = (n2 + 360 - n1) % 360, neg = (n1 + 360 - n2) % 360;
	if(pos > neg){
		printf("%d", -neg);
	}else{
		printf("%d", pos);
	}
	return 0;
}
