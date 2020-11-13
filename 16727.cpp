#include <cstdio>

int main(){
	int p1, p2, s1, s2;
	scanf("%d %d %d %d", &p1, &s1, &s2, &p2);
	if(p1 + p2 > s1 + s2){
		printf("Persepolis");
	}else if(p1 + p2 < s1 + s2){
		printf("Esteghlal");
	}else if(p2 > s1){
		printf("Persepolis");
	}else if(p2 < s1){
		printf("Esteghlal");
	}else{
		printf("Penalty");
	}
	return 0;
}
