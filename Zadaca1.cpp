#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    list<int> broevi;
    for (int i = 0; i < 10000; i++) {
        broevi.push_back(rand() % 10000);
    }

    int parni = count_if(broevi.begin(), broevi.end(), [](int n) { return n % 2 == 0; });
    int pomaliOd2000 = count_if(broevi.begin(), broevi.end(), [](int n) { return n < 2000; });
    int interval1 = count_if(broevi.begin(), broevi.end(), [](int n) { return n >= 2000 && n < 4000; });
    int interval2 = count_if(broevi.begin(), broevi.end(), [](int n) { return n >= 4000 && n < 6000; });
    int interval3 = count_if(broevi.begin(), broevi.end(), [](int n) { return n >= 6000 && n < 8000; });
    int interval4 = count_if(broevi.begin(), broevi.end(), [](int n) { return n >= 8000 && n < 10000; });
    double srednaVrednost = accumulate(broevi.begin(), broevi.end(), 0.0) / broevi.size();

    cout << "Broj na parni elementi: " << parni << endl;
    cout << "Broj na elementi pomali od 2000: " << pomaliOd2000 << endl;
    cout << "Broj na elementi vo interval [2000, 4000): " << interval1 << endl;
    cout << "Broj na elementi vo interval [4000, 6000): " << interval2 << endl;
    cout << "Broj na elementi vo interval [6000, 8000): " << interval3 << endl;
    cout << "Broj na elementi vo interval [8000, 10000): " << interval4 << endl;
    cout << "Sredna vrednost na elementite: " << srednaVrednost << endl;

    return 0;
}
