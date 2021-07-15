#include <iostream>
#include <vector>

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
		for(int i = 0; i < n; ++i){
			vector<bool> v(5);
			for(int j = 0; j < 5; ++j){
				int x;
				cin >> x;
				v[j] = (x <= 127);
			}
			if(v[0] && !v[1] && !v[2] && !v[3] && !v[4]){
				cout << 'A' << '\n';
			}else if(!v[0] && v[1] && !v[2] && !v[3] && !v[4]){
				cout << 'B' << '\n';
			}else if(!v[0] && !v[1] && v[2] && !v[3] && !v[4]){
				cout << 'C' << '\n';
			}else if(!v[0] && !v[1] && !v[2] && v[3] && !v[4]){
				cout << 'D' << '\n';
			}else if(!v[0] && !v[1] && !v[2] && !v[3] && v[4]){
				cout << 'E' << '\n';
			}else{
				cout << '*' << '\n';
			}
		}
	}
	return 0;
}
