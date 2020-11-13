#include "timecard.h"

static int N;

void init(int n) {
	N = n;
}

std::string convert(std::string s) {
	std::string ret = "";
	for(char c : s){
		if(c >= 'A' && c <= 'Z'){
			ret += c + ('a' - 'A');
		}else{
			ret += c;
		}
	}
	return ret;
}

