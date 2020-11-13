#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int a0 = 0; a0 < n; ++a0){
		int charCnt = 0, recCnt = 0;
		while(true){
			getline(cin, line);
			if(line == ""){
				break;
			}
			for(char c: line){
				++charCnt;
				if(c != '#'){
					++recCnt;
				}
			}
		}
		double ratio = round(recCnt * 100.0 / charCnt * 10) / 10;
		if(ratio == (int)ratio){
			cout << "Efficiency ratio is " << (int)ratio << "%.\n";
		}else{
			cout << "Efficiency ratio is " << fixed << setprecision(1) << ratio << "%.\n";
		}
	}
	return 0;
}
