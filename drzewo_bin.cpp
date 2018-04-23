#include<iostream>

using namespace std;

class Drzewo{
private:
	char *drzewo;
	int n;
	int size;
public:
	void push(char);
	void pop();
	Drzewo(){}
	Drzewo(int);
	~Drzewo();
	char rozszyfruj(string);
	string szyfruj(char);
};

Drzewo::Drzewo(int size){
	n = 1;
	this->size = size;
	drzewo = new char[size+1];
}
Drzewo::~Drzewo(){
	delete drzewo;
}
void Drzewo::push(char litera){
	drzewo[n] = litera;
	n++;
}

void Drzewo::pop(){
	n--;
}

char Drzewo::rozszyfruj(string s){
	int index = 0 ;
	for(int i = 0; i < s.length(); i++){
		index = index*2+1+(int)s[i]-48;
	}
	return drzewo[index];
}
string Drzewo::szyfruj(char c){
	int i = 1;
	string s = "";
	while(drzewo[i] != c && i <= size){
		i++;
	}
	while(i!=0){
		s+=(1-i%2)+48;
		i = (i-1)/2;
	}
	return s;
}

int main(){
	int size;
	cin >> size;
	Drzewo d(size);
	char c;
	for(int i = 0; i < size; i++){
		cin >> c;
		d.push(c);
	}
	char l;
	cin >> l;
	cout << d.szyfruj(l) << "\n";

}
