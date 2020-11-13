#include <cstdio>
#include <cstdlib>
#include <algorithm>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int minPos(int x, int y, int p1, int p2){
	int g = gcd(x, y);
	if(abs(p1 - p2) % g != 0){
		return -1;
	}
	for(int pos = std::max(p1, p2); ; pos += g){
		if((pos - p1) % x == 0 && (pos - p2) % y == 0){
			return pos;
		}
	}
	return -1;
}

int main(){
	int x, y, p1, p2;
	scanf("%d %d %d %d", &x, &y, &p1, &p2);
	printf("%d", minPos(x, y, p1, p2));
	return 0;
}
