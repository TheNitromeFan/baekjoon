#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> v;
	int number = 0;
	int result = 0;
	bool minus_flag = false;
	for(char c : s){
		if(c != '+' && c != '-'){
			number = number * 10 + (c - '0');
		}
		else{
			if(minus_flag){
				result -= number;
			}else{
				result += number;
			}
			if(c == '-'){
				minus_flag = true;
			}
			number = 0;
		}
	}
	if(minus_flag){
		result -= number;
	}else{
		result += number;
	}
	cout << result << endl;
	return 0;
}
