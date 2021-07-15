#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<bool> valid_score(101);
	for(int x = 0; x <= 20; ++x){
		for(int m = 1; m <= 3; ++m){
			valid_score[m * x] = true;
		}
	}
	valid_score[50] = true;
	while(true){
		int n;
		cin >> n;
		if(n <= 0){
			break;
		}
		int c = 0, p = 0;
		for(int d1 = 0; d1 <= n; ++d1){
			for(int d2 = 0; d2 <= n; ++d2){
				int d3 = n - d1 - d2;
				if(d1 <= d2 && d2 <= d3 && d3 <= 100 && valid_score[d1] && valid_score[d2] && valid_score[d3]){
					++c;
				}
			}
		}
		for(int d1 = 0; d1 <= n; ++d1){
			for(int d2 = 0; d2 <= n; ++d2){
				int d3 = n - d1 - d2;
				if(d3 >= 0 && d3 <= 100 && valid_score[d1] && valid_score[d2] && valid_score[d3]){
					++p;
				}
			}
		}
		if(c > 0){
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << ".\n";
		}else{
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
		}
		cout << string(70, '*') << '\n';
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
