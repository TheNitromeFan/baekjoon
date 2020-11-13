#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int votes[10000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &votes[i]);
		if(votes[i] > votes[0]){
			printf("N");
			return 0;
		}
	}
	printf("S");
	return 0;
}
