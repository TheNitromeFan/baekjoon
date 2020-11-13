#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverse(string &s){
	int n = s.length();
	for(int i = 0; i < n / 2; ++i){
		swap(s[i], s[n - 1 - i]);
	}
}

int main(){
	string a, b;
	cin >> a >> b;
	reverse(a);
	reverse(b);
	string ans;
	int i = 0;
	int carry = 0;
	while(i < a.size() || i < b.size()){
		int digit_sum;
		if(i < a.size() && i < b.size()){
			digit_sum = (a[i] - '0') + (b[i] - '0') + carry;
		}else if(i < a.size()){
			digit_sum = (a[i] - '0') + carry;
		}else{
			digit_sum = (b[i] - '0') + carry;
		}
		if(digit_sum < 10){
			ans += to_string(digit_sum);
			carry = 0;
		}else{
			ans += to_string(digit_sum - 10);
			carry = 1;
		}
		++i;
	}
	if(carry == 1){
		ans += to_string(1);
	}
	reverse(ans);
	cout << ans;
	return 0;
}
