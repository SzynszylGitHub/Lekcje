#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


string max(const string& a, const string& b) {
    if (a.size() > b.size()) return a;
    if (b.size() > a.size()) return b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) return a;
        else return b;
    }
}
string repair(string& a,int size) {
    for (int i = 0; i < size; i++)
        a = "0" + a;
    return a;
}
string XOR(string a, string b) {
    if (a.size() > b.size()) repair(b, a.size() - b.size());
    if (b.size() > a.size()) repair(a, b.size() - a.size());
    string ns="";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) ns += "1";
        else ns += "0";
    }
    return ns;
}
int bintoint(string a) {
    int num=0;
    for (int i = a.size() - 1; i >= 0; i--) {
        num += (a[i] - '0') * pow(2,a.size()-i-1);
    }
    return num;
}
string inttobin(int a) {
    string ns = "";
    while (a != 0) {
        if (a % 2) {
            ns += "1"; 
            a -= 1; 
        }
        else ns += "0";
        a /= 2;
    }
    reverse(ns.begin(), ns.end());
    return ns;
}

int zad2(const string& name) {
    fstream folder;
    folder.open(name);
    if (!folder.good()) return -1;
    string line;
    int counter = 1 ;
    int finalCounter = 0;

    while (folder >> line) {
        for (int i = 1; i < line.size(); i++) {
            if (line[i - 1] != line[i]) counter++;
        }
        if (counter <= 2)  finalCounter++;
        
        counter = 1;

    }
    folder.close();
    return finalCounter;
}
string zad3(const string& name) {
    fstream folder;
    folder.open(name, ios::in);
    if (!folder.good()) return "bad folder name error";
    string nMax;
    folder >> nMax;
    string line;
    while (folder >> line) {
        nMax = max(nMax, line);
    }
    folder.close();
    return nMax;
}
void zad5(const string& name) {
    fstream folder;
    folder.open(name, ios::in);
    fstream folder2;
    folder2.open("wyniki2_5.txt", ios::out);
    if(folder.good()){
        string line;
        while (folder >> line) {
             folder2 << XOR(line, inttobin(bintoint(line) / 2)) << "\n";
        }
    }
    folder.close();
    cout << "completed task" << endl;
}

int main()
{
    fstream folder;
    string prep = "bin_przyklad.txt";
    string finish = "bin.txt";
    prep = finish; // podmiana przykladu na wlasciwy plik


    folder.open("wyniki2.txt", ios::out);
    folder << "zadanie 2.2: " << zad2(prep) << "\n";
    folder << "zadanie 2.3: " << zad3(prep) << "\n";
    folder.close();
    zad5(prep);
    
        return 0;
}
