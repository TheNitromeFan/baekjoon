#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int score = 0;
	for(int hole = 1; hole <= n; ++hole){
		int strokes;
		cin >> strokes;
		if(strokes > 7){
			strokes = 7;
		}
		if(hole % 2 == 1){
			score += strokes - 2;
		}else{
			score += strokes - 3;
		}
	}
	cout << score;
	return 0;
}
