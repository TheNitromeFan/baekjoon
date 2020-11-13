#include <iostream>
#include <string>
#include <algorithm>
#define MAX 9999999

using namespace std;

bool is_not_prime[MAX+1];

void sieve(){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(int m = 2; m * 2 <= MAX; ++m){
		is_not_prime[m * 2] = true;
	}
	for(int p = 3; p * p <= MAX; p += 2){
		for(int m = p; m * p <= MAX; m += 2){
			is_not_prime[m * p] = true;
		}
	}
}

int ways(string s){
	int ret = 0;
	bool checked[MAX+1] = {};
	for(int len = 1; len <= s.length(); ++len){
		string bitmask(len, 1);
		bitmask.resize(s.length(), 0);
		do{
			string t;
			for(int i = 0; i < s.length(); ++i){
				if(bitmask[i]){
					t += s[i];
				}
			}
			sort(t.begin(), t.end());
			do{
				int j = stoi(t);
				if(!checked[j] && !is_not_prime[j]){
					checked[j] = true;
					++ret;
				}
			}while(next_permutation(t.begin(), t.end()));
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	return ret;
}

int main(){
	sieve();
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		cout << ways(s) << '\n';
	}
	return 0;
}
