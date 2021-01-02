#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string ans;
	string num;
	bool neg = false;
	for(unsigned i = 0; i < s.length(); ++i){
		if(s[i] == '-' || s[i] == '+'){
			if(!neg && num != ""){
				ans += "+" + num;
			}else if(num != ""){
				if(num.length() < 2){
					ans += "-" + num;
				}else if(num[1] == '0' && num.length() >= 3){
					ans += "-";
					ans += num[0];
					ans += "+0+";
					for(unsigned j = 2; j < num.length(); ++j){
						ans += num[j];
					}
				}else{
					ans += "-";
					ans += num[0];
					ans += "+";
					for(unsigned j = 1; j < num.length(); ++j){
						ans += num[j];
					}
				}
			}
			neg = (s[i] == '-');
			num = "";
		}else{
			num += s[i];
		}
	}
	if(!neg){
		ans += "+" + num;
	}else{
		if(num.length() < 2){
			ans += "-" + num;
		}else if(num[1] == '0' && num.length() >= 3){
			ans += "-";
			ans += num[0];
			ans += "+0+";
			for(unsigned j = 2; j < num.length(); ++j){
				ans += num[j];
			}
		}else{
			ans += "-";
			ans += num[0];
			ans += "+";
			for(unsigned j = 1; j < num.length(); ++j){
				ans += num[j];
			}
		}
	}
	cout << ans;
	return 0;
}
