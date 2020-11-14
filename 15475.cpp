#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int consec = 0, maxConsec = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == 1){
			++consec;
			if(consec > maxConsec){
				maxConsec = consec;
			}
		}else{
			consec = 0;
		}
	}
	printf("%d", maxConsec + 1);
	return 0;
}
