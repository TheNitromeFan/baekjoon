#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int sumr = 0, sumg = 0, sumb = 0;
		for(int j = 0; j < 10; ++j){
			int r, g, b;
			cin >> r >> g >> b;
			sumr += r;
			sumg += g;
			sumb += b;
		}
		if(sumr % 10 >= 5){
			sumr += 10;
		}
		if(sumg % 10 >= 5){
			sumg += 10;
		}
		if(sumb % 10 >= 5){
			sumb += 10;
		}
		cout << sumr / 10 << ' ' << sumg / 10 << ' ' << sumb / 10 << '\n';
	}
	return 0;
}
