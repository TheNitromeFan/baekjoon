#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string p1, p2;
		cin >> p1 >> p2;
		if(p1 == "#" && p2 == "#"){
			break;
		}
		int n;
		cin >> n;
		int correct = 0;
		for(int i = 0; i < n; ++i){
			char call, toss;
			cin >> call >> toss;
			if(call == toss){
				++correct;
			}
		}
		cout << p1 << ' ' << correct << ' ' << p2 << ' ' << n - correct << '\n';
	}
	return 0;
}
