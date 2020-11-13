#include <cstdio>
#include <utility>

using namespace std;

int main(){
	int n, q, k;
	scanf("%d %d %d", &n, &k, &q);
	static pair<int, char> messages[10001];
	for(int i = 1; i <= k; ++i){
		scanf("%d %c", &messages[i].first, &messages[i].second);
	}
	if(messages[q].first == 0){
		printf("-1");
		return 0;
	}
	bool has_read[26] = {};
	for(int i = 1; i <= k; ++i){
		if(messages[i].first >= messages[q].first){
			has_read[messages[i].second - 'A'] = true;
		}
	}
	for(int j = 1; j < n; ++j){
		if(!has_read[j]){
			printf("%c ", j + 'A');
		}
	}
	return 0;
}
