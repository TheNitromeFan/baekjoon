#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int arr[10] = {};
	for(int i = 1; i <= n; ++i){
		int num;
		scanf("%d", &num);
		int pos = 0, index = 0;
		while(index < num){
			while(arr[pos] > 0){
				++pos;
			}
			++pos;
			++index;
		}
		while(arr[pos] > 0){
			++pos;
		}
		arr[pos] = i;
	}
	for(int j = 0; j < n; ++j){
		printf("%d ", arr[j]);
	}
	return 0;
}
