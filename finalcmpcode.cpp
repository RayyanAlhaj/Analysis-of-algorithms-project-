#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Calculates the hamming distance 
int hamming_distance(string a, string b) {
    int distance = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }
    return distance;
}

// Calculates the maximal clique 
vector<int> maximal_clique(int distance_threshold, int num_digits) {
    vector<int> clique;

    for (int i = 0; i < (1 << num_digits); i++) {
        bitset<5> binary(i);
        string binary_str = binary.to_string();

        bool valid = true;
        for (int num : clique) {
            if (hamming_distance(binary_str, bitset<5>(num).to_string()) < distance_threshold) {
                valid = false;
                break;
            }
        }
        if (valid) {
            clique.push_back(i);
        }
    }

    return clique;
}

int main() {
    int distance_threshold, num_digits;
    cout << "Enter hamming distance: ";
    cin >> distance_threshold;
    cout << "Enter length of binary strings: ";
    cin >> num_digits;

    vector<int> clique = maximal_clique(distance_threshold, num_digits);
    int clique_size = clique.size();

    // cout << "Maximal clique: ";
    // for (int num : clique) {
    //     cout << num << " ";
    // }
    // cout << endl;
    cout << "Size of Maximal clique: " << clique_size << endl;
    

    return 0;
}