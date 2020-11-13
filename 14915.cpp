#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string hexdigits = "0123456789ABCDEF";

string number_to_base(int number, int base){
	string ret;
	while(number){
		ret += hexdigits[number % base];
		number /= base;
	}
	if(ret.empty()){
		ret = "0";
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &m, &n);
	printf("%s", number_to_base(m, n).c_str());
	return 0;
}
