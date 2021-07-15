#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool occupied[11][11] = {};
	bool valid = true;
	for(int a0 = 0; a0 < n; ++a0){
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		if(d){
			for(int i = r; i < r + l; ++i){
				if(i <= 10 && !occupied[i][c]){
					occupied[i][c] = true;
				}else{
					valid = false;
				}
			}
		}else{
			for(int j = c; j < c + l; ++j){
				if(j <= 10 && !occupied[r][j]){
					occupied[r][j] = true;
				}else{
					valid = false;
				}
			}
		}
	}
	cout << (valid ? 'Y' : 'N') << '\n';
	return 0;
}
