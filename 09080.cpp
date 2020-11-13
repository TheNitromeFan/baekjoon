#include <cstdio>

#define REGULAR 1000
#define NIGHT 5000


long min(long a, long b){
	
	if(a < b) return a;
	else return b;
}

long fee(long hour, long minute, long time){
	
	if(time == 0) return 0;
	if(hour >= 24)
		return fee(hour - 24, minute, time);
	long current = 60 * hour + minute;
	if(current < 60 * 8){
		if(current + time <= 60 * 8)
			return min(((time - 1) / 60 + 1) * REGULAR, NIGHT);
		else
			return min(((time - 1) / 60 + 1) * REGULAR, fee(hour, minute, 60 * 8 - current) + fee(8, 0, current + time - 60 * 8));
	}else if(current < 60 * 22){
		if(current + time <= 60 * 22)
			return ((time - 1) / 60 + 1) * REGULAR;
		else
			return min(((time - 1) / 60 + 1) * REGULAR, fee(hour, minute, 60 * 22 - current) + fee(22, 0, current + time - 60 * 22));
	}else{
		if(current + time <= 60 * 32)
			return min(((time - 1) / 60 + 1) * REGULAR, NIGHT);
		else
			return min(((time - 1) / 60 + 1) * REGULAR, fee(hour, minute, 60 * 32 - current) + fee(32, 0, current + time - 60 * 32));
	}
}

int main(void){
	
	int t;
	scanf("%d", &t);
	long h, m, d;
	for(int i = 0; i < t; i++){
		scanf("%ld:%ld %ld", &h, &m, &d);
		printf("%ld\n", fee(h, m, d));
	}
	return 0;
}
