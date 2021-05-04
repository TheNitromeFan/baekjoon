#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string answer;
	cin >> answer;
	int m;
	cin >> m;
	vector<string> students(m);
	vector<int> correct(m), incorrect(m);
	for(int i = 0; i < m; ++i){
		cin >> students[i];
		for(int j = 0; j < n; ++j){
			if(students[i][j] == answer[j]){
				++correct[i];
			}else{
				++incorrect[i];
			}
		}
	}
	vector<pair<int, int>> cheated;
	for(int i1 = 0; i1 < m; ++i1){
		for(int i2 = 0; i2 < i1; ++i2){
			int correct_match = 0, incorrect_match = 0;
			for(int j = 0; j < n; ++j){
				if(students[i1][j] == students[i2][j]){
					if(students[i1][j] == answer[j]){
						++correct_match;
					}else{
						++incorrect_match;
					}
				}
			}
			if(2 * correct_match > correct[i1] && 2 * incorrect_match > incorrect[i1]
			&& 2 * correct_match > correct[i2] && 2 * incorrect_match > incorrect[i2]){
				cheated.push_back(make_pair(i2 + 1, i1 + 1));
			}
		}
	}
	cout << cheated.size() << '\n';
	for(pair<int, int> &p : cheated){
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}
