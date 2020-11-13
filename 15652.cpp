#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	string bitmask(m, 1);
	bitmask.resize(n+m-1, 0);
	do{
		int cntr = 0;
		for(int i = 0; i < n+m-1; ++i){
			if(bitmask[i]){
				printf("%d ", i+1-cntr);
				++cntr;
			}
		}
		printf("\n");
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	return 0;
}
