#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isValidEmail(const char* email) {
    int len = strlen(email);
    int atPos = -1;
    int dotPos = -1;

    // Проверка наличия символа '@' и '.'
    for (int i = 0; i < len; ++i) {
        if (email[i] == '@') {
            if (atPos != -1) return false; // Более одного символа '@'
            atPos = i;
        } else if (email[i] == '.') {
            dotPos = i;
        }
    }

    // Проверка наличия '@' и '.'
    if (atPos == -1 || dotPos == -1 || atPos > dotPos) return false;

    // Проверка имени пользователя
    for (int i = 0; i < atPos; ++i) {
        if (!isalnum(email[i]) && email[i] != '_' && email[i] != '-' && email[i] != '.') {
            return false;
        }
    }

    // Проверка доменного имени
    for (int i = atPos + 1; i < len; ++i) {
        if (email[i] == '-' && (i + 1 < len && email[i + 1] == '-')) {
            return false; // Два дефиса подряд
        }
        if (!isalnum(email[i]) && email[i] != '-' && email[i] != '.') {
            return false;
        }
    }

    return true;
}

int main() {
    char email[100];
    cout << "Введите адрес электронной почты: ";
    cin >> email;

    if (isValidEmail(email)) {
        cout << "Адрес электронной почты корректен." << endl;
    } else {
        cout << "Адрес электронной почты некорректен." << endl;
    }

    return 0;
}
