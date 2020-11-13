#include <iostream>
#include <iomanip>
#include <string>
#define MOD 10000

using namespace std;

string s = "welcome to code jam";

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int a0 = 1; a0 <= n; ++a0){
		getline(cin, line);
		int a[501][20] = {}; // a[m][n]: how many times s[0:n] appears in a[0:m]
		a[0][0] = 1;
		for(unsigned i = 0; i < line.length(); ++i){
			for(unsigned j = 0; j < 20; ++j){
				a[i + 1][j] += a[i][j];
				a[i + 1][j] %= MOD;
				if(j < 19 && line[i] == s[j]){
					// cout << i << " " << j << "\n";
					a[i + 1][j + 1] += a[i][j];
					a[i + 1][j + 1] %= MOD;
				}
				// cout << a[i][j] << " ";
			}
			// cout << "\n";
		}
		cout << "Case #" << a0 << ": " << setw(4) << setfill('0') << a[line.length()][19] << "\n";
	}
	return 0;
}
