#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_players;
    cout << "Vnesi broj na igraci: ";
    cin >> num_players;

    vector<vector<int>> players(num_players);
    vector<int> sums(num_players);

    // Kreiranje  i mesanje na spilot
    vector<int> deck(52);
    for (int i = 0; i < 52; i++) {
        deck[i] = (i % 13) + 1;
    }
    random_shuffle(deck.begin(), deck.end());

    // Delenje na karti na igracite
    int card_index = 0;
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 52 / num_players; j++) {
            players[i].push_back(deck[card_index]);
            card_index++;
        }
    }

    // Izminuvanje na kartite i presmetuvanje na zbirot
    for (int i = 0; i < num_players; i++) {
        for (int card : players[i]) {
            sums[i] += card;
        }
    }

    // Prikaz na kartite i zbirot za sekoj igrac
    for (int i = 0; i < num_players; i++) {
        cout << "Igrac " << (i + 1) << ": ";
        for (int card : players[i]) {
            cout << card << " ";
        }
        cout << "(zbir = " << sums[i] << ")" << endl;
    }

    // Prikaz na pobednikot
    auto max_iter = max_element(sums.begin(), sums.end());
    int winner_index = distance(sums.begin(), max_iter);
    cout << "Pobednik e igrac " << (winner_index + 1) << " so zbir od " << *max_iter << endl;

    return 0;
}
