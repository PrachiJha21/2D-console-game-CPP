//Rock Paper Scissors Game in C++
#include<iostream>
#include<ctime> //not in curriculum but needed for random number generation
#include<cstdlib>
#include<iomanip>
using namespace std;

enum class Outcome {WIN, LOSE, TIE, INVALID};

//to welcome the player and show rules
class Welcome{
    public:
        Welcome(){
            cout << setw(6)<<" "<<"Welcome to Rock, Paper, Scissors!" << endl;
            cout <<setfill('-')<<setw(50)<<"-"<<endl;
            cout<<"Rules:" << endl;
            cout <<setfill('-')<<setw(50)<<"-"<<endl;
            cout << "To Select Rock, enter 1" <<endl;
            cout << "To Select Paper, enter 2"<<endl;
            cout<<"To Select Scissors, enter 3"<<endl;
            cout <<setfill('-')<<setw(50)<<"-"<<endl;
        }
};

//to take choices and display them
class Choice{
    public:
        int input(){
            int playerchoice;
            cout<<"Enter your choice: ";
            cin>>playerchoice;
            cout <<setfill('-')<<setw(50)<<"-"<<endl;
            return playerchoice;
        }
        int randomChoice(){
            int computerchoice;
            srand(time(NULL)); 
            computerchoice = (rand() % 3 ) + 1;
            return computerchoice;
        }
        void displayChoice(int playerchoice, int computerchoice){
            string compchoice;
            string player;
            if (playerchoice == 1)
                player = "Rock";
            else if (playerchoice == 2)
                player = "Paper";
            else if( playerchoice == 3)
                player = "Scissors";
            else
                player = "Invalid option chosen!";
            cout<<"You chose: "<<player<<endl;
            
            if (computerchoice == 1)
                compchoice = "Rock";
            else if (computerchoice == 2)
                compchoice = "Paper";
            else 
                compchoice = "Scissors";
            cout<<"Computer chose: "<<compchoice<<endl; 
            cout <<setfill('-')<<setw(50)<<"-"<<endl;
        }
};

//Game Logic
class Game {
    public:
    Outcome outcome;
        void result(int playerChoice, int computerChoice){
            if (playerChoice == computerChoice){
                outcome = Outcome::TIE;
            }
            else if(playerChoice == 1 && computerChoice == 2){
                outcome = Outcome::LOSE;
            }
            else if(playerChoice == 1 && computerChoice == 3){
                outcome = Outcome::WIN;
            }
            else if(playerChoice == 2 && computerChoice == 1){
                outcome = Outcome::WIN;
            }
            else if(playerChoice == 2 && computerChoice == 3){
                outcome = Outcome::LOSE;
            }
            else if (playerChoice == 3 && computerChoice == 1){
                outcome = Outcome::LOSE;
            }
            else if (playerChoice == 3 && computerChoice == 2){
                outcome = Outcome::WIN;
            }
            else{
                outcome = Outcome::INVALID;
            }
        }
};

//Display Coloured Output(not in curriculum)
class Color{
    public:
        void show(Outcome outcome){
            switch(outcome){
                case Outcome::WIN:
                    cout<<"\033[32mYou Win!\033[0m"<<endl;
                    break;
                case Outcome::LOSE:
                    cout<<"\033[31mYou Lose!\033[0m"<<endl;
                    break;
                case Outcome::TIE:
                    cout<<"\033[33mIt's a Tie!\033[0m"<<endl;
                    break;
                case Outcome::INVALID:
                    cout<<"\033[34mInvalid Input!\033[0m"<<endl;
                    break;
            }
        }
};

//To track and display scores
class ScoreTracker{
    int PlayerScore = 0;
    int ComputerScore = 0;
    public:
        void show(Outcome outcome){
            cout <<setfill('*')<<setw(50)<<"*"<<endl;
            cout<<setfill(' ')<<setw(17)<<" "<<"Current Scores:"<<endl;
            cout <<setfill('*')<<setw(50)<<"*"<<endl;
            switch(outcome){
                case Outcome::WIN:
                    PlayerScore++;
                    break;
                case Outcome::LOSE:
                    ComputerScore++;
                    break;
                    case Outcome::TIE:
                    PlayerScore++;
                    ComputerScore++;
                    break;
                case Outcome::INVALID:
                    PlayerScore += 0;
                    ComputerScore += 0;
                    break;
            }   
            cout<<"Player: "<<PlayerScore<<setfill(' ')<<setw(15)<<" "<<"|"<<setw(13)<<" "<<"Computer: "<<ComputerScore<<endl;
        }
};

int main(){
    //Object Creation
    Welcome W1;
    Choice I1;
    Game G1; 
    Color C1;
    ScoreTracker S1;
    //Looping for multiple rounds 
    char playAgain;
    do{
        int playerChoice = I1.input();
        int computerChoice = I1.randomChoice();
        G1.result(playerChoice, computerChoice);
        I1.displayChoice(playerChoice, computerChoice);        
        C1.show(G1.outcome);
        S1.show(G1.outcome);
        cout <<setfill('*')<<setw(50)<<"*"<<endl;
        cout<<"Do you want to play again? (y/n): ";
        cin>>playAgain;
    }while(playAgain == 'y' || playAgain == 'Y');
    return 0;
}