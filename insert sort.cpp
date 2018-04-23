#include <iostream>
#include <math.h>

using namespace std;

class Dolina{
private:
	struct Para{
		int first;
    	int second;
	};            //struktura dla par liczb
	int N, D; //n = ilosc ciagow, d = dlugosc ciagu
	int rozm_tablicy; 
	Para* tablica;
public:
    void wypisz();
    int dzielnik(Para para);
    void wstaw(Para para, int ile_elementow);
    void wczytaj();
    void wykonaj();
    int znajdz(Para para, int ile_elementow); //  func sprawdzajaca cala tablice przedzialami
};



void Dolina::wypisz()
{

    for (int i = 0; i < rozm_tablicy; i++){

        cout << tablica[i].first << " " << tablica[i].second << " "; 
    }
    cout <<"\n";
}

int Dolina::dzielnik(Para para)
{
    int x = para.second; 
    int pierwiastek = sqrt(x); 
    for (int i = 2; i <= pierwiastek; i++){  
        if ((x%i) == 0){
            return x/i;
        }
    }
    return 1; //jesli liczba nie ma dzielnikow(jest l pierwsza) wroc 1

}

void Dolina::wstaw(Para para, int ile_elementow){ //bo prawie posortowana  //nlog(n)
	
	int start = znajdz(para, ile_elementow); //poczatek przedzialu 
	
    for (int i = start; i < ile_elementow; i++){
        if ((para.first < tablica[i].first) || (para.first == tablica[i].first && dzielnik(para) > dzielnik(tablica[i]))){
            for (int j = ile_elementow; j > i; j--){ //przesuwamy wszystkie elementy zaczynajac od i o jeden w prawo
                tablica[j] = tablica[j - 1];
            }
            tablica[i] = para;
            return;  //jezeli jest taki element to wstawiamy i wychodzimy z metody
        }
    }
    tablica[ile_elementow] = para;  //jesli takiego el nie ma to wstawiamy na koniec tablicy
}


void Dolina::wczytaj(){

	int ile_elementow;
    Para para;

    cin >> this->tablica[0].first; //pierwsza para
    cin >> this->tablica[0].second;

    ile_elementow = 1;

    for (int i = 1; i < rozm_tablicy; i++){
    	cin >> para.first;
        cin >> para.second;
        wstaw(para, ile_elementow);
        ile_elementow++;
    }
}

 void Dolina::wykonaj(){
 	cin >> N;

        for ( int i = 0; i < N; i++){
            cin>>D;
            rozm_tablicy = D / 2;

            tablica = new Para[rozm_tablicy];

            wczytaj();
            wypisz();
            
            delete[] tablica;

        }
 }
 int Dolina::znajdz( Para para, int ile_elementow){ // f robi skoki az w koncu znajdzie liczbe mniejsza od tej ktora potrzebujemy wsawic
	int start = 0;
	int skok = 20; //sprawdzamy cala tablice co 20 elementow(skoki)
	for (int i = ile_elementow-1; i > 0; i = i - skok){  //przeszukuje okreslone odcinki 
		if (para.first > tablica[i].first){  
			start = i; //w tym miejscu ustawia start
			break;
		}
	}
	return start;
}

int main(){
    ios_base::sync_with_stdio(false);

    Dolina dolina;
    dolina.wykonaj();


    return 0;
}
