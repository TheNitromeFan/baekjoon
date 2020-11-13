#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int paint = 0;
	if(b < c || d < a){
		paint = b - a + d - c;
	}else{
		paint = max(b, d) - min(a, c);
	}
	printf("%d", paint);
	return 0;
}
