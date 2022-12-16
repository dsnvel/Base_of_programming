#include <iostream>

using namespace std;

int replace(char* new_string, char* string, char* want_to_replace,
    char* change_to, int size_of_string, int size_of_new_string, int size_of_want_to_replace, int size_of_change_to);
void print_array(char* string, int size);
void pull_array(char* array, int size);
int counter_of_array(char* array, int size);

int main() {

    char pass[1];
    int size_of_string;
    int SIZE = 10;

    cout << "Enter size of string:" << endl;
    cin >> size_of_string;
    cin.getline(pass, size_of_string);

    char* string = new char[size_of_string];
    pull_array(string, size_of_string);

    cout << "Enter string:" << endl;
    cin.getline(string, size_of_string);

    char* want_to_replace = new char[SIZE];
    pull_array(want_to_replace, SIZE);
    char* change_to = new char[SIZE];
    pull_array(change_to, SIZE);

    cout << "Enter string what you want to replace (max size 10):" << endl;
    cin.getline(want_to_replace, size_of_string);

    cout << "Enter string which will replace previous text (max size 10):" << endl;
    cin.getline(change_to, size_of_string);

    // cout << "------------------------------------" << endl;

    int size_of_new_string = size_of_string * SIZE;
    char* new_string = new char[size_of_new_string];
    pull_array(new_string, size_of_new_string);

    int size_of_want_to_replace, size_of_change_to;

    size_of_string = counter_of_array(string, size_of_string);
    size_of_want_to_replace = counter_of_array(want_to_replace, SIZE);
    size_of_change_to = counter_of_array(change_to, SIZE);

    /*cout << new_string << endl;
    cout << string << endl;
    cout << want_to_replace << endl;
    cout << change_to << endl;
    cout << size_of_string << endl;
    cout << size_of_new_string << endl;
    cout << size_of_want_to_replace << endl;
    cout << size_of_change_to << endl;*/

    int new_size = replace(new_string, string, want_to_replace, change_to,
        size_of_string, size_of_new_string, size_of_want_to_replace, size_of_change_to);

    /*cout << new_size << endl;
    cout << new_string << endl;*/

    cout << "------------------" << endl;
    cout << "New text:" << endl;
    print_array(new_string, size_of_new_string);

    delete[] new_string;
    delete[] string;
    delete[] want_to_replace;
    delete[] change_to;

    return 0;
}

void pull_array(char* array, int size) {
    for (int index = 0; index < size; index++) {
        array[index] = '0';
    }
}

int counter_of_array(char* array, int size) {
    int count = 0;
    for (int index = 0; index < size; index++) {
        if (array[index] == '\0') {
            break;
        }
        count++;
    }
    return count;
}

void print_array(char* string, int size) {
    for (int index = 0; index < size; index++) {
        if (string[index] != '0')
            cout << string[index];
    }
    cout << "" << endl;
    cout << "------------------" << endl;
    cout << "Finish!" << endl;
}

int replace(char* new_string, char* string, char* want_to_replace,
    char* change_to, int size_of_string, int size_of_new_string, int size_of_want_to_replace, int size_of_change_to) {
    char symbol_of_string;
    char symbol_of_want_to_replace;

    int size_of_new_arr = 0;

    int index_of_string;
    int index_of_new_string = 0;
    int flag;
    for (int index = 0; index < size_of_string;) {
        symbol_of_string = string[index];
        symbol_of_want_to_replace = want_to_replace[0];
        if (symbol_of_string == symbol_of_want_to_replace) {
            flag = 0;
            index_of_string = index;
            for (int index_1 = 0; index_1 < size_of_want_to_replace; index_1++) {
                if (string[index_of_string] != want_to_replace[index_1]) {
                    flag = 1;
                    break;
                }
                index_of_string++;
            }
            if (flag != 1) {
                for (int index_2 = 0; index_2 < size_of_change_to; index_2++) {
                    new_string[index_of_new_string] = change_to[index_2];
                    size_of_new_arr++;
                    index_of_new_string++;
                    index++;
                }
                index += size_of_want_to_replace - size_of_change_to;
                size_of_new_arr += size_of_want_to_replace - size_of_change_to;
            }
            else {
                new_string[index_of_new_string] = string[index];
                size_of_new_arr++;
            }
        }
        else {
            new_string[index_of_new_string] = string[index];
            size_of_new_arr++;
            index++;
        }
        index_of_new_string++;
    }

    return size_of_new_arr;
}
