#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string bijective_base_26(long long n){
	string ret = "";
	while(n > 0){
		--n;
		ret += (char)('A' + (int)(n % 26));
		n /= 26;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long k;
		scanf("%lld", &k);
		printf("%s\n", bijective_base_26(k).c_str());
	}
	return 0;
}
