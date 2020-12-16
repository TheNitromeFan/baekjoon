#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool speak(set<string> &elements, string &word, unsigned pos, vector<bool> &visited){
	if(pos == word.length()){
		return true;
	}
	visited[pos] = true;
	bool ret = false;
	string x;
	x += word[pos];
	if(!visited[pos + 1] && elements.find(x) != elements.end()){
		ret |= speak(elements, word, pos + 1, visited);
	}
	if(pos + 1 < word.length()){
		x += word[pos + 1];
		if(!visited[pos + 2] && elements.find(x) != elements.end()){
			ret |= speak(elements, word, pos + 2, visited);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> elements = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg",
	"al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni",
	"cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru",
	"rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la", "ce", "pr", "nd",
	"pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os",
	"ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u",
	"np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh",
	"hs", "mt", "ds", "rg", "cn", "fl", "lv"};
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string word;
		cin >> word;
		vector<bool> visited(word.length() + 1);
		cout << (speak(elements, word, 0, visited) ? "YES" : "NO") << "\n";
	}
	return 0;
}
