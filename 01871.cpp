#include <cstdio>
#include <cstdlib>

bool nice(char plate[9]){
	int first = 0, second = 0;
	for(int i = 0; i < 3; ++i){
		first *= 26;
		first += plate[i] - 'A';
	}
	for(int j = 4; j < 8; ++j){
		second *= 10;
		second += plate[j] - '0';
	}
	return abs(first - second) <= 100;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		char plate[9];
		scanf("%s", plate);
		printf("%s\n", nice(plate) ? "nice" : "not nice");
	}
	return 0;
}
