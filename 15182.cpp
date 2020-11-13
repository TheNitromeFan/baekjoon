#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int bits[11][9];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 8; ++j){
			scanf("%d", &bits[i][j]);
		}
	}
	int even = 0, odd = 0;
	for(int i = 1; i <= n; ++i){
		int sum = 0;
		for(int j = 1; j <= 8; ++j){
			sum += bits[i][j];
		}
		if(sum % 2){
			++odd;
		}else{
			++even;
		}
	}
	bool Even = false;
	if(odd == 1){
		printf("Even\n");
		Even = true;
	}else{
		printf("Odd\n");
	}
	for(int i = 1; i <= n; ++i){
		int sum = 0;
		for(int j = 1; j <= 8; ++j){
			sum += bits[i][j];
		}
		if((Even && (sum % 2)) || (!Even && !(sum % 2))){
			printf("Byte %d is broken\n", i);
		}
	}
	int parity[9];
	for(int j = 1; j <= 8; ++j){
		scanf("%d", &parity[j]);
	}
	for(int j = 1; j <= 8; ++j){
		int sum = parity[j];
		for(int i = 1; i <= n; ++i){
			sum += bits[i][j];
		}
		if((Even && (sum % 2)) || (!Even && !(sum % 2))){
			printf("Bit %d is broken", j);
		}
	}
	return 0;
}
