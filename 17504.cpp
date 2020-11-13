#include <cstdio>
#include <stack>

int main(){
	std::stack<long long> fr;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		fr.push(1);
		fr.push(x);
	}
	while(fr.size() >= 4){
		long long c = fr.top();
		fr.pop();
		long long b = fr.top();
		fr.pop();
		long long a = fr.top();
		fr.pop();
		fr.pop();
		fr.push(c);
		fr.push(a * c + b);
	}
	long long q = fr.top();
	fr.pop();
	long long p = fr.top();
	fr.pop();
	printf("%lld %lld", q - p, q);
	return 0;
}
