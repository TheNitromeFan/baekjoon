#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::fill;

static void singles(const long long m, const long long n, bool (&is_single)[1000001]){
	for(long long j = m/4; 4*j <= n; ++j){
		if(4*j >= m)
			is_single[4*j - m] = false;
	}
	for(long long i = 3; i*i <= n; i += 2){
		for(long long j = m/(i*i); i*i*j <= n; ++j){
			if(i*i*j >= m)
				is_single[i*i*j - m] = false;
		}
	}
}

int main(){
	long long min = 0LL, max = 0LL;
	cin >> min >> max;
	static bool is_single[1000001];
	fill(is_single, is_single+max-min+1, true);
	singles(min, max, is_single);
	int count = 0;
	for(long long i = min; i <= max; ++i){
		if(is_single[i-min])
			++count;
	}
	cout << count;
	return 0;
}
