#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


template<class T>
vector<T> load(const string& name){
    fstream folder;
    const int tab_size = 1000;
    vector<T> tab;
    tab.resize(tab_size);
    int i=0;
    folder.open(name,ios::in);
        while(folder >> tab[i])
        i++;
    folder.close();
    return tab;
}

int suma(int liczba){
    int suma;
    while(liczba > 0){
        suma += liczba%10;
        liczba/=10;
    }
    return suma;
}
string reverse_string(const string n){
    string nw="";
    for(int i=n.size()-1; i>=0; i--)
        nw+=n[i];
    return nw;
}


int main()
{
    auto tab = load<int>("liczby.txt");
    int maximum = 0;
    for(const auto& n:tab)
        if(n > maximum && !(n%2))
            maximum=n;

    auto tab2 = load<string>("liczby.txt");
    vector<string> zapis;
    for(auto& n:tab2){
        if(n == reverse_string(n))
            zapis.push_back(n);
    }

    vector<int> zapis2;
    int suma_liczb=0;
    for(auto& n:tab){
        suma_liczb += suma(n);
        if(suma(n) > 30)
            zapis2.emplace_back(n);
    }

    fstream folder;
    folder.open("wynik5.txt",ios::out);

    folder << "zadanie 5.1 \n"<< maximum << "\n";
    folder << "zadanie 5.2 \n";
    for(const auto& n:zapis)
       folder << n << "\n";
    folder << "zadanie 5.3 \n";
    for(const auto& n:zapis2)
        folder << n <<"\n";
    folder<<"suma wszystkich liczb z pliku: "<<suma_liczb<<"\n";

    folder.close();

    return 0;
}
