#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, max_index, max = 0;
	int *tab[2];
	int * z_p;
    cin >> n;
    cin >> m;

    tab[0] = new int[m];
	tab[1] = new int[m];

    for(int j = 0; j < m; j++){
        cin >> tab[0][j];
    }

    for(int i = 1; i < n; i++){     //O(n*m)
		for(int j = 0; j < m; j++){
			cin >> tab[1][j];
			if(j == 0){
				if(tab[0][j] > tab[0][j+1])
					tab[1][j] += tab[0][j];
				else
					tab[1][j] += tab[0][j+1];
            }
			else if(j == m-1){
				if(tab[0][j] > tab[0][j-1])
					tab[1][j] += tab[0][j];
				else
					tab[1][j] += tab[0][j-1];
			}
			else
				if(tab[0][j+1] > tab[0][j] )
					if( tab[0][j+1] > tab[0][j-1])
                        tab[1][j] += tab[0][j+1];
                    else
                        tab[1][j] += tab[0][j-1];
				else
                    if(tab[0][j] > tab[0][j-1] )
                        tab[1][j] += tab[0][j];
                    else
                        tab[1][j] += tab[0][j-1];
        }
        z_p = tab[0];       //swap zeby nie stracic tab[0]
		tab[0] = tab[1];
        tab[1] = z_p;
	}

    for(int j = 0; j < m; j++){
        if(tab[0][j] > max){
            max = tab[0][j];
            max_index = j;
        }
    }

	cout << max_index << " " << max;
	cout << "\n";
return 0;
}

