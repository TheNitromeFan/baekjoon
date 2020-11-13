#include <cstdio>
#include <algorithm>

int steps(int n, int m){
	if(n == 1){
		return 1;
	}else if(n == 2){
		return std::min(4, (m + 1) / 2);
	}
	if(m == 1){
		return 1;
	}else if(m == 2){
		return 2;
	}else if(m <= 6){
		return std::min(4, m);
	}
	return m - 2;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", steps(n, m));
	return 0;
}
