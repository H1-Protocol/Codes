#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    char choice;

    do {
        string test_sentence = "Failure and Programming is a bliss, learn from it and learning C++ is just a little painfull...";
        string user_input;

        cout << "==================Typing Speed Test==================" << endl << endl;
        cout << "Type the following sentence, Word by Word: " << endl << endl;
        cout << "\"" << test_sentence << "\"" << endl << endl;

        cout << "\nPress Enter To START...";
        cin.get(); // for Enter

        time_t startTime = time(0);

        cout << "\nStart typing:\n" << endl;
        getline(cin, user_input);

        time_t endTime = time(0);
        double timeTaken = difftime(endTime, startTime);

        // Characters count
        int totalChars = user_input.length();

        // Counts words(spaces + 1)
        int wordCount = 1;
        for (int i = 0; i < totalChars; i++) {
            if (user_input[i] == ' ')
                wordCount++;
        }

        double wpm = (wordCount / timeTaken) * 60;

        cout << "\n==================Results==================" <<endl;
        cout << "Total characters typed: " << totalChars <<endl;
        cout << "Total words typed     : " << wordCount  <<endl;
        cout << "Time taken            : " << timeTaken  <<" seconds" << endl;
        cout << "Typing speed          : " << wpm        << " WPM"    << endl;

        if (user_input == test_sentence) {
            cout << endl<< endl<< "\nPerfect! You typed exactly the same!!" << endl<< endl<< endl;
        } else {
            cout << endl<< endl<< "\nThe text does not match perfectly, though good try!" << endl;
        }

        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;cout<< endl<< endl<< endl<< endl;
        cin.ignore(); // clear newline for next loop

    } while(choice == 'y' || choice == 'Y');
    return 0;
}
