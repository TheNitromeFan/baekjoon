#include <cstdio>

char next_day(char d){
	char ret = ' ';
	switch(d){
		case 'o':
			ret = 'u';
			break;
		case 'u':
			ret = 'e';
			break;
		case 'e':
			ret = 'h';
			break;
		case 'h':
			ret = 'r';
			break;
	}
	return ret;
}

int main(){
	int t, n;
	scanf("%d %d", &t, &n);
	for(int i = 0; i < n; ++i){
		char day1[5], day2[5];
		int t1, t2;
		scanf("%s %d %s %d", day1, &t1, day2, &t2);
		char d1 = day1[1], d2 = day2[1];
		while(!(d1 == d2 && t1 == t2)){
			--t;
			if(t1 == 23){
				d1 = next_day(d1);
				t1 = 0;
			}else{
				++t1;
			}
		}
	}
	int sleep = 0;
	if(t > 48){
		sleep = -1;
	}else if(t > 0){
		sleep = t;
	}
	printf("%d", sleep);
	return 0;
}
