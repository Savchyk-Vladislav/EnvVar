#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //extern вказує на те, що змінна environ буде шукатися не в цьому файлі а в іншому, в нашому випадку у стандартній бібліотеці cstdlib
    extern char** environ;
    //Перебираємо масив environ до останнього вказівника на nullptr
    for (int i = 0; environ[i] != nullptr; ++i) {
        cout << environ[i] << endl;
    }
    return 0;
}
