#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<string> vec;
	for(int i = 0; i < n; ++i){
		char chars[51];
		scanf("%s", chars);
		string word(chars);
		vec.push_back(word);
	}
	sort(vec.begin(), vec.end(), [ ](const string &lhs, const string &rhs){
		return (lhs.length() < rhs.length()) || ((lhs.length() == rhs.length()) && lhs.compare(rhs) < 0);
	});
	printf("%s\n", vec[0].c_str());
	for(int i = 1; i < n; ++i){
		if(vec[i] != vec[i-1]){
			printf("%s\n", vec[i].c_str());
		}
	}
	return 0;
}
