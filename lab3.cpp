#include <iostream>

using namespace std;

void get_lengths_of_words(int count_of_words);

int main()
{
    // setlocale(LC_ALL, "Russian")
    int count_of_words;

    cout << "[..] Enter count of words:" << endl;
    cin >> count_of_words;

    get_lengths_of_words(count_of_words);

    cout << "[+] Complete!" << endl;
}


void get_lengths_of_words(int count_of_words) {
    cout << "[..] Enter your sentence:" << endl;
    const int size_of_string = 100;
    char string[size_of_string] = {};
    char new_string[size_of_string] = {};
    int index_new = 0;
    int count_of_iterations = 0;
    while (cin >> string) {
        int index = 0;
        int counter = 0;
        while (string[index] != '\0') {
            new_string[index_new] = string[index];
            counter += 1;
            index += 1;
            index_new += 1;
        }

        if (counter <= 9) {
            new_string[index_new] = char(counter + '0');
            index_new += 1;
        }

        else {
            const int size_of_counter = 3;
            char counter_inString[size_of_counter] = {};
            int index_of_counterString = 0;

            int digit;

            while (counter != 0) {
                digit = counter % 10;
                counter_inString[index_of_counterString] = char(digit + '0');
                index_of_counterString += 1;
                counter /= 10;
            }

            for (int index_counter = size_of_counter-1; index_counter >= 0; index_counter -= 1) {
                if (counter_inString[index_counter] != '\0') {
                    new_string[index_new] = counter_inString[index_counter];
                    index_new += 1;
                }
            }
        }
        count_of_iterations += 1;

        if (count_of_iterations == count_of_words) {
            cout << "----------New sentence----------\n" << endl;
            cout << new_string << "\n" << endl;
            cout << "--------------------------------" << endl;
            break;
        }
    }
}
