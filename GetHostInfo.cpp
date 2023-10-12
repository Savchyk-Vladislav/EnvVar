#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
using namespace std;

int main() {
    // Отримуємо ім'я хоста
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        cout << "Computer (host) name: " << hostname << endl;
    } else {
        cerr << "Failed to get computer name." << endl;
    }

    // Отримуємо інформацію про систему
    struct utsname sysInfo;
    if (uname(&sysInfo) == 0) {
        cout << "Computer information:" << endl;
        cout << "System name: " << sysInfo.sysname << endl;
        cout << "Host (network) name: " << sysInfo.nodename << endl;
        cout << "Operating system version: " << sysInfo.release << endl;
        cout << "Operating system build version: " << sysInfo.version << endl;
        cout << "Processor architecture: " << sysInfo.machine << endl;
    } else {
        cerr << "Failed to retrieve computer information." << endl;
    }
    return 0;
}
