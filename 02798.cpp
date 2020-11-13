#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cards[300000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &cards[i]);
	}
	string bitmask(3, 1);
	bitmask.resize(n, 0);
	int ans = 0;
	do{
		int total = 0;
		for(int i = 0; i < n; ++i){
			if(bitmask[i]){
				total += cards[i];
			}
		}
		if(total <= m && total > ans){
			ans = total;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", ans);
	return 0;
}
