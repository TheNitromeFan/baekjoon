#include <cstdio>
#define MAX (10000 + 1)

int main(){
	int n;
	scanf("%d\n", &n);
	char student[MAX], key[MAX];
	for(int i = 0; i < n; ++i){
		scanf(" %c", &student[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf(" %c", &key[i]);
	}
	int score = 0;
	for(int i = 0; i < n; ++i){
		if(student[i] == key[i]){
			++score;
		}
	}
	printf("%d", score);
	return 0;
}
