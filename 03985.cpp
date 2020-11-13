#include <cstdio>
#include <cstring>
#define MAX (1000 + 1)

int main(){
	int ell;
	scanf("%d", &ell);
	bool walnut[MAX];
	memset(walnut, true, sizeof(walnut));
	int n;
	scanf("%d", &n);
	int p[MAX], k[MAX];
	int expected = 0, expected_max = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &p[i], &k[i]);
		int len = k[i] - p[i] + 1;
		if(len > expected_max){
			expected_max = len;
			expected = i;
		}
	}
	printf("%d\n", expected);
	int actual = 0, actual_max = 0;
	for(int i = 1; i <= n; ++i){
		int taken = 0;
		for(int j = p[i]; j <= k[i]; ++j){
			if(walnut[j]){
				walnut[j] = false;
				++taken;
			}
		}
		if(taken > actual_max){
			actual_max = taken;
			actual = i;
		}
	}
	printf("%d", actual);
	return 0;
}
