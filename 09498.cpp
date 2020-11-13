#include <cstdio>


char grade(int n){
	
	if(n >= 90) return 'A';
	else if(n >= 80) return 'B';
	else if(n >= 70) return 'C';
	else if(n >= 60) return 'D';
	else return 'F';
}

int main(void){
	
	int score;
	scanf("%d", &score);
	printf("%c", grade(score));
	return 0;
}
