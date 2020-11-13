#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger{
	public:
		string s;
		
		BigInteger() : s(""){
			
		}
		
		BigInteger(string x){
			s = x;
			reverse(s.begin(), s.end());
		}
		
		string toString(){
			string ret = s;
			reverse(ret.begin(), ret.end());
			return ret;
		}
		
		bool operator<(BigInteger x){
			if(s.size() != x.s.size()){
				return s.size() < x.s.size();
			}
			for(int i = (int)s.size() - 1; i >= 0; --i){
				if(s[i] != x.s[i]){
					return s[i] < x.s[i];
				}
			}
			return false;
		}
		
		BigInteger operator+(BigInteger x){
			BigInteger res;
			for(unsigned i = 0, carry = 0; i < s.size() || i < x.s.size() || carry; ++i){
				carry += (i < s.size() ? s[i] - '0' : 0) + (i < x.s.size() ? x.s[i] - '0' : 0);
				res.s += carry % 10 + '0';
				carry /= 10;
			}
			return res;
		}
		
		BigInteger operator*(BigInteger x){
			BigInteger res("0");
			for(unsigned i = 0; i < s.size(); ++i){
				int b = s[i] - '0';
				for(int j = 0; j < b; ++j){
					res = res + x;
				}
				x.s = "0" + x.s;
			}
			return res;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, r;
	cin >> a >> b >> r;
	BigInteger x = BigInteger(a), y = BigInteger(b), z = BigInteger(r);
	if(a == "0" || b == "0"){
		cout << "0";
	}else if(r == "0"){
		cout << "overflow";
	}else if(z < x * y){
		cout << "overflow";
	}else{
		BigInteger prod = x * y;
		cout << ((x * y).toString());
	}
	return 0;
}
