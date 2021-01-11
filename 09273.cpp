#include <cstdio>

using namespace std;

int main(){
	int n;
	while(scanf("1/%d\n", &n) == 1){
		int cnt = 0;
		for(int x = n + 1; x <= 2 * n; ++x){
			if((n * n) % (x - n) == 0){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
