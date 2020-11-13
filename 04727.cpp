#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int cal, fat, carb, prot;
	while(true){
		scanf("%d %d %d %d", &cal, &fat, &carb, &prot);
		if(cal == 0 && fat == 0 && carb == 0 && prot == 0){
			break;
		}
		if(cal >= max((fat - 0.5), 0.0) * 9 + max((carb - 0.5), 0.0) * 4 + max((prot - 0.5), 0.0) * 4
		&& cal < (fat + 0.5) * 9 + (carb + 0.5) * 4 + (prot + 0.5) * 4){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}
