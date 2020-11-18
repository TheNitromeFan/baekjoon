#include <cstdio>
#include <algorithm>
#include <functional>

using std::sort;
using std::greater;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int j, n;
		scanf("%d %d", &j, &n);
		int box[1000];
		for(int i = 0; i < n; ++i){
			int ri, ci;
			scanf("%d %d", &ri, &ci);
			box[i] = ri * ci;
		}
		sort(box, box + n, greater<int>());
		int cnt = 0;
		while(j > 0){
			j -= box[cnt];
			++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
