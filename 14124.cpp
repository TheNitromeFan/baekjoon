#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void convert_base(vector<long long> &digits, long long n, int base){
	while(n){
		digits.push_back(n % base);
		n /= base;
	}
	reverse(digits.begin(), digits.end());
}

int complexity(long long n, int base){
	vector<long long> digits;
	convert_base(digits, n, base);
	int ret = 0;
	for(unsigned i = 0; i + 1 < digits.size(); ++i){
		if(digits[i] != digits[i + 1]){
			++ret;
		}
	}
	return ret;
}

int min_complexity(long long n){
	int ans_base = 10, ans_complexity = 1000000000;
	for(int base = 10; base >= 2; --base){
		int c = complexity(n, base);
		if(c < ans_complexity){
			ans_base = base;
			ans_complexity = c;
		}
	}
	return ans_base;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << min_complexity(n) << '\n';
	return 0;
}
