#include <iostream>
#include <string>

using namespace std;

long long base_9_to_10(string &num){
	long long ret = 0;
	for(char c : num){
		ret = ret * 9 + (c - '0');
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string num;
	cin >> num;
	for(char &c : num){
		if(c >= '5'){
			--c;
		}
	}
	cout << base_9_to_10(num);
	return 0;
}
