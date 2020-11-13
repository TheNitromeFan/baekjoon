#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	char digit;
	scanf("%d %c", &n, &digit);
	string digits;
	for(int i = 1; i <= n; ++i){
		digits += to_string(i);
	}
	printf("%lld", count(digits.begin(), digits.end(), digit));
	return 0;
}
