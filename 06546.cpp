#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dx[4] = {10, 0, -10, 0};
	int dy[4] = {0, 10, 0, -10};
	string folds;
	while(cin >> folds){
		int x = 300, y = 420;
		cout << x << ' ' << y << ' ' << "moveto\n";
		int dir = 0;
		x += dx[dir];
		y += dy[dir];
		cout << x << ' ' << y << ' ' << "lineto\n";
		for(char fold : folds){
			if(fold == 'V'){
				dir = (dir + 1) % 4;
			}else{
				dir = (dir + 3) % 4;
			}
			x += dx[dir];
			y += dy[dir];
			cout << x << ' ' << y << ' ' << "lineto\n";
		}
		cout << "stroke\nshowpage\n";
	}
	return 0;
}
