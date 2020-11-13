#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int balls[4] = {1, 0, 0, 2};
	string swaps;
	cin >> swaps;
	for(char c : swaps){
		switch(c){
			case 'A':
				swap(balls[0], balls[1]);
				break;
			case 'B':
				swap(balls[0], balls[2]);
				break;
			case 'C':
				swap(balls[0], balls[3]);
				break;
			case 'D':
				swap(balls[1], balls[2]);
				break;
			case 'E':
				swap(balls[1], balls[3]);
				break;
			case 'F':
				swap(balls[2], balls[3]);
				break;
		}
	}
	for(int i = 0; i < 4; ++i){
		if(balls[i] == 1){
			cout << i + 1;
		}
	}
	cout << '\n';
	for(int i = 0; i < 4; ++i){
		if(balls[i] == 2){
			cout << i + 1;
		}
	}
	return 0;
}
