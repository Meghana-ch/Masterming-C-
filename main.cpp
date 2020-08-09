#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;

int main()
{
    char select;
    int code, guess;
    int secret_num[3];
    int guess_num[3];
    int n1, n2, n3;
    int chance = 1;
    int inplace = 0, outplace = 0;
    cout << "INSTRUCTIONS:\n"
            "- You have 10 moves to guess the number.\n"
            "- Press 's' to set the three digits, or 'r' to randomize them.\n"
            "- Input of 000 displays the hidden digits. Input of 999 exits the program.\n"
            "GOOD LUCK!!" << endl;

    // For selecting on how to randomize the number.
    cout << "Press 's' to set the three digits, or 'r' to randomize them: ";
    cin >> select;
    // Setting the secret code.
    if(select == 's' || select == 'S')
    {
        cout << "Please enter a 3-digit number: ";
        cin >> code;
        secret_num[2] = code % 10;
        code = code/10;
        secret_num[1] = code % 10;
        code = code/10;
        secret_num[0] = code % 10;
    }
    // randomizing the number.
    else if(select == 'r' || select == 'R')
    {
        srand((int)time(nullptr));
        n1 = rand() % 10;
        secret_num[0] = n1;
        n2 = rand() % 10;
        while(n2 == secret_num[0])
        {
            n2 = rand() % 10;
        }
        secret_num[1] = n2;
        n3 = rand() % 10;
        while(n3 == secret_num[0] || n3 == secret_num[1])
        {
            n3 = rand() % 10;
        }
        secret_num[2] = n3;

    }
    // In case wrong char has been entered.
    else
    {
        cout << "Invalid entry!";
        while(select != 's' || select != 'S' || select != 'r' || select != 'R')
        {
            cout << "Press 's' to set the three digits, or 'r' to randomize them: ";
            cin >> select;
        }
    }
    // Taking the input from user for guessed number.
    cout << "                                                   INPLACE         OUTPLACE\n"
            "                       -------         --------" << endl;
    while(chance <= 10) {
        cout << chance << "." << " " << "Your guess: ";
        cin >> guess;
        guess_num[2] = guess % 10;
        guess = guess / 10;
        guess_num[1] = guess % 10;
        guess = guess / 10;
        guess_num[0] = guess % 10;
        outplace = 0;
        inplace = 0;
        unordered_set<int> s = {secret_num[0], secret_num[1], secret_num[2]}; // creating the set.
        if(s.find(guess_num[0]) != s.end()) //checking if numbers exist in the secret number.
        {
            outplace++;
            if(guess_num[0] == secret_num[0])
            {
                outplace--;
                inplace++;
            }
        }
        if(s.find(guess_num[1]) != s.end())
        {
            outplace++;
            if(guess_num[1] == secret_num[1])
            {
                outplace--;
                inplace++;
            }
        }
        if(s.find(guess_num[2]) != s.end())
        {
            outplace++;
            if(guess_num[2] == secret_num[2])
            {
                outplace--;
                inplace++;
            }
        }

        if(secret_num[0] == guess_num[0] && secret_num[1] == guess_num[1] && secret_num[2] == guess_num[2])
        {
            cout << "*** Congratulations! You have found the number. ***";
            break;
        }
        cout << "You entered: " << guess_num[0] << guess_num[1] << guess_num[2] << "         " <<
        inplace << "               " << outplace << endl;
        chance++;
    }
    cout << "Better Luck next time! The secret code was " << secret_num[0] << secret_num[1] << secret_num[2] << endl;
    return 0;
}
// correct the calculations for subtracting the inplace count when it was incremented before.