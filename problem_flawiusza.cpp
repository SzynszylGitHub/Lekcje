#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // w programie istnieje mozliwosc zastrzelenia samego siebie wiec w momencie
    // nie wymyslilem zabezpieczenia przed tym wiec ufam ze nikt nie poda blednych wartosci

    int n_size,powtorzenia;
    cin >> n_size;
    cin >> powtorzenia;

    vector<int> tab;
    tab.resize(n_size);

    for(auto& n:tab)
        n = 1;

    bool flaga;
    int m;
    if(powtorzenia)
    while(powtorzenia){
        for(int i=0; i<n_size; i++){
            if(tab[i]){
                flaga = true;
                m=1;
                while(flaga){
                    if(tab[i+m%n_size]){
                        tab[i+m%n_size]=0;
                        break;
                    }

                    m++;
                }
            }
        }
        powtorzenia--;
    }

    cout << "przezyly osoby na miejscach: ";
    for(int i=0; i<n_size; i++)
        if(tab[i]) cout<< i+1 <<", ";

    return 0;
}
