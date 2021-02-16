// Sort Tool.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <fstream>
#include <list>

using namespace std;


list<int> mnozina;

const string INPUT_FILE = "in.txt";


int main()
{
    cout << "          SORT TOOL\n";
    cout << "*******************************\n";
    cout << "Načítám vstupní soubor [" << INPUT_FILE << "]...\n";


}


bool loadFile() 
{
    ifstream myfile(INPUT_FILE);
    
    string line;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            cout << line << '\n';
        }
        myfile.close();
    } else {
        return false;
    }

    return true;
}