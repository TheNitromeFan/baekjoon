#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	vector<bool> ball = {false, true, false, false};
	string moves;
	cin >> moves;
	for(char c : moves){
		switch(c){
			case 'A':
				swap(ball[1], ball[2]);
				break;
			case 'B':
				swap(ball[2], ball[3]);
				break;
			case 'C':
				swap(ball[1], ball[3]);
				break;
		}
	}
	for(int i = 1; i <= 3; ++i){
		if(ball[i]){
			cout << i;
		}
	}
	return 0;
}
