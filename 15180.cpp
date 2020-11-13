#include <cstdio>

int main(){
	int stat[9] = {};
	int pos;
	scanf("%d", &pos);
	++stat[pos];
	printf("%d", pos);
	int nstat = 1;
	while(true){
		char move[3];
		scanf("%s", move);
		if(move[0] == '#'){
			break;
		}
		if(move[0] == 'C'){
			pos += move[1] - '0';
			if(pos > 8){
				pos -= 8;
			}
		}else{
			pos -= move[1] - '0';
			if(pos < 1){
				pos += 8;
			}
		}
		if(stat[pos] == 0){
			++nstat;
		}else if(stat[pos] == 1){
			nstat = 9;
		}
		++stat[pos];
		printf(" %d", pos);
	}
	if(nstat > 8 || nstat < 5){
		printf(" reject");
	}
	return 0;
}
