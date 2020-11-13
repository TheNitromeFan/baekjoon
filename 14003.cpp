#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int len = 0;
	static int a[1000000], min[1000001], pred[1000001];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		int low = 1, high = len;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(a[min[mid]] < a[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		int new_len = low;
		pred[i] = min[new_len-1];
		min[new_len] = i;
		if(new_len > len){
			len = new_len;
		}
	}
	printf("%d\n", len);
	static int b[1000000];
	int k = min[len];
	for(int i = len-1; i >= 0; --i){
		b[i] = a[k];
		k = pred[k];
	}
	for(int i = 0; i < len; ++i){
		printf("%d ", b[i]);
	}
	return 0;
}
