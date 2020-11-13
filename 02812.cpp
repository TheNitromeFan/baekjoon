#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	string number;
	cin >> number;
	deque<char> digits;
	for(int i = 0; i < number.length(); ++i){
		while(k > 0 && !digits.empty() && digits.back() < number[i]){
			digits.pop_back();
			--k;
		}
		digits.push_back(number[i]);
	}
	for(int i = 0; i < digits.size() - k; ++i){
		cout << digits[i];
	}
	return 0;
}
