#include <cstdio>
#include <map>

using namespace std;

map<long long, long long> fibs;

long long fibonacci(long long x){
	if(x == 0){
		return 0;
	}else if(x == 1 || x == 2){
		return 1;
	}else if(fibs.find(x) != fibs.end()){
		return fibs[x];
	}else if(x % 2 == 0){
		long long y = x / 2;
		fibs[x] = (fibonacci(y-1) + fibonacci(y+1)) * fibonacci(y);
	}else{
		long long y = x / 2;
		long long tmp1 = fibonacci(y), tmp2 = fibonacci(y+1);
		fibs[x] = tmp1 * tmp1 + tmp2 * tmp2;
	}
	return fibs[x];
}

int main(){
	int a, b, c;
	while(true){
		fibs.clear();
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0){
			break;
		}
		printf("%lld\n", fibonacci(c) * a + fibonacci(c+1) * b);
	}
	return 0;
}
