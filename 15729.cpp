#include <cstdio>
#define MAX 1000000

int main(){
	int n;
	scanf("%d", &n);
	static int bulbs[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &bulbs[i]);
	}
	int presses = 0;
	for(int i = 0; i < n - 2; ++i){
		if(bulbs[i] == 1){
			bulbs[i] = 0;
			bulbs[i + 1] = 1 - bulbs[i + 1];
			bulbs[i + 2] = 1 - bulbs[i + 2];
			++presses;
		}
	}
	if(bulbs[n - 2] == 1){
		bulbs[n - 2] = 0;
		bulbs[n - 1] = 1 - bulbs[n - 1];
		++presses;
	}
	if(bulbs[n - 1] == 1){
		bulbs[n - 1] = 0;
		++presses;
	}
	printf("%d", presses);
	return 0;
}
