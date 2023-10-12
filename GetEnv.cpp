#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "Enter environment variable name : ";
    string envN;
    cin >> envN;
    // Використовуємо функцію getenv() для отримання значення змінної оточення, попередньо конвертнувши string у char
    char* env = getenv(envN.c_str());
    if (env) {
        // Якщо змінна оточення існує то виводимо її значення
        cout << "Environment variable " << envN << " = " << env << endl;
    } else {
        // Якщо змінної оточення не існує то виводимо повідомлення про помилку
        cerr << "Environment variable " << envN << " not found!" << endl;
    }
    return 0;
}

