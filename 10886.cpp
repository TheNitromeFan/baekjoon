#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cute = 0, opinion;
	for(int i = 0; i < n; ++i){
		scanf("%d", &opinion);
		if(opinion){
			++cute;
		}else{
			--cute;
		}
	}
	if(cute > 0){
		printf("Junhee is cute!");
	}else{
		printf("Junhee is not cute!");
	}
	return 0;
}
