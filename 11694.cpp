#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	int res = 0;
	int piles = 0;
	bool flag = false;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		res ^= v[i];
		if(v[i] == 1){
			++piles;
		}else{
			flag = true;
		}
	}
	if(!flag){
		cout << (piles % 2 == 1 ? "cubelover" : "koosaga");
	}else if(piles > 0){
		if(piles % 2 == 1){
			cout << (res == 0 ? "cubelover" : "koosaga");
		}else{
			for(int i = 0; i < n; ++i){
				if(v[i] != 1){
					v[i] = 1;
					break;
				}
			}
			res = 0;
			for(int i = 0; i < n; ++i){
				res ^= v[i];
			}
			cout << (res == 0 ? "cubelover" : "koosaga");
		}
	}else{
		cout << (res == 0 ? "cubelover" : "koosaga");
	}
	return 0;
}
