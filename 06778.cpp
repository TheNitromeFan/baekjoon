#include <cstdio>

int main(){
	int ant, eyes;
	scanf("%d %d", &ant, &eyes);
	if(ant >= 3 && eyes <= 4){
		printf("TroyMartian\n");
	}
	if(ant <= 6 && eyes >= 2){
		printf("VladSaturnian\n");
	}
	if(ant <= 2 && eyes <= 3){
		printf("GraemeMercurian\n");
	}
	return 0;
}
