#include <iostream>
#include <string>

int longest_laugh(std::string s){
	int ret = 0;
	unsigned idx = 0;
	while(idx < s.length()){
		if(s[idx] != 'h' && s[idx] != 'a'){
			++idx;
			continue;
		}
		int cnt = 1;
		++idx;
		while(idx < s.length() && (s[idx] == 'h' || s[idx] == 'a') && s[idx] != s[idx - 1]){
			++cnt;
			++idx;
		}
		if(ret < cnt){
			ret = cnt;
		}
	}
    return ret;
}

int main(){
	std::string s;
	std::cin >> s;
	std::cout << longest_laugh(s);
	return 0;
}
