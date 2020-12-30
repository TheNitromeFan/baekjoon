#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int highest = 0, current = 0;
	for(char c : s){
		if(c == '['){
			current += 3;
		}else if(c == '{'){
			current += 2;
		}else if(c == '('){
			current += 1;
		}else if(c == ')'){
			current -= 1;
		}else if(c == '}'){
			current -= 2;
		}else if(c == ']'){
			current -= 3;
		}else{
			if(highest < current){
				highest = current;
			}
		}
	}
	cout << highest;
	return 0;
}
