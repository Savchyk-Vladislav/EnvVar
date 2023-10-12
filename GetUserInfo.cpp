#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
using namespace std;

int main() {
    //Спочатку витягуємо UID після чого повертаємо її до структури passwd
    struct passwd* pwd = getpwuid(geteuid());
    if (pwd != nullptr) {
            //Витягуємо зі структури ім'я користувача та домашню діректорію
        cout << "User name: " << pwd->pw_name << endl;
        cout << "Home directory: " << pwd->pw_dir << endl;
    }
    //Те ж саме тільки через getpwnam, і в якості ім'я користувача передаємо root користувача
    char* rootName = "root";
    struct passwd* pwd2 = getpwnam(rootName);
    if (pwd2 != nullptr) {
        cout << "User name: " << pwd2->pw_name << endl;
        cout << "Home directory: " << pwd2->pw_dir << endl;
    }
    return 0;
}
