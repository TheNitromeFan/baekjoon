#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ran(char c){
	int ret = 0;
	switch(c){
		case 'A':
			ret = 1;
			break;
		case 'T':
			ret = 10;
			break;
		case 'J':
			ret = 11;
			break;
		case 'Q':
			ret = 12;
			break;
		case 'K':
			ret = 13;
			break;
		default:
			ret = c - '0';
			break;
	}
	return ret;
}

int main(){
	char card[3];
	vector<int> cnt(14, 0);
	for(int i = 0; i < 5; ++i){
		scanf("%s", card);
		++cnt[ran(card[0])];
	}
	printf("%d", *max_element(cnt.begin(), cnt.end()));
	return 0;
}
