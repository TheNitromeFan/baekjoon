#include <cstdio>

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	int high = n - p, low = p - 1;
	bool pizza = false;
	if((n - 1) % 3 == 0){
		pizza = (high >= (n - 1) / 3) && (low >= (n - 1) / 3);
	}else if((n - 1) % 3 == 1){
		pizza = (high >= (n - 1) / 3 + 1) && (low >= (n - 1) / 3);
	}else{
		pizza = (high >= (n - 1) / 3 + 1) && (low >= (n - 1) / 3 + 1);
	}
	printf("%s", pizza ? "YES" : "NO");
	return 0;
}
