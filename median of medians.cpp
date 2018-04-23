#include<iostream>
#include<algorithm>
using namespace std;

struct element{
	int liczba_krokow;
	string nazwa_miejsca;
	bool operator < (const element& el)const{
		if(liczba_krokow < el.liczba_krokow)
			return false;
		else if(liczba_krokow == el.liczba_krokow){
			if(nazwa_miejsca < el.nazwa_miejsca)
				return false;
			return true;
		}
		else
			return true;
	}
};


element rec(element *tab, int n){
    if(n <= 10){
        sort(tab, tab+n);
        return tab[n/2];
    }
    else{
        int k = n/5;
        element z_p;
        int mod = n%5;
        for(int i = 0; i < k; i++){
            sort(tab + i*5, tab + (i+1)*5);
        	z_p = tab[i];
            tab[i] = tab[i*5+2];
            tab[i*5+2] = z_p;
        }
        if(mod != 0){
            sort(tab + 5*k, tab + n);
            z_p = tab[k];
            tab[k] = tab[k*5 + mod/2 + mod%2 - 1];
            tab[k*5 + mod/2 + mod%2 - 1] = z_p;
            k++;
        }
        return rec(tab, k);
    }
}

element liczniki(element *tab, int n, int szukany){
    
    if(n <= 10){
        sort(tab, tab+n);
        return tab[szukany];
    }
    else{
    	int mniejsze = 0;
    	int rowne = 0;
    	int wieksze = 0;
    	element z_p;
    	int i = 0;
    	element mediana = rec(tab, n);
        while(mniejsze + wieksze + rowne < n){
            if(mediana < tab[i]){
                wieksze++;
                z_p = tab[i];
                tab[i] = tab[n-wieksze];
                tab[n-wieksze] = z_p;
            }
            else if(tab[i] < mediana){
                z_p = tab[i];
                tab[i] = tab[mniejsze];
                tab[mniejsze] = z_p;
                mniejsze++;
                i++;
            }
            else {
                rowne++;
                i++;
            }
        }
        if(szukany < mniejsze){
            return liczniki(tab, mniejsze, szukany);
        }
        else if(szukany < mniejsze + rowne){
            return tab[mniejsze + rowne - 1];
        }
        else if(szukany < n){
            return liczniki(tab + mniejsze + rowne, wieksze, szukany - (mniejsze + rowne));
        }
    }
}
int main(){
	//O(n)
	ios_base::sync_with_stdio(false);
	int N, D, A,*a;
	cin >> N;
	element *tab = new element[N];
	for(int i = 0; i < N; i++){
		cin >> tab[i].nazwa_miejsca;
		cin >> tab[i].liczba_krokow;
	}	  
	cin >> D;
	D/=2;
	cin >> A;
	a = new int[A];
	for(int i = 0; i < A; i++){
		cin >> a[i];
	}
	element e;
	for(int i = 0; i < A; i++){
		e = liczniki(tab, N, a[i]);
		if(D >= e.liczba_krokow ){
			D-= e.liczba_krokow;
			cout << e.nazwa_miejsca << " ";
		}
		else
			cout << "NIE " ;
	}
}
