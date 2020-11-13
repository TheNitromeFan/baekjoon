#include <cstdio>
#include <cstdlib>


long x = 0, y = 0;

void place(long c, long r, long k){
	
	if(k > r*c) return;
	long **seats = (long **)malloc(c * sizeof(long *));
	for(long i = 0; i < c; i++){
		*(seats+i) = (long *)malloc(r * sizeof(long));
		for(long j = 0; j < r; j++) *(*(seats+i)+j) = 0;
	}
	long count = 1;
	int direction = 0;
	while(count < k){
		*(*(seats+x)+y) = count;
		count++;
		if(direction == 0){
            if(y+1 == r || seats[x][y+1] != 0){
                direction = 1;
                x++;
            }else y++;
        }else if(direction == 1){
            if(x+1 == c || seats[x+1][y] != 0){
                direction = 2;
                y--;
            }else x++;
        }else if(direction == 2){
            if(y == 0 || seats[x][y-1] != 0){
                direction = 3;
                x--;
            }else y--;
        }else{
            if(seats[x-1][y] != 0){
                direction = 0;
                y++;
            }else x--;
        }
	}
	x++;
	y++;
	for(long i = 0; i < c; i++) free(*(seats+i));
	free(seats);
}

int main(void){
	
	long c, r, k;
	scanf("%ld %ld %ld", &c, &r, &k);
	place(c, r, k);
	if(x) printf("%ld %ld", x, y);
	else printf("0");
	return 0;
}
