#include <iostream>
#include <string>
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
		vector<string> cards(n, "");
		for(int idx = 0; idx < n; ++idx){
			cin >> cards[idx];
		}
		int i = 0, j = (n % 2 == 0) ? n / 2 : n / 2 + 1;
		for(int idx = 0; idx < n; ++idx){
			if(idx % 2 == 0){
				cout << cards[i] << '\n';
				++i;
			}else{
				cout << cards[j] << '\n';
				++j;
			}
		}
	}
	return 0;
}
