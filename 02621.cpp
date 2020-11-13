#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
	return a.second < b.second;
}

int points(vector<pair<char, int>> &cards){
	sort(cards.begin(), cards.end(), cmp);
	if(cards[0].first == cards[1].first && cards[1].first == cards[2].first && cards[2].first == cards[3].first && cards[3].first == cards[4].first
	&& cards[0].second + 1 == cards[1].second && cards[1].second + 1 == cards[2].second && cards[2].second + 1 == cards[3].second && cards[3].second + 1 == cards[4].second){
		return 900 + cards[4].second;
	}else if((cards[0].second == cards[1].second && cards[1].second == cards[2].second && cards[2].second == cards[3].second)
	|| (cards[1].second == cards[2].second && cards[2].second == cards[3].second && cards[3].second == cards[4].second)){
		return 800 + cards[1].second;
	}else if(cards[0].second == cards[1].second && cards[1].second == cards[2].second && cards[3].second == cards[4].second){
		return 700 + 10 * cards[2].second + cards[4].second;
	}else if(cards[0].second == cards[1].second && cards[2].second == cards[3].second && cards[3].second == cards[4].second){
		return 700 + 10 * cards[2].second + cards[0].second;
	}else if(cards[0].first == cards[1].first && cards[1].first == cards[2].first && cards[2].first == cards[3].first && cards[3].first == cards[4].first){
		return 600 + cards[4].second;
	}else if(cards[0].second + 1 == cards[1].second && cards[1].second + 1 == cards[2].second && cards[2].second + 1 == cards[3].second && cards[3].second + 1 == cards[4].second){
		return 500 + cards[4].second;
	}else if((cards[0].second == cards[1].second && cards[1].second == cards[2].second)
	|| (cards[1].second == cards[2].second && cards[2].second == cards[3].second)
	|| (cards[2].second == cards[3].second && cards[3].second == cards[4].second)){
		return 400 + cards[2].second;
	}else if((cards[0].second == cards[1].second && cards[2].second == cards[3].second)
	|| (cards[0].second == cards[1].second && cards[3].second == cards[4].second)
	|| (cards[1].second == cards[2].second && cards[3].second == cards[4].second)){
		return 300 + 10 * cards[3].second + cards[1].second;
	}else if(cards[0].second == cards[1].second || cards[1].second == cards[2].second){
		return 200 + cards[1].second;
	}else if(cards[2].second == cards[3].second || cards[3].second == cards[4].second){
		return 200 + cards[3].second;
	}else{
		return 100 + cards[4].second;
	}
}

int main(){
	vector<pair<char, int>> cards;
	cards.resize(5);
	for(int i = 0; i < 5; ++i){
		char card[6];
		fgets(card, 5, stdin);
		cards[i].first = card[0];
		cards[i].second = card[2] - '0';
	}
	printf("%d", points(cards));
	return 0;
}
