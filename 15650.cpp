#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	string bitmask(m, 1);
	bitmask.resize(n, 0);
	do{
		for(int i = 0; i < n; ++i){
			if(bitmask[i]){
				printf("%d ", i+1);
			}
		}
		printf("\n");
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	return 0;
}
