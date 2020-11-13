#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string x, y, z;
	cin >> x >> y >> z;
	int m = x.size(), n = y.size(), p = z.size();
	static int lcs[101][101][101];
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			for(int k = 0; k <= p; ++k){
				if(i == 0 || j == 0 || k == 0){
					lcs[i][j][k] = 0;
				}else if(x[i-1] == y[j-1] && y[j-1] == z[k-1]){
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}else{
					lcs[i][j][k] = max(max(lcs[i-1][j][k], lcs[i][j-1][k]), lcs[i][j][k-1]);
				}
			}
		}
	}
	cout << lcs[m][n][p];
	return 0;
}
