#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	string x, y;
	cin >> x >> y;
	int m = x.size(), n = y.size();
	static int lcs[1001][1001];
	static string s[1001][1001];
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
			}else if(x[i-1] == y[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
				s[i][j] = s[i-1][j-1] + x[i-1];
			}else{
				if(lcs[i-1][j] > lcs[i][j-1]){
					lcs[i][j] = lcs[i-1][j];
					s[i][j] = s[i-1][j];
				}else{
					lcs[i][j] = lcs[i][j-1];
					s[i][j] = s[i][j-1];
				}
			}
		}
	}
	cout << lcs[m][n] << '\n' << s[m][n];
	return 0;
}
