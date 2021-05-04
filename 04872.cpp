#include <cstdio>
#define MAX 10000
#define MAX_LEN 11

using namespace std;

int main(){
	char codes[MAX][MAX_LEN];
	int n = 0;
	while(scanf("%s", codes[n]) == 1){
		++n;
	}
	for(int j = 0; codes[0][j] != '\0'; ++j){
		int x = 0;
		for(int i = 0; i < n; ++i){
			x += codes[i][j] - '0';
		}
		printf("%d", x % 10);
	}
	return 0;
}
