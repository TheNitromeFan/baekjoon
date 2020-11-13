#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string message;
	getline(cin, message);
	int happy = 0, sad = 0;
	for(unsigned i = 0; i + 2 < message.length(); ++i){
		if(message[i] == ':' && message[i + 1] == '-' && message[i + 2] == ')'){
			++happy;
		}else if(message[i] == ':' && message[i + 1] == '-' && message[i + 2] == '('){
			++sad;
		}
	}
	if(happy == 0 && sad == 0){
		cout << "none";
	}else if(happy == sad){
		cout << "unsure";
	}else if(happy > sad){
		cout << "happy";
	}else if(sad > happy){
		cout << "sad";
	}
	return 0;
}
