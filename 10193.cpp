#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string word1, word2;
		cin >> word1 >> word2;
		int coins = 0;
		for(string::size_type j = 0; j < word1.length(); ++j){
			coins += word1[j] - word2[j];
		}
		cout << "Swapping letters to make " << word1 << " look like " << word2;
		if(coins > 0){
			cout << " earned " << coins << " coins.\n";
		}else if(coins < 0){
			cout << " cost " << -coins << " coins.\n";
		}else{
			cout << " was FREE.\n";
		}
	}
	return 0;
}
