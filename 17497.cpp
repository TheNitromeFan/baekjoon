#include <cstdio>
#include <string>
#include <algorithm>
#define MAX 100

using namespace std;
int main(){
	long long n;
	scanf("%lld", &n);
	string ans;
	while(n){
		if(n & 1){
			ans += '/';
			n *= 2;
		}else if(n & 2){
			ans += '+';
			n -= 2;
		}else{
			ans += '*';
			n /= 2;
		}
	}
	if(ans.length() >= MAX){
		printf("-1");
		return 0;
	}
	printf("%lld\n", ans.length());
	reverse(ans.begin(), ans.end());
	for(char c : ans){
		printf("[%c] ", c);
	}
	return 0;
}
