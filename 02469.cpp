#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void change_cols(string &players, string &ladder, int n){
	for(int i = 0; i < n - 1; ++i){
		if(ladder[i] == '-'){
			swap(players[i], players[i + 1]);
		}
	}
}

string row(string &players1, string &players2, int n){
	string ans = "";
	int i = 0;
	while(i < n - 1){
		if(players1[i] == players2[i]){
			ans += "*";
		}else if(players1[i] == players2[i + 1] && players1[i + 1] == players2[i]){
			if(i == n - 2){
				ans += "-";
			}else{
				ans += "-*";
				++i;
			}
		}else{
			return string(n - 1, 'x');
		}
		++i;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	string start, end;
	for(int i = 0; i < k; ++i){
		start += (char)('A' + i);
	}
	cin >> end;
	string ladder[1001];
	int idx = -1;
	for(int j = 0; j < n; ++j){
		cin >> ladder[j];
		if(ladder[j][0] == '?'){
			idx = j;
		}
	}
	for(int j = 0; j < idx; ++j){
		change_cols(start, ladder[j], k);
	}
	for(int j = n - 1; j > idx; --j){
		change_cols(end, ladder[j], k);
	}
	// cout << start << ' ' << end << '\n';
	cout << row(start, end, k);
	return 0;
}
