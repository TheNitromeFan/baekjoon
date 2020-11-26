#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int sum_of_squares_of_digits(int n, int base){
	int ret = 0;
	while(n > 0){
		ret += (n % base) * (n % base);
		n /= base;
	}
	return ret;
}

bool happy(int n, int base){
	set<int> seen;
	while(true){
		if(n == 1){
			return true;
		}else if(seen.find(n) != seen.end()){
			return false;
		}
		seen.insert(n);
		n = sum_of_squares_of_digits(n, base);
	}
	return false;
}

bool happy_in_all_bases(vector<int> &bases, int n){
	for(int base : bases){
		if(!happy(n, base)){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for(int a0 = 1; a0 <= t; ++a0){
		getline(cin, s);
		vector<int> bases;
		for(unsigned i = 0; i < s.length(); ++i){
			if(s[i] == ' '){
				continue;
			}else if(s[i] == '1'){
				bases.push_back(10);
				++i;
			}else{
				bases.push_back(s[i] - '0');
			}
		}
		int n = 2;
		while(!happy_in_all_bases(bases, n)){
			++n;
		}
		cout << "Case #" << a0 << ": " << n << "\n";
	}
	return 0;
}
