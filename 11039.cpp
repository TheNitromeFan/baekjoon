#include <iostream>
#include <vector>
#include <string>

using namespace std;

int tanku(vector<string> &words, int n){
	for(int i = 0; i < n; ++i){
		unsigned len = 0;
		int cnt = 0;
		for(int j = i; j < n; ++j){
			len += words[j].length();
			if(cnt == 4 && len > 7){
				break;
			}else if(cnt == 4 && len == 7){
				++cnt;
				len = 0;
			}else if(cnt == 3 && len > 7){
				break;
			}else if(cnt == 3 && len == 7){
				++cnt;
				len = 0;
			}else if(cnt == 2 && len > 5){
				break;
			}else if(cnt == 2 && len == 5){
				++cnt;
				len = 0;
			}else if(cnt == 1 && len > 7){
				break;
			}else if(cnt == 1 && len == 7){
				++cnt;
				len = 0;
			}else if(cnt == 0 && len > 5){
				break;
			}else if(cnt == 0 && len == 5){
				++cnt;
				len = 0;
			}
			if(cnt == 5){
				break;
			}
		}
		if(cnt == 5){
			return i + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<string> words(n);
		for(int i = 0; i < n; ++i){
			cin >> words[i];
		}
		cout << tanku(words, n) << '\n';
	}
	return 0;
}
