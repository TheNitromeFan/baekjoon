#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool no_repeating_digits(unsigned n){
	vector<bool> seen(10);
	while(n > 0){
		if(seen[n % 10]){
			return false;
		}
		seen[n % 10] = true;
		n /= 10;
	}
	return true;
}

bool runaround(unsigned n){
	if(!no_repeating_digits(n)){
		return false;
	}
	vector<unsigned> digits;
	while(n > 0){
		digits.push_back(n % 10);
		n /= 10;
	}
	reverse(digits.begin(), digits.end());
	unsigned idx = 0;
	vector<bool> seen(digits.size());
	unsigned cnt = 0;
	seen[idx] = true;
	++cnt;
	while(true){
		idx += digits[idx];
		idx %= digits.size();
		if(seen[idx]){
			break;
		}
		seen[idx] = true;
		++cnt;
	}
	return idx == 0 && cnt == digits.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		unsigned n;
		cin >> n;
		if(n == 0){
			break;
		}
		++t;
		for(unsigned m = n; ; ++m){
			if(runaround(m)){
				cout << "Case " << t << ": " << m << "\n";
				break;
			}
		}
	}
	return 0;
}
