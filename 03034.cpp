#include <iostream>

using namespace std;

int main(){
	int n, w, h;
	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i){
		int m;
		cin >> m;
		if(m * m <= w * w + h * h){
			cout << "DA" << '\n';
		}else{
			cout << "NE" << '\n';
		}
	}
	return 0;
}
