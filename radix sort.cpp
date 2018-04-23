#include <iostream>

using namespace std;

class Wigilia{
	private:
		struct element{ //elementy w ktorych przechowywuje indeksy potraw ktore sortuje
			int indeks;
			element * nastepny;
		};
		string *potrawy;
		int *kaloryjnosc;
		element **tab_mod;
		element **tab_div;
		int n;
		int licznik; 
	public:
		Wigilia(){}
		Wigilia(int);
		void wczytaj();
		void push(string, int);
		void sortuj();
		void wypisz();
};
Wigilia::Wigilia(int n){
	this->n = n;
	licznik = 0;
	potrawy = new string[n];
	kaloryjnosc = new int[n];
	tab_mod = new element*[n];
	tab_div = new element*[n];
	for(int i = 0; i < n; i++){
		tab_mod[i] = 0;
		tab_div[i] = 0;
	}
}

void Wigilia::push(string p, int k){ 
	element *z_p = new element;
	potrawy[licznik] = p;
	kaloryjnosc[licznik] = k;
	z_p->indeks = licznik;
	z_p->nastepny = tab_mod[kaloryjnosc[licznik]%n]; //tab_mod[] wsk na ostatnio dodany el do stosu
	tab_mod[kaloryjnosc[licznik]%n] = z_p; //teraz ten wsk bedzie wskazywac na nowy el          
	//powyzsze 2 linijki dodaja na stos nowy el
	licznik++;
}
void Wigilia::sortuj(){  //sortujemy wzgledem poprzedniego sortowania nie zmieniajac kolejnosci jednakowych elementow  O(n)
	element *z_p;
	for(int i = n-1; i >= 0; i--){
		while(tab_mod[i] != NULL){
			z_p = tab_mod[i]->nastepny;
			tab_mod[i] -> nastepny = tab_div[kaloryjnosc[tab_mod[i]->indeks]/n];
			tab_div[kaloryjnosc[tab_mod[i]->indeks]/n] = tab_mod[i];

			tab_mod[i] = z_p;
		}
	}
}
void Wigilia::wypisz(){
	for(int i = 0; i < licznik; i++){
		while(tab_div[i] != NULL){
			cout << potrawy[tab_div[i]->indeks] << " ";


			tab_div[i] = tab_div[i]->nastepny;

		}
	}
}
void Wigilia::wczytaj(){
	string potr;
	int kal;
	for(int i = 0; i < n; i++){
		cin >> potr;
		cin >> kal;
		push(potr,kal);
	}
	sortuj();
}
int main(){
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	Wigilia w(n);
	w.wczytaj();
	w.wypisz();
	return 0;
}
