#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int t[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &t[i]);
	}
	bool a[100000] = {};
	int max_period = 0;
	int i = 0;
	int periods[100000] = {};
	while(i < n){
		while(i < n && t[i] >= 0){
			++i;
		}
		int start = i;
		while(i < n && t[i] < 0){
			++i;
		}
		int end = i;
		periods[start] = end - start;
		if(max_period < periods[start]){
			max_period = periods[start];
		}
	}
	// printf("%d\n", max_period);
	int cnt = 0;
	for(i = 0; i < n; ++i){
		if(periods[i] > 0){
			for(int j = i - 1, k = 0; j >= 0 && k < 2 * periods[i]; --j, ++k){
				if(!a[j]){
					++cnt;
					a[j] = true;
				}
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	*/
	int max_add = 0;
	for(int i = 0; i < n; ++i){
		if(periods[i] == max_period){
			// printf("%d\n", i);
			int add = 0;
			for(int j = i - 1, k = 0; j >= 0 && k < 3 * periods[i]; --j, ++k){
				if(!a[j]){
					// printf("\n%d\n", j);
					++add;
				}
			}
			if(max_add < add){
				max_add = add;
			}
		}
	}
	printf("%d", cnt + max_add);
	return 0;
}
