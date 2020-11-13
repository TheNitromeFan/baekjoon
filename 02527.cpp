#include <cstdio>


char cross(long a, long b, long c, long d, long p, long q, long r, long s){
	
	if(c < p || d < q || r < a || s < b) return 'd';
	else if((c == p || r == a) && (d == q || b == s)) return 'c';
	else if(c == p || r == a || d == q || b == s) return 'b';
	else return 'a';
}

int main(void){
	long a, b, c, d, p, q, r, s;
	for(int i = 0; i < 4; i++){
		scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &p, &q, &r, &s);
		printf("%c\n", cross(a, b, c, d, p, q, r, s));
	}
	return 0;
}
