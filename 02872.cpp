#include <cstdio>
#define MAX 300000

int main(){
	int n;
	scanf("%d", &n);
	int books[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &books[i]);
	}
	int ans = 0, current = n;
	for(int i = n-1; i >= 0; --i){
		if(books[i] == current){
			--current;
		}else{
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
