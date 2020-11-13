#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string moves;
	cin >> moves;
	bool has_ball[4] = {};
	has_ball[1] = true;
	for(char c : moves){
		if(c == 'A'){
			swap(has_ball[1], has_ball[2]);
		}else if(c == 'B'){
			swap(has_ball[2], has_ball[3]);
		}else{
			swap(has_ball[1], has_ball[3]);
		}
	}
	for(int i = 1; i <= 3; ++i){
		if(has_ball[i]){
			cout << i;
		}
	}
	return 0;
}
