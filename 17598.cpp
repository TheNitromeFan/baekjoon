#include <cstdio>

int main(){
	int lion = 0, tiger = 0;
	for(int i = 0; i < 9; ++i){
		char c[6];
		scanf("%s", c);
		if(c[0] == 'L'){
			++lion;
		}else{
			++tiger;
		}
	}
	printf("%s", lion > tiger ? "Lion" : "Tiger");
	return 0;
}
