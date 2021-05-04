#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int code;
		cin >> code;
		int ab = code / 100, cd = code % 100;
		if((ab * ab + cd * cd) % 7 == 1){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}
