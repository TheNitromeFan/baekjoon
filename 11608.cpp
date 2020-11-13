#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v(26, 0);
	char s[101];
	scanf("%s", s);
	for(int i = 0; s[i] != '\0'; ++i){
		++v[s[i] - 'a'];
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for(int i = 0; i < 24; ++i){
		sum += v[i];
	}
	printf("%d", sum);
	return 0;
}
