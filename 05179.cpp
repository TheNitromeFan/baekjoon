#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 1; a0 <= k; ++a0){
		int m, n, p;
		cin >> m >> n >> p;
		vector<pair<int, int>> tally(p);
		vector<vector<int>> problems(p);
		for(int i = 0; i < p; ++i){
			problems[i].resize(m);
		}
		for(int a1 = 0; a1 < n; ++a1){
			int part, time, j;
			char problem;
			cin >> part >> problem >> time >> j;
			--part;
			int number = problem - 'A';
			if(j == 1 && problems[part][number] != -1){
				++tally[part].first;
				tally[part].second += time + problems[part][number] * 20;
				problems[part][number] = -1;
			}else if(j == 0 && problems[part][number] != -1){
				++problems[part][number];
			}
		}
		vector<int> participants(p);
		for(int i = 0; i < p; ++i){
			participants[i] = i;
		}
		sort(participants.begin(), participants.end(), [&tally](int x, int y){
			pair<int, int> px = tally[x], py = tally[y];
			return px.first > py.first || (px.first == py.first && px.second < py.second);
		});
		cout << "Data Set " << a0 << ":\n";
		for(int x : participants){
			cout << x + 1 << " " << tally[x].first << " " << tally[x].second << "\n";
		}
		cout << "\n";
	}
	return 0;
}
