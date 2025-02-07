#include <iostream>
#include <fstream>
#include <random>

using namespace std;

// Character set for passwords
const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:',.<>?/";

string generatePassword(int length) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, characters.size() - 1);

    string password;
    for (int i = 0; i < length; i++) {
        password += characters[dis(gen)];
    }
    return password;
}

int main() {
    ofstream file("passwords.txt");
    if (!file) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> lengthDis(1, 10);

    const int numPasswords = 10'000'000;  //


    for (int i = 0; i < numPasswords; i++) {
        int length = lengthDis(gen);
        file << generatePassword(length) << endl;
    }

    file.close();
    cout << "10 million random passwords have been saved in passwords.txt!" << endl;

    return 0;
}
