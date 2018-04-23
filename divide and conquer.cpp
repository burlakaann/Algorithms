#include<iostream>
#include<math.h>

using namespace std;
/*
double P(int i, int j){
    return 30-sqrt(pow((i-5),2)+pow((j-5),2));
}*/

class Ambony{
private:
    double max;
    int i;
    int max_index;
    int n,m;
public:
    Ambony(){};
    Ambony(int,int);
    void rec(int, int);
};

Ambony::Ambony(int n, int m){
    max = 0;
    this->n = n;
    this->m = m;
}
void Ambony::rec(int n, int m1){ // O(nlogm)
    if(m1 > 2 && m1 <= m){
        m1 = m1/2;
        for(int j = 0; j < n; j++){
            if(P(j, m1) > max){
                max = P(j,m1);
                max_index = j;
            }
        }
        if(P(max_index, m1-1) > max){
            rec(n,m1);
        }
        else if(P(max_index, m1+1) > max ){
            rec(n,m1*4);
        }
        else{
            cout << (int)max ;
        }
    }
    else{
        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                if(P(k, j) > max){
                    max = P(k,j);
                    max_index = j;
                }
            }
        }

        cout << (int)max;
    }
}

int main(){
	
	int n,m;
	int max_index;
	cin >> n >> m;
	Ambony a(n,m);
    a.rec(n,m);

}

