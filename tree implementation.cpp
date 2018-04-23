#include<iostream>
#include<queue>

using namespace std;

class Drzewo{

private:
	struct drzewo {   //struktura deklarujaca pojedyncze wierzcholki
		char litera;
		int il_miejsc ;
		drzewo * l_syn ;
		drzewo * p_brat;
	};
public:
	typedef drzewo * pozycja; //

private :
	pozycja korzen;
	queue <pozycja> kolejka;   //kolejka ustalajaca porzadek ojcow
public:
	Drzewo();
	~Drzewo();
	void push(char, int);
	void preorder(pozycja);
	void odwiedz(pozycja);
	pozycja getKorzen();
	void deleteDrz(pozycja);
};

Drzewo :: Drzewo(){
	korzen = NULL;
}

Drzewo :: ~Drzewo(){
    if( korzen != NULL)
        deleteDrz(korzen);
}

Drzewo::pozycja Drzewo :: getKorzen(){
	return korzen;
}

void Drzewo :: deleteDrz(pozycja v){ //usuniecie drzewa z pamieci (postorder) usuwamy korzen na sam koniec

    if( v->l_syn != NULL )
        delete(v->l_syn);   //deleteDrz(v->l_syn);
    if( v->p_brat != NULL )
        delete(v->p_brat); //deleteDrz(v->p_brat);
    delete v;
}


void Drzewo :: push(char litera, int il_miejsc){
 

	if(korzen == NULL){

		pozycja z_p = new drzewo;
        z_p -> litera = litera;
        z_p -> il_miejsc = il_miejsc;
        z_p -> l_syn = NULL;
        z_p -> p_brat = NULL;

		korzen = z_p;  //wsk na pierwszy element(korzen)
		kolejka.push(korzen);
	}
	else{
		if(kolejka.front()->il_miejsc != 0){
			if(kolejka.front()->l_syn == 0){

				pozycja z_p = new drzewo;
                z_p -> litera = litera;
                z_p -> il_miejsc = il_miejsc;
                z_p -> l_syn = NULL;
                z_p -> p_brat = NULL;

				kolejka.front()->l_syn = z_p;
				kolejka.push(z_p);
				kolejka.front()->il_miejsc--;
			}
			else{

                pozycja z_p = new drzewo;
                z_p -> litera = litera;
                z_p -> il_miejsc = il_miejsc;
                z_p -> l_syn = NULL;
                z_p -> p_brat = NULL;

				kolejka.back()->p_brat = z_p; //kolejka.back() - ostatnio dodany syn
				kolejka.push(z_p);
				kolejka.front()->il_miejsc--;
			}
		}
		else{
			kolejka.pop();
			push(litera, il_miejsc);
		}
	}
}


void Drzewo :: odwiedz(pozycja v){

		cout<<v->litera;

}
void Drzewo :: preorder(pozycja v){ //O(n)

        odwiedz(v);
        if (v->l_syn != NULL )
            preorder (v->l_syn );
        if (v->p_brat != NULL ) 
            preorder (v->p_brat );

}

int main(){
	//O(k*n)
	int K, N, il_miejsc;
	char litera;
	cin >> K;
	for(int i = 0; i < K; i++){
		Drzewo d;
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> litera;
			cin >> il_miejsc;
			d.push(litera, il_miejsc);

        }
		if(d.getKorzen() != NULL )
            d.preorder(d.getKorzen());
		cout<<endl;
	}

	return 0;
}
