#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	long long atk, pow, crit, dmg, spd;
};

long long fight(long long atk, long long pow, long long crit, long long dmg, long long spd){
	return atk * (100 + pow) * ((10000 - 100 * min(crit, 100LL)) + min(crit, 100LL) * dmg) * (100 + spd);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct item a, b, aw, bw;
	cin >> a.atk >> a.pow >> a.crit >> a.dmg >> a.spd;
	cin >> b.atk >> b.pow >> b.crit >> b.dmg >> b.spd;
	cin >> aw.atk >> aw.pow >> aw.crit >> aw.dmg >> aw.spd;
	cin >> bw.atk >> bw.pow >> bw.crit >> bw.dmg >> bw.spd;
	long long cmp1 = fight(a.atk, a.pow, a.crit, a.dmg, a.spd);
	long long cmp2 = fight(a.atk - aw.atk + bw.atk, a.pow - aw.pow + bw.pow, a.crit - aw.crit + bw.crit, a.dmg - aw.dmg + bw.dmg, a.spd - aw.spd + bw.spd);
	long long cmp3 = fight(b.atk, b.pow, b.crit, b.dmg, b.spd);
	long long cmp4 = fight(b.atk - bw.atk + aw.atk, b.pow - bw.pow + aw.pow, b.crit - bw.crit + aw.crit, b.dmg - bw.dmg + aw.dmg, b.spd - bw.spd + aw.spd);
	if(cmp2 > cmp1){
		cout << "+\n";
	}else if(cmp2 < cmp1){
		cout << "-\n";
	}else{
		cout << "0\n";
	}
	if(cmp4 > cmp3){
		cout << "+\n";
	}else if(cmp4 < cmp3){
		cout << "-\n";
	}else{
		cout << "0\n";
	}
	return 0;
}
