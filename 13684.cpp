#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int x0, y0;
		cin >> x0 >> y0;
		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;
			if(x < x0 && y > y0){
				cout << "NO\n";
			}else if(x > x0 && y > y0){
				cout << "NE\n";
			}else if(x > x0 && y < y0){
				cout << "SE\n";
			}else if(x < x0 && y < y0){
				cout << "SO\n";
			}else{
				cout << "divisa\n";
			}
		}
	}
	return 0;
}
