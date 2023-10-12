#include <iostream>
#include <cstdlib>
#include "environ.h"
using namespace std;

extern char** environ;

void Environ::displayEnv() {
    // Виводимо все оточення
    char** env = environ;
    for (int i = 0; environ[i] != nullptr; ++i) {
        cout << environ[i] << endl;
    }
}

void Environ::displayVarVal(char* var) {
    char* val = getenv(var);
    if (val) {
        // Якщо змінна оточення існує то виводимо її значення
        cout << "Environment variable " << var << " = " << val << endl;
    } else {
        // Якщо змінної оточення не існує то виводимо повідомлення про помилку
        cerr << "Environment variable " << var << " not found!" << endl;
    }
}

void Environ::setVarVal(char* varVal) {
    // Встановлюємо зазначене значення зазначеної змінної
    if (putenv(const_cast<char*>(varVal)) == 0) {
        cout << "Variable set successfully." << endl;
    } else {
        cerr << "Failed to set variable." << endl;
    }
}

void Environ::assignVarVal(char* var, char* val) {
    if (val == nullptr) {
        val = "";
    }
    // Встановлюємо значення змінної оточення
    if (setenv(var, val, 1) == 0) {
        cout << "Variable assigned successfully." << endl;
    } else {
        cerr << "Failed to assign variable." << endl;
    }
    // Перевіряємо значення змінної оточення після встановлення
    char* envR = getenv(var);
    if (envR) {
        cout << "The value of the environment variable " << var << " = " << envR << endl;
    } else {
        cerr << "Environment variable not found." << endl;
    }
}

void Environ::deleteVar(char* var) {
    // Видаляємо вказану змінну оточення
    if (unsetenv(var) == 0) {
        cout << "Variable deleted successfully." << endl;
    } else {
        cerr << "Failed to delete variable." << endl;
    }
}

void Environ::clearEnv() {
    // Очищаємо все оточення
    clearenv();
    cout << "Environment variables were deleted." << endl;
}

void Environ::displayHelp() {
    // Виводимо допоміжну інформацію про використання
    cout << "Instructions:" << endl;
    cout << "- If the program is called without options, the entire environment will be displayed" << endl;
    cout << "- If the short option -i <variable> is specified (or the long --info <variable>), then the specified value will be displayed variable or a message that this variable is not in the environment" << endl;
    cout << "- If the short option -s <variable=value> is specified (or the long --set <variable = value>), then the specified environment variable will get a new one value and the set value will be displayed of the specified variable" << endl;
    cout << "- If the short option -a <variable> and -v <value> (or long --assign <variable> and --value <value>), then the specified variable the environment will acquire a new value and will be output the set value of the specified variable, if no value is specified, then an empty string is assigned" << endl;
    cout << "- If the short option -d <variable> is specified (or the long --del <variable>), then the specified variable is removed from the environment" << endl;
    cout << "- If the short option -с (or long --сlear) is specified, then the program is complete cleans the environment." << endl;
}
