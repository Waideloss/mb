#include <iostream>

using namespace std;

int main() {
int age;
cout << "Введите число";
cin >> age;
    if (age < 18) {
        cout << "Вы можете купить сигареты" << endl;
    }
    else {
        cout << "Вы не можете купить сигареты" << endl;
    }

    return 0;
}