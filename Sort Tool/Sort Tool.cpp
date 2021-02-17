// Sort Tool.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <fstream>
#include <list>
#include <array>

using namespace std;


const int COUNT_ARRAY = 50;


int* generateArray() {
   int result[COUNT_ARRAY];

    for (int i = 0; i < COUNT_ARRAY; i++) {
        result[i] = rand();
    }

    return result;
}


/*
   Zobrazení listu
*/
void showArray(int array[]) {
    cout << "[";
    for (int i = 0; i < COUNT_ARRAY; i++) {
        cout << array[i];
        if (i < (COUNT_ARRAY - 1)) {
            cout << ",";
        }
    }
    cout << "]\n";
}


/********************************************************/
/*                  ŘADÍCÍ METODY                       */ 
/********************************************************/

void swapElement(int array[], int a_key, int b_key) {
    int temp = array[a_key];
    array[a_key] = array[b_key];
    array[b_key] = temp;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort1(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place  
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j + 1] < array[j]) {
                swapElement(array, j, j + 1);
            }
        }
    }
}


void insertionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + 1;
        int tmp = array[j];
        while (j > 0 && tmp > array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = tmp;
    }
}


void quicksort(int array[], int left, int right) {
    if (left < right) {
        int boundary = left;
        for (int i = left + 1; i < right; i++) {
            if (array[i] > array[left]) {
                swapElement(array, i,  ++boundary);
            }
        }
        swapElement(array, left, boundary);
        quicksort(array, left, boundary);
        quicksort(array, boundary + 1, right);
    }
}
/********************************************************/


int main()
{
    // Úvod
    cout << "*******************************\n";
    cout << "          SORT TOOL            \n";
    cout << "*******************************\n";

    cout << "Generuji mnozinu cisel...\n";
   
    int* mnozina = generateArray();

    // Zobrazení načtené množiny
    showArray(mnozina);

    string in;
    // Vstup uživatele
    cout << "Jakym algoritmem chcete mnozinu seradit [quickSort/insertionSort/bubbleSort]?\n";
    cin >> in;

    // Spracování
    if (in == "quickSort") {
        quicksort(mnozina, 0, 1);
    } else if(in == "insertionSort") {
        insertionSort(mnozina, COUNT_ARRAY);
    } else if (in == "bubbleSort") {
        bubbleSort1(mnozina, COUNT_ARRAY -1 );
    } else {
        cout << "Chybny vyber algoritmu\n";
        return 0;
    }

    // Zobrazení načtené množiny
    cout << "Serazena mnozina:\n";
    showArray(mnozina);
  

    return 1;
}