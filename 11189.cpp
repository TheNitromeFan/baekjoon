#include <iostream>
#include <string>

using namespace std;

void adjust(char &c){
	if(c == 'U'){
		c = 'D';
	}else{
		c = 'U';
	}
}

int main(){
	char state;
	cin >> state;
	string seq;
	cin >> seq;
	char state1 = state, state2 = state, state3 = state;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(char c : seq){
		if(c != state1){
			++cnt1;
			adjust(state1);
		}
		if(state1 == 'D'){
			++cnt1;
			adjust(state1);
		}
		if(c != state2){
			++cnt2;
			adjust(state2);
		}
		if(state2 == 'U'){
			++cnt2;
			adjust(state2);
		}
		if(c != state3){
			++cnt3;
			adjust(state3);
		}
	}
	cout << cnt1 << '\n' << cnt2 << '\n' << cnt3;
	return 0;
}
