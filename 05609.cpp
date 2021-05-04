#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int top = 1, front = 2, right = 3, left = 4, back = 5, bottom = 6;
	int n;
	cin >> n;
	int score = 1;
	for(int i = 0; i < n; ++i){
		string move;
		cin >> move;
		if(move == "North"){
			int temp = top;
			top = front;
			front = bottom;
			bottom = back;
			back = temp;
		}else if(move == "South"){
			int temp = top;
			top = back;
			back = bottom;
			bottom = front;
			front = temp;
		}else if(move == "East"){
			int temp = top;
			top = left;
			left = bottom;
			bottom = right;
			right = temp;
		}else if(move == "West"){
			int temp = top;
			top = right;
			right = bottom;
			bottom = left;
			left = temp;
		}else if(move == "Right"){
			int temp = front;
			front = right;
			right = back;
			back = left;
			left = temp;
		}else{
			int temp = front;
			front = left;
			left = back;
			back = right;
			right = temp;
		}
		score += top;
	}
	cout << score;
	return 0;
}
