#include <iostream>

using namespace std;

void no_bingo(int n, int k){
	if(n == 2){
		if(k == 0){
			cout << "YES\n..\n..\n";
		}else if(k == 1){
			cout << "YES\n#.\n..\n";
		}else{
			cout << "NO\n";
		}
		return;
	}
	if(k > n * n - n){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if((i == 1 && j == 1) || (i == n && j == n) || (i > 1 && i < n && i + j == n + 1)){
				cout << '.';
			}else if(k){
				cout << '#';
				--k;
			}else{
				cout << '.';
			}
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	no_bingo(n, k);
	return 0;
}
