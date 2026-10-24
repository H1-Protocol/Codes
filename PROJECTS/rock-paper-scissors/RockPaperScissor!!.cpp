#include <iostream>
#include <ctime>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main(){

char player;
char computer;
bool Again = true;
char pa;
srand(time(0));

while(Again){
player = getUserChoice();
cout << "Your Choice: ";
showChoice(player);

computer = getComputerChoice();
cout << "Computer's Choice:  ";
showChoice(computer);
chooseWinner(player,computer);
    
cout << "\n\nPlay Again? y/n: ";
cin >>pa;
    if (pa == 'y' || pa == 'Y') {
        Again = true;
    } else {
        Again = false;
        cout << "\n\nThanks for playing! Goodbye.\n";
    }

    }return 0;
}

char getUserChoice(){
    char player;
    cout << "\n\nRock-Paper-Scissors Game\n";

    do{
        cout << "Choose an Option:\n";
        cout << "*****************\n";
        cout << "'r' for Rock \n";
        cout << "'p' for Paper \n";
        cout << "'s' for Scissor \n";
        cin >> player;
    }while(player != 'r' && player != 'p' && player !='s');
    return player;
}

char getComputerChoice(){

	
	int num = rand() % 3 + 1;

	switch(num){
		case 1: return 'r';
		case 2: return 'p';
		case 3: return 's';
	}

	return 0;
}

void showChoice(char choice){
    switch(choice){

        case 'r':cout << "Rock\n";
                break;
        case 'p':cout << "Paper\n";
                break;
        case 's':cout << "Scissor\n";        
                break;
        }      
}

void chooseWinner(char player, char computer){

        switch(player){
    case 'r': if (computer == 'r'){
            cout << "It's a tie!!\n";
        }
        else if(computer == 'p'){
            cout << "You Loose!!\n";
        }
        else{
            cout << "You Win!!\n";
        }
        break;
    case 'p': if (computer == 'r'){
            cout << "You Win!!\n";
        }
        else if(computer == 'p'){
            cout << "It's a tie!!\n";
        }
        else{
            cout << "You Loose!!\n";
        }
        break;
    case 's': if (computer == 'p'){
            cout << "You Win!!\n";
        }
        else if(computer == 's'){
            cout << "It's a tie!!\n";
        }
        else{
            cout << "You Loose!!\n";
        }
        break;
    


    }
}
