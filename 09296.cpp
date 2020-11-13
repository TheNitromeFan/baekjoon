#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int ell;
		scanf("%d", &ell);
		char key[101], student[101];
		scanf("%s", key);
		scanf("%s", student);
		int cnt = 0;
		for(int i = 0; i < ell; ++i){
			if(key[i] != student[i]){
				++cnt;
			}
		}
		printf("Case %d: %d\n", a0, cnt);
	}
	return 0;
}
