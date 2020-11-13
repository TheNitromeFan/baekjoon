#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x){
			++a;
		}else{
			++b;
		}
	}
	printf("%d", min(a, b));
	return 0;
}
