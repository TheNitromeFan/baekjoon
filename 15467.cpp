#include <cstdio>
#include <algorithm>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int c[6];
		for(int i = 0; i < 6; ++i){
			scanf("%d", &c[i]);
		}
		std::sort(c, c + 6);
		if((c[0] == c[1] && c[1] == c[2] && c[2] == c[3] && c[4] == c[5])
		|| (c[0] == c[1] && c[2] == c[3] && c[3] == c[4] && c[4] == c[5])){
			printf("tiki pair\n");
		}else if((c[0] == c[1] && c[1] == c[2] && c[2] == c[3])
		|| (c[1] == c[2] && c[2] == c[3] && c[3] == c[4])
		|| (c[2] == c[3] && c[3] == c[4] && c[4] == c[5])){
			printf("tiki\n");
		}else if(c[0] == c[1] && c[1] == c[2] && c[3] == c[4] && c[4] == c[5]){
			printf("two triples\n");
		}else if((c[0] == c[1] && c[1] == c[2] && c[3] == c[4])
		|| (c[0] == c[1] && c[1] == c[2] && c[4] == c[5])
		|| (c[1] == c[2] && c[2] == c[3] && c[4] == c[5])
		|| (c[0] == c[1] && c[2] == c[3] && c[3] == c[4])
		|| (c[0] == c[1] && c[3] == c[4] && c[4] == c[5])
		|| (c[1] == c[2] && c[3] == c[4] && c[4] == c[5])){
			printf("full house\n");
		}else if((c[0] == c[1] && c[1] == c[2])
		|| (c[1] == c[2] && c[2] == c[3])
		|| (c[2] == c[3] && c[3] == c[4])
		|| (c[3] == c[4] && c[4] == c[5])){
			printf("one triple\n");
		}else if(c[0] == c[1] && c[2] == c[3] && c[4] == c[5]){
			printf("three pairs\n");
		}else if((c[0] == c[1] && c[2] == c[3])
		|| (c[0] == c[1] && c[3] == c[4])
		|| (c[0] == c[1] && c[4] == c[5])
		|| (c[1] == c[2] && c[3] == c[4])
		|| (c[1] == c[2] && c[4] == c[5])
		|| (c[2] == c[3] && c[4] == c[5])){
			printf("two pairs\n");
		}else if(c[0] == c[1] || c[1] == c[2] || c[2] == c[3] || c[3] == c[4] || c[4] == c[5]){
			printf("one pair\n");
		}else{
			printf("single\n");
		}
	}
	return 0;
}
