#include <cstdio>
#include <algorithm>

using std::sort;

int main(){
	int a[4];
	for(int i = 0; i < 4; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + 4);
	printf("%d %d %d %d", a[0], a[2], a[1], a[3]);
	return 0;
}
