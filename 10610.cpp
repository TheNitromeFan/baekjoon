#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	string s;
	cin >> s;
	int check_sum = 0;
	bool has_zero = false;
	for(char c : s){
		if(c == '0'){
			has_zero = true;
		}
		check_sum = (check_sum + (c - '0')) % 3;
	}
	if(!has_zero || check_sum != 0){
		cout << -1;
	}else{
		sort(s.begin(), s.end(), greater<int>());
		cout << s;
	}
	cout << endl;
	return 0;
}
