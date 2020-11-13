#include <cstdio>
#include <algorithm>
#define MAX (100000 + 1)

using namespace std;

int squares(int n){
	int terms[MAX] = {};
	for(int i = 0; i <= n; ++i){
		terms[i] = i;
		for(int j = 1; j * j <= i; ++j){
			if(terms[i] > terms[i - j * j] + 1){
				terms[i] = terms[i - j * j] + 1;
			}
		}
	}
	return terms[n];
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", squares(n));
	return 0;
}
