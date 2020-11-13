#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	while(true){
		int a, d;
		scanf("%d %d", &a, &d);
		if(a == 0 && d == 0){
			break;
		}
		vector<int> b(a, 0), c(d, 0);
		for(int i = 0; i < a; ++i){
			scanf("%d", &b[i]);
		}
		for(int j = 0; j < d; ++j){
			scanf("%d", &c[j]);
		}
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		printf("%c\n", b[0] < c[1] ? 'Y' : 'N');
	}
	return 0;
}
