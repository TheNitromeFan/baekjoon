#include <cstdio>

using namespace std;

int main(){
	int a;
	static int arr[(1 << 25) / 32] = {};
	while(scanf("%d", &a) == 1){
		int quotient = a / 32;
		int remainder = 1 << (a % 32);
		if(!(arr[quotient] & remainder)){
			arr[quotient] += remainder;
			printf("%d ", a);
		}
	}
	return 0;
}
