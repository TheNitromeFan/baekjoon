#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string num;
		cin >> num;
		if(num == "#"){
			break;
		}
		unsigned r = 0;
		for(unsigned i = 0; i < num.length(); ++i){
			r += (i + 2) * (num[num.length() - 1 - i] - '0');
			r %= 11;
		}
		unsigned check = 11 - r;
		cout << num << " -> ";
		if(check == 11){
			cout << 0;
		}else if(check == 10){
			cout << "Rejected";
		}else{
			cout << check;
		}
		cout << '\n';
	}
	return 0;
}
