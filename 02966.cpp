#include <cstdio>

char adrian(int idx){
	return 'A' + (idx % 3);
}

char bruno(int idx){
	if(idx % 2 == 0){
		return 'B';
	}else if(idx % 4 == 1){
		return 'A';
	}else{
		return 'C';
	}
}

char goran(int idx){
	char ret;
	switch(idx % 6){
		case 0:
		case 1:
			ret = 'C';
			break;
		case 2:
		case 3:
			ret = 'A';
			break;
		default:
			ret = 'B';
			break;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	char answers[101];
	scanf("%s", answers);
	int a = 0, b = 0, g = 0;
	for(int i = 0; i < n; ++i){
		if(answers[i] == adrian(i)){
			++a;
		}
		if(answers[i] == bruno(i)){
			++b;
		}
		if(answers[i] == goran(i)){
			++g;
		}
	}
	if(a == b && b == g){
		printf("%d\nAdrian\nBruno\nGoran", a);
	}else if(a == b && b > g){
		printf("%d\nAdrian\nBruno", a);
	}else if(a == g && a > b){
		printf("%d\nAdrian\nGoran", a);
	}else if(b == g && b > a){
		printf("%d\nBruno\nGoran", b);
	}else if(a > b && a > g){
		printf("%d\nAdrian", a);
	}else if(b > a && b > g){
		printf("%d\nBruno", b);
	}else{
		printf("%d\nGoran", g);
	}
	return 0;
}
