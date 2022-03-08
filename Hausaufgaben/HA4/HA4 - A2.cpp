#include <iostream> 
#include <iomanip> 
#include <ctime> 
using namespace std; 

int main() { 
    long c; const int n = 150; time_t t; 
    cout << "Two nested loops O(n^2)" << endl; 
    time(&t); 
    c = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            c++; 
            cout << "Count: " << setw(10) << c << "\r"; 
        } 
    } 

    t = time(0) - t; 
    cout << endl << "Required time: " << t << "s" << endl; 
    cout << "\nThree nested loops O(n^3)" << endl; 
    time(&t); 
    c = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            for (int k = 0; k < n; k++) { 
                c++; 
                cout << "Count: " << setw(10) << c << "\r"; 
            } 
        } 
    } 
    t = time(0) - t; 
    cout << endl << "Required time: " << t << "s" << endl; 
}

/*
    Zeit in Sekunden
    n\Kompiler || GCC 8.1.0 (MinGW) ||   VS-C++   ||
    ------------------------------------------------
        50     ||   1    |    42    ||  1  |  37  ||
    ------------------------------------------------
        100    ||   2    |    376   ||  4  |  420 ||
    ------------------------------------------------
        150    ||   5    |   1228   ||  10 | 1417 ||
    ------------------------------------------------

    Testgerät: Surface Pro 7
    CPU: Intel Core i5-1035G4 (Taktfrequenz: 1.1 GHz // Turbo: 3.7 GHz) (4 Kerne / 8 Threads)
    RAM: 8GB LPDDR4X (3733 MHz)
    OS: Windows 11 Home
*/