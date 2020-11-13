#include <cstdio>


int max_teams(int girls, int boys, int interns){
	
	interns -= girls % 2;
	girls -= girls % 2;
	if(girls - 2 * boys >= interns) return boys;
	else if(boys - girls / 2 >= interns) return girls / 2;
	else if(girls > 2 * boys){
		interns -= girls - 2 * boys;
		girls = 2 * boys;
	}else{
		interns -= boys - girls / 2;
		boys = girls / 2;
	}
	return boys - (interns+2) / 3;
}

int main(void){
	
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	printf("%d", max_teams(m, n, k));
	return 0;
}
