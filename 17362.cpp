#include <cstdio>

int finger(int n){
	int ret = -1;
	switch(n % 8){
		case 1:
			ret = 1;
			break;
		case 2:
		case 0:
			ret = 2;
			break;
		case 3:
		case 7:
			ret = 3;
			break;
		case 4:
		case 6:
			ret = 4;
			break;
		case 5:
			ret = 5;
			break;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", finger(n));
	return 0;
}
