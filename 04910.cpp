#include <iostream>
#include <string>

using namespace std;

int remainder_by_11(string s){
	int ans = 0;
	for(unsigned i = 0; i < s.length(); ++i){
		if(i % 2 == 0){
			ans += s[i] - '0';
		}else{
			ans += 11 - (s[i] - '0');
		}
		ans %= 11;
	}
	if(s.length() % 2 == 0){
		ans = 11 - ans;
	}
	return ans % 11;
}

string divide_by_11(string s){
	string ret = "";
	int quot = 0;
	for(unsigned i = 0; i < s.length(); ++i){
		quot = quot * 10 + s[i] - '0';
		if(ret == "" && quot / 11 == 0){
			continue;
		}
		ret += (char)(quot / 11 + '0');
		quot %= 11;
	}
	return ret;
}

string phone(string s){
	int rem = remainder_by_11(s);
	if(rem == 0){
		return "IMPOSSIBLE";
	}
	if(s.length() % 2 == 0){
		rem = 11 - rem;
	}
	string ret = divide_by_11(to_string(rem) + s);
	// cout << ret << "\n";
	return ret.length() == s.length() ? ret : "IMPOSSIBLE";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int t = 0;
	while(true){
		cin >> s;
		if(s == "0"){
			break;
		}
		++t;
		cout << t << ". " << phone(s) << "\n";
	}
	return 0;
}
