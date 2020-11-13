#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

void combination(int s[], int n, int k){
	string bitmask(k, 1);
	bitmask.resize(n, 0);
	do{
		for(int i = 0; i < n; ++i){
			if(bitmask[i]){
				printf("%d ", s[i]);
			}
		}
		printf("\n");
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(){
	int k;
	while(true){
		scanf("%d", &k);
		if(k == 0){
			break;
		}
		int s[13];
		for(int i = 0; i < k; ++i){
			scanf("%d", &s[i]);
		}
		combination(s, k, 6);
		printf("\n");
	}
	return 0;
}
