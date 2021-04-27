#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int x11, x12, y11, y12, x21, x22, y21, y22;
		scanf("%d.%d %d.%d %d.%d %d.%d", &x11, &x12, &y11, &y12, &x21, &x22, &y21, &y22);
		int x1 = 1000000 * x11 + x12, x2 = 1000000 * x21 + x22;
		for(int x = -11000000; x <= 11000000; x += 1000000){
			if((x <= x1 && x >= x2) || (x <= x2 && x >= x1)){
				++cnt;
				break;
			}
		}
	}
	printf("%.9lf", 2.0 * n / cnt);
	return 0;
}
