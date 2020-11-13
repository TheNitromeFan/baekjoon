#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	getline(cin, line);
	int probs = 0;
	while(true){
		getline(cin, line);
		if(line == "고무오리 디버깅 끝"){
			break;
		}else if(line == "문제"){
			++probs;
		}else if(probs > 0){
			--probs;
		}else{
			probs += 2;
		}
	}
	if(probs == 0){
		cout << "고무오리야 사랑해";
	}else{
		cout << "힝구";
	}
	return 0;
}
