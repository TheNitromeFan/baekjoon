#include <iostream>
#include <string>

using namespace std;

int roman(string &s){
	string::size_type len = s.length();
	string::size_type idx = 0;
	int ret = 0;
	while(idx < len && s[idx] == 'M'){
		ret += 1000;
		++idx;
	}
	if(idx < len && s[idx] == 'D'){
		ret += 500;
		++idx;
		while(idx < len && s[idx] == 'C'){
			ret += 100;
			++idx;
		}
	}else if(idx < len && s[idx] == 'C'){
		if(idx + 1 < len && s[idx + 1] == 'M'){
			ret += 900;
			idx += 2;
		}else if(idx + 1 < len && s[idx + 1] == 'D'){
			ret += 400;
			idx += 2;
		}else{
			while(idx < len && s[idx] == 'C'){
				ret += 100;
				++idx;
			}
		}
	}
	if(idx < len && s[idx] == 'L'){
		ret += 50;
		++idx;
		while(idx < len && s[idx] == 'X'){
			ret += 10;
			++idx;
		}
	}else if(idx < len && s[idx] == 'X'){
		if(idx + 1 < len && s[idx + 1] == 'C'){
			ret += 90;
			idx += 2;
		}else if(idx + 1 < len && s[idx + 1] == 'L'){
			ret += 40;
			idx += 2;
		}else{
			while(idx < len && s[idx] == 'X'){
				ret += 10;
				++idx;
			}
		}
	}
	if(idx < len && s[idx] == 'V'){
		ret += 5;
		++idx;
		while(idx < len && s[idx] == 'I'){
			ret += 1;
			++idx;
		}
	}else if(idx < len && s[idx] == 'I'){
		if(idx + 1 < len && s[idx + 1] == 'X'){
			ret += 9;
			idx += 2;
		}else if(idx + 1 < len && s[idx + 1] == 'V'){
			ret += 4;
			idx += 2;
		}else{
			while(idx < len && s[idx] == 'I'){
				ret += 1;
				++idx;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		cout << roman(s) << '\n';
	}
	return 0;
}
