#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::swap;

int main(){
	int n;
	scanf("%d", &n);
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	if(r1 > r2){
		swap(r1, r2);
		swap(c1, c2);
	}
	if(r1 % 2 != r2 % 2 || (r2 - r1) / 2 % 2 != abs(c2 - c1) % 2){
		printf("-1");
	}else if((r2 - r1) / 2 <= abs(c2 - c1)){
		printf("%d", (r2 - r1) / 2 + (abs(c2 - c1) - (r2 - r1) / 2) / 2);
	}else{
		printf("%d", (r2 - r1) / 2);
	}
	return 0;
}
