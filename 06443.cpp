#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		sort(word.begin(), word.end());
		set<string> used;
		do{
			if(used.find(word) == used.end()){
				used.insert(word);
				cout << word << '\n';
			}
		}while(next_permutation(word.begin(), word.end()));
	}
	return 0;
}
