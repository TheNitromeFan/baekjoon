#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int num[8];
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	string bitmask(m, 1);
	bitmask.resize(n+m-1, 0);
	do{
		int cntr = 0;
		for(int i = 0; i < n+m-1; ++i){
			if(bitmask[i]){
				printf("%d ", num[i-cntr]);
				++cntr;
			}
		}
		printf("\n");
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	return 0;
}
