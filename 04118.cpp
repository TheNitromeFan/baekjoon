#include <cstdio>

bool covered(bool lotto[50]){
	for(int i = 1; i <= 49; ++i){
		if(!lotto[i]){
			return false;
		}
	}
	return true;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		bool lotto[50] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 6; ++j){
				int x;
				scanf("%d", &x);
				lotto[x] = true;
			}
		}
		printf("%s\n", covered(lotto) ? "Yes" : "No");
	}
	return 0;
}
