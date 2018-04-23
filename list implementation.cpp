#include <iostream>

using namespace std ;

class Lista{
public :
	typedef int wartosc ;
private :
	struct element {
		wartosc wart ;
		element * nastepny ;
		element * poprzedni ;
	};
public :
	typedef element * pozycja ;
public :
	pozycja pierwszy ;
	pozycja ostatni ;
public :
	Lista ();
	~ Lista ();
	bool empty ();
	wartosc front ();
	wartosc back ();
	void push_front ( wartosc );
	void push_back ( wartosc );
	void pop_front ();
	void pop_back ();
};

int Lista :: front (){  //zwaraca wartosc pierwszego elementu
	if (empty())
		return 0;
	else
		return pierwszy->wart ;

}

int Lista :: back (){  //zwraca wartosc ostatniego elementu
	if (empty())
		return 0;
	else
		return ostatni->wart ;
}

void Lista :: pop_front (){
	if(!empty()){
        if(pierwszy->nastepny==NULL){
            delete pierwszy;
            pierwszy = NULL;
        }
        else{
            pozycja z_p ;
            z_p = pierwszy;
            pierwszy = z_p->nastepny;
            delete z_p ;
            pierwszy->poprzedni = NULL;
        }
    }
}

void Lista :: pop_back (){   //O(1)
	if(!empty()){

        if(ostatni->poprzedni==NULL){    
            delete ostatni;
            ostatni = NULL;
        }
        else{
            pozycja z_p ;
            z_p = ostatni;
            ostatni = z_p->poprzedni;
            delete z_p ;
            ostatni->nastepny = NULL;
        }
    }
}

void Lista :: push_front(Lista :: wartosc arg ){ //O(1)
	pozycja z_p = new element ;
	if (empty()){
		z_p -> wart = arg ;
		z_p -> poprzedni = NULL ;
		z_p -> nastepny = NULL ;
		pierwszy = z_p ;
		ostatni = z_p ;
	}
	else {
		pierwszy -> poprzedni = z_p ;
		z_p -> nastepny = pierwszy  ;
		z_p -> poprzedni = NULL ;
		z_p -> wart = arg ;
		pierwszy = z_p ;
	}
}

void Lista :: push_back(Lista :: wartosc arg){ //O(1)

	if(empty()){
		push_front(arg);
	}
	else {
        pozycja z_p = new element ;
		ostatni -> nastepny = z_p ;
		z_p -> poprzedni = ostatni ;
		z_p -> nastepny = NULL ;
		z_p -> wart = arg ;
		ostatni = z_p ;
	}
}

bool Lista :: empty (){ //O(1)
	if(pierwszy == NULL || ostatni == NULL)
		return true ;
	else
		return false ;
}

Lista :: Lista(){
    pierwszy = NULL ;
	ostatni = NULL ;
}

Lista :: ~Lista(){
	while(!empty())
		pop_front();
}

class Kuglarz{
private:
	unsigned int N, K, U, Z;
	bool reka;
	Lista kroki_upuszcz;
	Lista zmiana_dloni;
	Lista lewa;
	Lista prawa;
public:
	void wczytaj();
	void wez_pileczki();
	void zongluj();
	Kuglarz();
	void wypisz();
	void zmien_reke();
};

void Kuglarz::wczytaj(){
		cin>>N;
		cin>>K;
		cin>>U;

		int z_p;
		for(int i = 1; i <= U; i++){
			cin >> z_p;
			kroki_upuszcz.push_back(z_p);
		}

		cin>>Z;
		for(int i = 1; i <= Z; i++){
			cin >> z_p;
			zmiana_dloni.push_back(z_p);
		}
}

void Kuglarz::wez_pileczki(){

	if(N%2==0){   //il pileczek w obu dloniach jest taka sama
		for(int i = 1; i <= N/2; i++){
			lewa.push_back(i);

		}
		for(int i = N; i >= N/2 + 1; i--){
			prawa.push_front(i);
		}
	}
	else {
		for(int i = 1; i <= N/2 + 1; i++){
			lewa.push_back(i);
		}
		for(int i = N; i >= N/2 + 2; i--){
			prawa.push_front(i);
		}
	}
}


Kuglarz::Kuglarz(){
	reka = true; //lewa
}
void Kuglarz::zmien_reke(){

	if(reka == true)
		reka = false;
	else
		reka = true;
}


void Kuglarz::zongluj(){
	int z_p;
	for(int i = 1; i <= K; i++){
		if(i%2!=0){
			if(i == zmiana_dloni.front()){
				zmien_reke();
				zmiana_dloni.pop_front();
			}
			if(reka){
				z_p = lewa.back();
				lewa.pop_back();
			}else{
				z_p = prawa.front();
				prawa.pop_front();
			}
			zmien_reke();
		}
		else{
			if(i == kroki_upuszcz.front()){
				kroki_upuszcz.pop_front();
			}
			else{		
				if(reka){
					lewa.push_front(z_p);
				}else{
					prawa.push_back(z_p);
				}
			}			
		}
	}
}
				
void Kuglarz::wypisz(){
	while(lewa.empty()==false){
		cout << lewa.front() << " ";
		lewa.pop_front();
	}
	while(prawa.empty()==false){
		cout << prawa.front() << " ";
		prawa.pop_front();
	}
}


int main(){
	
	//O( ilosc krokow + ilosc upuszczonych pilek + ilosc zmian rak)
	Kuglarz k;
	k.wczytaj();
	k.wez_pileczki();
	k.zongluj();
	k.wypisz();
return 0;
}
