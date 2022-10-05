#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int char_to_int(string n){
    int helper;
    stringstream ss;
    ss.clear();
    ss << n;
    ss >> helper;
    return helper;
}

template<class T>
vector<T> load(const string& name){
    vector<T> tab;
    const int size_tab=1000;
    int i=0;
    tab.resize(size_tab);
    fstream folder;
    folder.open(name,ios::in);
    while(folder >> tab[i])
        i++;
    folder.close();
    return tab;
}

int main()
{
    int man=0 , woman=0;
    auto tab = load<string>("dane.txt");
    for(const auto n:tab)
        if(n[n.size()-2]%2) man++;
        else woman++;

    int listopad=0;
    string helper;
    for(const auto n:tab){
        helper ="";
        helper += n[2];
        helper += n[3];
        if(helper == "11" || helper == "31")
            listopad++;
    }

    vector<string> zapis;
    for(const auto n:tab)
        if((n[0]+(3*n[1])+(7*n[2])+(9*n[3])+n[4]+(3*n[5])+(7*n[6])+(9*n[7])+n[8]+(3*n[9])+n[10])%10!=0)
            zapis.emplace_back(n);

    fstream folder;
    folder.open("wynik6.txt",ios::out);
    folder << "zadanie 6.1\n";
    folder << woman <<" kobiety\n";
    folder << man << " Mezczyzni\n";
    folder << "zadanie 6.2\n";
    folder << "liczba osob urodzonych w listopadzie: " << listopad << "\n";
    folder << "zadanie 6.3\n";
    for(const auto n:zapis)
        folder << n << "\n";




    return 0;
}
