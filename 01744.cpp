#include <cstdio>
#include <algorithm>
#define MAX 10000

using namespace std;

int main(){
	int a[MAX];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int sum = 0;
	int i = 0, j = n - 1;
	for(; i < j; i += 2){
		if(a[i] <= 0 && a[i + 1] <= 0){
			sum += a[i] * a[i + 1];
		}else{
			break;
		}
	}
	for(; j > 0; j -= 2){
		if(a[j] > 1 && a[j - 1] > 1){
			sum += a[j] * a[j - 1];
		}else{
			break;
		}
	}
	for(; i <= j; --j){
		sum += a[j];
	}
	printf("%d", sum);
	return 0;
}
