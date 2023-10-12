#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // Якщо кількість аргументів переданих рівна 1 то видаляємо все оточення
        clearenv();
        cout << "Environment variables were deleted." << endl;
    } else {
        // Якщо кількість аргументів переданих рівна 2 то видаляємо вказану змінну оточення
        string envN(argv[1]);
        unsetenv(envN.c_str());
        cout << "Environment variable " << envN << " was deleted." << endl;
    }
    // Виводимо поточне оточення на екран
    extern char** environ;
    for (int i = 0; environ[i] != nullptr; ++i) {
        cout << environ[i] << endl;
    }
    return 0;
}
