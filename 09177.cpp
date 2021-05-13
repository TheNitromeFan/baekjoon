#include <iostream>
#include <string>
#define MAX 210

using namespace std;

bool match(bool visited[][MAX], string &s1, string &s2, string &s3, unsigned idx1, unsigned idx2){
	if(idx1 == s1.length() && idx2 == s2.length()){
		return true;
	}
	if(visited[idx1][idx2]){
		return false;
	}
	visited[idx1][idx2] = true;
	if(idx1 < s1.length() && s1[idx1] == s3[idx1 + idx2] && match(visited, s1, s2, s3, idx1 + 1, idx2)){
		return true;
	}
	if(idx2 < s2.length() && s2[idx2] == s3[idx1 + idx2] && match(visited, s1, s2, s3, idx1, idx2 + 1)){
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		bool visited[MAX][MAX] = {};
		cout << "Data set " << i << ": " << (match(visited, s1, s2, s3, 0, 0) ? "yes" : "no") << "\n";
	}
	return 0;
}
