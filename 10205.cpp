#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	for(int a0 = 1; a0 <= k; ++a0){
		int h;
		scanf("%d", &h);
		char actions[100];
		scanf("%s", actions);
		for(int i = 0; actions[i] != '\0'; ++i){
			if(actions[i] == 'c'){
				++h;
			}else if(h > 0){
				--h;
			}
		}
		printf("Data Set %d:\n%d\n\n", a0, h);
	}
	return 0;
}
