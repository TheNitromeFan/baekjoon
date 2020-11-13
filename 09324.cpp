#include <iostream>
#include <string>

using namespace std;

bool authentic(string message){
	int uses[26] = {};
	int i = 0;
	while(i < message.length()){
		++uses[message[i] - 'A'];
		if(uses[message[i] - 'A'] % 3 == 0){
			if(i+1 < message.length() && message[i+1] == message[i]){
				++i;
			}else{
				return false;
			}
		}
		++i;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string message;
		cin >> message;
		if(authentic(message)){
			cout << "OK\n";
		}else{
			cout << "FAKE\n";
		}
	}
	return 0;
}
