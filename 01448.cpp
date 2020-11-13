#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	static int a[1000000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+n, greater<int>());
	for(int i = 0; i < n-2; ++i){
		for(int j = i+1; j < n-1; ++j){
			if(a[i] < a[j] + a[j+1]){
				printf("%d", a[i] + a[j] + a[j+1]);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
