#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	while(true){
		int n, p;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		scanf("%d", &p);
		int page = min((p - 1) / 2 + 1, (n - p) / 2 + 1);
		vector<int> pages = {2 * page - 1, 2 * page, n - 2 * page + 1, n - 2 * page + 2};
		for(int x : pages){
			if(x != p){
				printf("%d ", x);
			}
		}
		printf("\n");
	}
	return 0;
}
