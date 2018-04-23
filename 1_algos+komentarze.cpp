#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[26];//litery
    string text;//wczytany tekst
    string str;//zp dla wczytywania pojedynczych linii
    int min = text.length()+1;//
    int max = 0;
    char chmin, chmax;// najczesciej i najrzadziej wystêpujaca litera

    for(int i = 0; i<26;i++){
        arr[i]=0; //zerowanie elementow tablicy
    }

    while(str[str.length()-1] != '^'){ //poki ostatni znak != ^
        getline(cin, str);      // wczytaj linie
        text+=str;           //zapisz wczytana linie do tekstu
    }
    min = text.length(); 
    max = 0; //zakres liter pod jednym indeksem w arr od 0 do dlugosci tekstu

    int l = text.length()-1; // ^

    for(int i = 0; i < l; i++){
        if(text[i] > 64 && text[i] < 91)  //wielkie litery
            arr[text[i]-'A']++;       
        if(text[i] > 96 && text[i] < 123) //male litery
            arr[text[i]-'a']++;
    }


    for(int i = 0; i < 26; i++){
        if (arr[i] < min && arr[i]!=0) { min = arr[i]; chmin = i; }
        if (arr[i] > max) { max = arr[i]; chmax = i; }
    }

    chmax+=97;  //mala litera
    chmin+=97;

    cout << chmax << " " << chmin << endl;
    return 0;
}
