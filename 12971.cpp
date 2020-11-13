#include <cstdio>
#include <algorithm>

using std::max;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int minPos(int p1, int p2, int p3, int x1, int x2, int x3){
	int g1 = gcd(p1, p2), g2 = gcd(p2, p3), g3 = gcd(p3, p1);
	if(x1 % g1 != x2 % g1 || x2 % g2 != x3 % g2 || x3 % g3 != x1 % g3){
		return -1;
	}
	int g = gcd(g1, g2);
	for(int x = max(max(x1, x2), x3); ; x += g){
		if(x % p1 == x1 && x % p2 == x2 && x % p3 == x3){
			return x;
		}
	}
	return -1;
}

int main(){
	int p1, p2, p3, x1, x2, x3;
	scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &x1, &x2, &x3);
	printf("%d", minPos(p1, p2, p3, x1, x2, x3));
	return 0;
}
