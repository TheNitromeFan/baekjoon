#include <cstdio>

int main(){
	int aatk, alif, batk, blif;
	scanf("%d %d %d %d", &aatk, &alif, &batk, &blif);
	while(alif > 0 && blif > 0){
		alif -= batk;
		blif -= aatk;
	}
	if(alif <= 0 && blif <= 0){
		printf("DRAW");
	}else if(alif <= 0){
		printf("PLAYER B");
	}else{
		printf("PLAYER A");
	}
	return 0;
}
