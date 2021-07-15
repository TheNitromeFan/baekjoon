#include <iostream>
#include <algorithm>

using namespace std;

int max_power(long long a, long long b, int p){
	int ret = 0;
	int cnt = 0;
	long long pow = 1;
	while(pow <= b){
		++cnt;
		pow *= p;
		if(b / pow != (a - 1) / pow){
			ret = cnt;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	cout << min(max_power(a, b, 2), max_power(a, b, 5)) << '\n';
	return 0;
}
