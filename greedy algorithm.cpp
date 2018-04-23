#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

struct Kwiaty{
	int priorytet;
	int liczba;
	bool operator < (const Kwiaty& kw)const{ //bo w porownywaniu elementow wykorzystuje i liczbe kwiatow i ich priorytet
  		if(liczba < kw.liczba)
  			return true;
  		else if(liczba == kw.liczba){
  			if(priorytet < kw.priorytet)
  				return false;
  			else
  				return true;
		  }
		else
			return false;
	}
};

int main(){
	
	//O(suma*w) O(w)
	ios_base::sync_with_stdio(false);
	int r, w;
	Kwiaty n;
	Kwiaty m;
	cin >> r;
	for(int i = 0; i < r; i++){
		priority_queue <Kwiaty> k;
		float suma = 0;
		int max = 0;
		cin >> w;
		for(int j = 0; j < w; j++){
			n.priorytet = j;
			cin >> n.liczba;
			k.push(n);
			suma+=n.liczba;
			if(n.liczba > max){
				max = n.liczba;
			}	
		}
		if(ceil(suma/2 ) >= max){
			n.liczba = 0;
			for(int j = 0; j < suma; j++){
				cout << k.top().priorytet<< " ";
				m = k.top();
				m.liczba--;
				k.pop();
				if(n.liczba!=0){
					k.push(n);
				}
				n = m;
			}
			cout << "\n";
		}
		else 
			cout << "NIE\n";
	}
}
