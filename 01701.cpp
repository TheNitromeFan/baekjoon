#include <cstdio>
#define MAX 5002

int main(){
	int pi[MAX] = {};
	char t[MAX];
	scanf("%s", t);
	int ans = 0;
	for(int i = 0; t[i] != '\0'; ++i){
		int k = 0;
		for(int j = i + 1; t[j] != '\0'; ++j){
			while(k > 0 && t[j] != t[i + k]){
				k = pi[k - 1];
			}
			if(t[j] == t[i + k]){
				++k;
				if(ans < k){
					ans = k;
				}
			}
			pi[j - i] = k;
		}
	}
	printf("%d", ans);
	return 0;
}
