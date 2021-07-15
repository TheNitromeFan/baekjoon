#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(int i = 0; i < n; ++i){
		if(i >= k - 1){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] += 'a' - 'A';
			}else{
				s[i] -= 'a' - 'A';
			}
		}
	}
	cout << s << '\n';
	return 0;
}
