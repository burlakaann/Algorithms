#include<iostream>

using namespace std;

class Graf{
private:

	struct sasiad {
		int v ;
		sasiad * nastepny ;//wsk na nastepna strukture z indeksem sasiada
	};

    typedef sasiad *sasiedzi;

	int liczba_wierzcholkow;
	sasiedzi *wierzcholki;  //tablica list sasiedzi(w tab wsk na pierwszy element listy)
	bool *odwiedzone;
	int il_odw;

public:
	Graf(){}
	void push(int x, int y);
	bool spojnosc();
	void dfs(int v);
	void wyswietl();
	void konstruktor(int liczba_wierzcholkow);
	void usun();
};

void Graf::konstruktor(int liczba_wierzcholkow){
	this->liczba_wierzcholkow = liczba_wierzcholkow;
	wierzcholki = new sasiedzi[liczba_wierzcholkow];
	odwiedzone = new bool[liczba_wierzcholkow];
	for(int i = 0; i < liczba_wierzcholkow; i++){
		wierzcholki[i] = NULL;
		odwiedzone[i] = false;
	}

	il_odw = 0;
}
void Graf::push(int x, int y){  //numery wierzcholkow miedzy ktorymi znajduje sie krawedz

	sasiad *s = new sasiad; 
	s->v = y;
	s->nastepny = wierzcholki[x];
	wierzcholki[x] = s;

	s = new sasiad;
	s->v = x;
	s->nastepny = wierzcholki[y];
	wierzcholki[y] = s;

}
bool Graf::spojnosc(){
	dfs(liczba_wierzcholkow-1); //
	if(liczba_wierzcholkow == il_odw)
		return true;
	return false;
}

void Graf::dfs(int v){ //o(m) il krokow = il krawedzi w spojnej czesci grafu * 2
	sasiad *z_p;
	odwiedzone[v] = true;
	il_odw++;
	while(wierzcholki[v] != NULL){  //  wierzcholki[v] ---- pierwsza struktura listy sasiedzi dla wierzcholka pod numerem v
        if( !odwiedzone[wierzcholki[v]->v] ) //indeks sasiada wierzcholka pod numerem v
			dfs(wierzcholki[v]->v);

		z_p = wierzcholki[v]; //zapamientuje wsk na sprawdzona strukture sasiada zeby ja potem usunac
		wierzcholki[v] = wierzcholki[v]->nastepny; //nastepny z listy sasiedzi danego wierzcholka i przypisuje go do tablicy
		delete z_p;
	}
}

void Graf::usun(){ //O(n + m) bo usuwamy sasiedzi(krawedzie)
	sasiad *z_p;
	for(int i = 0; i < liczba_wierzcholkow; i++){
        if(!odwiedzone[i]){
            while(wierzcholki[i] != NULL){ //sprawdza czy doszlismy do ostatniego elementu w liscie 
            	z_p = wierzcholki[i]->nastepny;
            	delete wierzcholki[i];
            	wierzcholki[i] = z_p;
			}
        }
	}
	delete wierzcholki;
	delete odwiedzone;
}

void Graf::wyswietl(){
	int z, n, m, x, y;
	cin >> z;
	for(int i = 0; i < z; i++){
		cin >> n;
		konstruktor(n);
		cin >> m;

        if( n == m ){ //n = m w grafie spojnym jest tylko jeden cykl //cykl --- sciezka w ktorej na poczatku  na koncu wystepuje ten sam wierzcholek
            for(int i = 0; i < m; i++){
                cin >> x;
                cin >> y;
                push(x,y);
            }


            if( spojnosc() ){
                cout << "TO KARTOFEL" << "\n";
            }
            else {
                cout << "TO NIE KARTOFEL" << "\n";
            }
            usun();
        }else {
            for(int i = 0; i < m; i++){
                cin >> x;
                cin >> y;
            }
            cout << "TO NIE KARTOFEL" << "\n";

        }
	}
}

int main(){
	//O(z*(m+n))
	ios_base::sync_with_stdio(false);
	Graf g;
	g.wyswietl();
}
