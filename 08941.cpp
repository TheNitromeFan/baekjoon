#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, double> weight = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string mol;
		cin >> mol;
		double ans = 0;
		char elem = mol[0];
		int cnt;
		unsigned i = 1;
		while(i < mol.length()){
			if(mol[i] >= '0' && mol[i] <= '9'){
				cnt = 0;
				while(i < mol.length() && mol[i] >= '0' && mol[i] <= '9'){
					cnt = cnt * 10 + mol[i] - '0';
					++i;
				}
				ans += weight[elem] * cnt;
				if(i < mol.length()){
					elem = mol[i];
					++i;
				}
			}else{
				ans += weight[elem];
				elem = mol[i];
				++i;
			}
		}
		if(!(mol[mol.length() - 1] >= '0' && mol[mol.length() - 1] <= '9')){
			ans += weight[elem];
		}
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
}
