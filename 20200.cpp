#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s[101];
	scanf("%s", s);
	int worth = 0;
	int low = 0, high = 0;
	int daily[101] = {};
	for(int i = 0; i < n; ++i){
		if(s[i] == '+'){
			++worth;
			if(worth > high){
				high = worth;
			}
		}else if(s[i] == '-'){
			--worth;
			if(worth < low){
				low = worth;
			}
		}else{
			if(worth == high){
				high = worth + 1;
			}
		}
		daily[i + 1] = worth;
	}
	for(int price = high - 1; price >= low; --price){
		for(int i = 0; i < n; ++i){
			if(daily[i] == price && daily[i + 1] == price + 1){
				printf("/");
			}else if(daily[i] == price && daily[i + 1] == price){
				printf("_");
			}else if(daily[i] == price + 1 && daily[i + 1] == price){
				printf("\\");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
