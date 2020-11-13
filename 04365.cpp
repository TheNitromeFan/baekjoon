#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<string> cards(53);

vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
vector<string> faces = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

vector<vector<int>> shuffles;

void initialize(){
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 13; ++j){
			cards[i * 13 + j + 1] = faces[j] + " of " + suits[i];
		}
	}
}

void shuffle(int k){
	vector<string> newCards(53);
	for(int j = 1; j <= 52; ++j){
		newCards[j] = cards[shuffles[k][j]];
	}
	cards = newCards;
}

int main(){
	initialize();
	int n;
	scanf("%d", &n);
	shuffles.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		shuffles[i].resize(53);
		for(int j = 1; j <= 52; ++j){
			scanf("%d", &shuffles[i][j]);
		}
	}
	/*
	for(int j = 1; j <= 52; ++j){
		printf("%s\n", cards[j].c_str());
	}
	*/
	int k;
	while(scanf("%d", &k) == 1){
		shuffle(k);
		for(int j = 1; j <= 52; ++j){
			printf("%s\n", cards[j].c_str());
		}
		printf("\n");
	}
	return 0;
}
