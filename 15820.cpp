#include <cstdio>

int main(){
	int s1, s2;
	scanf("%d %d", &s1, &s2);
	for(int i = 0; i < s1; ++i){
		int t, m;
		scanf("%d %d", &t, &m);
		if(t != m){
			printf("Wrong Answer");
			return 0;
		}
	}
	for(int i = 0; i < s2; ++i){
		int t, m;
		scanf("%d %d", &t, &m);
		if(t != m){
			printf("Why Wrong!!!");
			return 0;
		}
	}
	printf("Accepted");
	return 0;
}
