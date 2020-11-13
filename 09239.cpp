#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ten_powers[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string x;
	cin >> x;
	int p = 0, q = 1;
	bool dec = false;
	for(char c : x){
		if(c == '.'){
			dec = true;
			continue;
		}
		p = 10 * p + c - '0';
		if(dec){
			q *= 10;
		}
	}
	int g = gcd(p, q);
	q /= g;
	p /= g;
	vector<int> ans;
	for(int b = 1; b < 10; ++b){
		if(b * p == b * q){
			ans.push_back(b);
		}
	}
	for(int n = 2; n <= 8; ++n){
		for(int a = 1; a < 10; ++a){
			int inc = gcd(q, ten_powers[n - 1]);
			for(int b = inc; b < ten_powers[n - 1]; b += inc){
				if((ten_powers[n - 1] * a + b) * p == (10 * b + a) * q){
					ans.push_back(ten_powers[n - 1] * a + b);
				}
			}
		}
	}
	if(ans.size() == 0){
		cout << "No solution";
		return 0;
	}
	for(auto x : ans){
		cout << x << '\n';
	}
	return 0;
}
