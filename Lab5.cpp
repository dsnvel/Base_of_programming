#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

int get_random_number(int min, int max);
string get_card_from_cards(string* cards, int count_of_cards, int number, string* card);

struct cards {
private:
    map <char, int> points_for_cards = { {'2', 2},
                                         {'3', 3},
                                         {'4', 4},
                                         {'5', 5},
                                         {'6', 6},
                                         {'7', 7},
                                         {'8', 8},
                                         {'9', 9},
                                         {'1', 10},
                                         {'В', 10},
                                         {'Д', 10},
                                         {'К', 10},
                                         {'Т', 11} };
public:
    int get_count_of_points(char first_symbol) {
        return points_for_cards[first_symbol];
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    const int count_of_cards = 54;

    int count_of_user_points;
    int count_of_bot_points;
    
    string message_of_user = "Continue";
    string message_of_bot = "Continue";

    string user_card;
    string bot_card;

    int user_random_number;
    int bot_random_number;

    char user_first_symbol;
    char bot_first_symbol;

    int bot_choice;

    cards stuck;

    while (message_of_user != "Stop game") {
        string cards[count_of_cards] = {"2-Буби", "2-Пики", "2-Черви", "2-Крести",
                                        "3-Буби", "3-Пики", "3-Черви", "3-Крести",
                                        "4-Буби", "4-Пики", "4-Черви", "4-Крести",
                                        "5-Буби", "5-Пики", "5-Черви", "5-Крести",
                                        "6-Буби", "6-Пики", "6-Черви", "6-Крести", 
                                        "7-Буби", "7-Пики", "7-Черви", "7-Крести", 
                                        "8-Буби", "8-Пики", "8-Черви", "8-Крести", 
                                        "9-Буби", "9-Пики", "9-Черви", "9-Крести", 
                                        "10-Буби", "10-Пики", "10-Черви", "10-Крести", 
                                        "В-Буби", "В-Пики", "В-Черви", "Д-Крести", 
                                        "Д-Буби", "Д-Пики", "Д-Черви", "В-Крести", 
                                        "К-Буби", "К-Пики", "К-Черви", "К-Крести", 
                                        "Т-Буби", "Т-Пики", "Т-Черви", "Т-Крести" };
        count_of_user_points = 0;
        count_of_bot_points = 0;

        while (message_of_user != "Stop" && message_of_bot != "Stop") {
            if (message_of_user != "Stop") {
                if (count_of_user_points < 21) {
                    user_random_number = get_random_number(0, count_of_cards);
                    user_card = get_card_from_cards(cards, count_of_cards, user_random_number, &user_card);
                    user_first_symbol = user_card[0];
                    count_of_user_points += stuck.get_count_of_points(user_first_symbol);
                    // cout << "Card first symbol: " << user_first_symbol << endl;
                    cout << "Your card: " << user_card << endl;
                    cout << "Your points: " << count_of_user_points << endl;
                    cout << "Stop or Continue: " << endl;
                    cin >> message_of_user;
                }
                else {
                    message_of_user = "Stop";
                }
            }
            this_thread::sleep_for(500ms);
            
            if (message_of_bot != "Stop") {
                if (count_of_bot_points < 21) {
                    if (count_of_bot_points >= 17) {
                        bot_choice = get_random_number(1, 10);
                        if (bot_choice > 5) {
                            bot_random_number = get_random_number(0, count_of_cards);
                            bot_card = get_card_from_cards(cards, count_of_cards, bot_random_number, &bot_card);
                            bot_first_symbol = bot_card[0];
                            count_of_bot_points += stuck.get_count_of_points(bot_first_symbol);
                        }
                        else {
                            cout << "-----------------------" << endl;
                            cout << "Bot stopped to taking cards!" << endl;
                            message_of_bot = "Stop";
                        }
                    }
                    else {
                        cout << "-----------------------" << endl;
                        cout << "Bot taking card!" << endl;
                        bot_random_number = get_random_number(0, count_of_cards);
                        bot_card = get_card_from_cards(cards, count_of_cards, bot_random_number, &bot_card);
                        bot_first_symbol = bot_card[0];
                        count_of_bot_points += stuck.get_count_of_points(bot_first_symbol);
                        // cout << "Card first symbol: " << bot_first_symbol << endl;
                        cout << "Bot card: " << bot_card << endl;
                        cout << "Bot points: " << count_of_bot_points << endl;
                    }
                }
                else {
                    cout << "Bot stopped to taking cards!" << endl;
                    message_of_bot = "Stop";
                }
            }
            this_thread::sleep_for(500ms);
            cout << "-----------------------" << endl;
            cout << "-----------------------" << endl;
        }
        if ((count_of_user_points == count_of_bot_points) || (count_of_user_points > 21 && count_of_bot_points > 21)) {
            cout << "Draw!" << endl;
        }
        else if (count_of_user_points > 21) {
            cout << "You Lose!" << endl;
        }
        else if (count_of_bot_points > 21) {
            cout << "You Win!" << endl;
        }
        else if (count_of_user_points > count_of_bot_points) {
            cout << "You Win!" << endl;
        }
        else {
            cout << "You Lose!" << endl;
        }
        cout << "Your points: " << count_of_user_points << endl;
        cout << "Bot points: " << count_of_bot_points << endl;
        cout << "Do you wanna play again (Stop game/Continue)?" << endl;
        message_of_bot = "Continue";
        cin >> message_of_user;
    }
}

int get_random_number(int min, int max) {
    srand(time(NULL));
    int number = min + rand() % (max - min + 1); //Формула для получения числа в заданном диапозоне

    return number;
}

string get_card_from_cards(string* cards, int count_of_cards, int number, string* card) {
    string value = cards[number];
    if (value != "0") {
        cards[number] = "0";
        cout << value << endl;
        *card = value;
        return value;
    }
    else {
        get_card_from_cards(cards, count_of_cards, (number + 1), card);
    }
}
