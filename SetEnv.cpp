#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout << "Enter environment variable name which you wanna change: ";
    string envN;
    cin >> envN;
    cout << "Enter environment variable value which you wanna install: ";
    string envV;
    cin >> envV;
    // Встановлюємо значення змінної оточення
    if (setenv(envN.c_str(), envV.c_str(), 1) == 0) {
        cout << "The environment variable was successfully set." << endl;
    } else {
        cerr << "Error setting environment variable value." << endl;
        return 0;
    }
    // Перевіряємо значення змінної оточення після встановлення
    char* envR = getenv(envN.c_str());
    if (envR) {
        cout << "The value of the environment variable " << envN << " = " << envR << endl;
    } else {
        cerr << "Environment variable not found." << endl;
    }
    return 0;
}
