#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p;
	cin >> p;
	for(int i = 1; i <= p; ++i){
		int n, m;
		cin >> n >> m;
		vector<string> cnds;
		map<string, int> votes;
		for(int j = 0; j < n; ++j){
			string cnd;
			cin >> cnd;
			votes[cnd] = 0;
			cnds.push_back(cnd);
		}
		for(int k = 1; k <= m; ++k){
			string cnd, place;
			int cnt;
			cin >> cnd >> cnt >> place;
			votes[cnd] += cnt;
		}
		string ans = cnds[0];
		bool tie = false;
		for(int j = 1; j < n; ++j){
			if(votes[ans] < votes[cnds[j]]){
				ans = cnds[j];
				tie = false;
			}else if(votes[ans] == votes[cnds[j]]){
				tie = true;
			}
		}
		if(tie){
			cout << "VOTE " << i << ": THERE IS A DILEMMA\n";
		}else{
			cout << "VOTE " << i << ": THE WINNER IS " << ans << ' ' << votes[ans] << '\n';
		}
	}
	return 0;
}
