#include <iostream>

using namespace std;

void get_new_string(char string[]);

void main() {
    // setlocale(LC_ALL, "Russian")
    cout << "Enter text: ";
    char string[1000];

    cout << endl;

    cin.getline(string, 1000);

    get_new_string(string);

    cout << "[+] Complete!" << endl;
}

void get_new_string(char string[]) {
    char new_string[1000] = { 0 };
    int counter_of_symbols = 0;
    char counter_in_string = { 0 };
    int flag = 0;
    for (int index = 0; index < 1000; index++) {
        char symbol = string[index];

        if (symbol == ' ' || symbol == '\0') {
            if (counter_of_symbols <= 9) {
                new_string[index] = char(counter_of_symbols + '0');
                counter_of_symbols = 0;
            }
            else {
                new_string[index] = char(counter_of_symbols / 10 + '0');
                new_string[index + 1] = char(counter_of_symbols % 10 + '0');
                counter_of_symbols = 0;
                index += 1;
            }
            if (symbol == '\0') {
                break;
            }
        }

        else if (symbol != ' ') {
            new_string[index] = symbol;
            counter_of_symbols += 1;
        }

    }
    cout << new_string << endl;
}