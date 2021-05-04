#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n, m, r, c, s;
		cin >> n >> m >> r >> c >> s;
		if((r - s <= 1 && r + s >= n) || (c - s <= 1 && c + s >= m)
		|| (r - s <= 1 && c - s <= 1) || (r + s >= n && c + s >= m)){
			cout << "Tuzik\n";
		}else{
			cout << "Barsik\n";
		}
	}
	return 0;
}
