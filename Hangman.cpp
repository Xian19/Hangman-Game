#include <iostream> //use for input and output
#include <cstdlib> //use to convert data types.
#include <cctype> //use to convert lowercase to uppercase.
#include <stdlib.h> //use for clearing the screen for each round.

using namespace std;

char randomWord[7]; //This is the array for the random word picked.
char guessWord[7]; //This is where the random word is stored to compare to the user's guess.
int tries; //Checks how many tries the user did.
int checker = 0; //The variable to check if the user won.
int wrong; //Variable to count user's mistakes.
char ifExit = 'N'; //Use to exit the system.
int death; //Variable to tell how many parts the player has left.
int correct = 0; //Variable that tells if the input is correct.
char input = '&'; //Variable for the user's input.
char out = 'Y'; //Variable to handle if the user wants to try again.
char screen[5][4] = {'-','-','-',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' '}; //This is the hangman screen use in the game.
char words[51][7] = {
    {'E','N','T','E','R',' ',' '},    //These are the words use for the game. 
    {'J','A','Z','Z',' ',' ',' '},    //You can add more by manipulating these.
    {'Q','U','I','Z','Z',' ',' '},
    {'P','A','C','E',' ',' ',' '},
    {'H','I','D','E',' ',' ',' '},
    {'H','A','I','R',' ',' ',' '},
    {'P','O','O','R',' ',' ',' '},
    {'K','N','E','E',' ',' ',' '},
    {'F','A','R','E',' ',' ',' '},
    {'W','A','V','E',' ',' ',' '},
    {'B','E','A','N',' ',' ',' '},
    {'H','O','U','S','E',' ',' '},
    {'C','L','A','I','M',' ',' '},
    {'S','T','R','A','P',' ',' '},
    {'B','L','A','C','K',' ',' '},
    {'F','L','O','O','D',' ',' '},
    {'T','O','U','C','H',' ',' '},
    {'D','I','R','T','Y',' ',' '},
    {'E','M','B','O','X',' ',' '},
    {'B','O','A','R','D',' ',' '},
    {'G','L','A','R','E',' ',' '},
    {'E','T','H','N','I','C',' '},
    {'M','E','D','I','U','M',' '},
    {'P','R','E','F','E','R',' '},
    {'N','O','T','I','C','E',' '},
    {'L','A','D','D','E','R',' '},
    {'C','H','O','R','U','S',' '},
    {'T','H','R','E','A','T',' '},
    {'L','A','U','N','C','H',' '},
    {'R','E','V','I','S','E',' '},
    {'M','E','A','S','U','R','E'},
    {'E','X','P','L','O','I','T'},
    {'V','A','R','I','A','N','T'},
    {'C','O','M','M','A','N','D'},
    {'D','I','A','M','O','N','D'},
    {'P','E','R','C','E','N','T'},
    {'O','U','T','S','I','D','E'},
    {'E','D','I','T','I','O','N'},
    {'G','R','A','P','H','I','C'},
    {'Q','U','A','R','E','L','L'},
    {'L','U','X','U','R','Y',' '},
    {'D','E','A','L',' ',' ',' '},
    {'S','I','C','K','L','Y',' '},
    {'W','E','S','T',' ',' ',' '},
    {'W','A','L','K',' ',' ',' '},
    {'C','A','M','P',' ',' ',' '},
    {'R','U','I','N',' ',' ',' '},
    {'C','O','D','E',' ',' ',' '},
    {'K','A','L','D','A','G',' '},
    {'G','R','O','W',' ',' ',' '},
    {'F','L','E','X',' ',' ',' '}
};
   
void displayScreen()  //Function for displaying the screen matrix.
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}

void refreshScreen() //Function to refresh the screen for each round.
{
    screen[1][2] = ' ';
    screen[2][2] = ' ';
    screen[2][1] = ' ';
    screen[2][3] = ' ';
    screen[3][1] = ' ';
    screen[3][3] = ' ';
}

void wordPicker() //Function to pick a random word from the matrix and put it in the randomWord array.
{
   int i = (rand() % 20 ) + 1;
    for (int j = 0; j < 7; j++)
        {
            randomWord[j] = words[i][j];
            
        }
        
     
}

void wordVisual() //This outputs the line that tells the player if the guess is right and how many letters there are.
{
  
  for (int j = 0; j < 7; j++)
    {
        if(randomWord[j] != ' ')
        {
            guessWord[j] = '_';
        }
        else
        {
            guessWord[j] = ' ';
        }
        cout<<guessWord[j]<<" ";
        
    }

  

}

char playerInput() //Takes the player's input.
{
    cout<<"Please input your guess: ";
    cin>>input;
    input = toupper(input);
    return input;
}

void wordRefresher() //This sees if the player has guessed a correct word and updates the guessWord array.
{
    wrong = 1;
    for (int j = 0; j < 7; j++)
    {
        if(input == randomWord[j])
        {
            guessWord[j] = input;
            correct ++;
            wrong = 0;
        }   

        
    }
      
}

void guessVisual() //This outputs the updated guessWord array
{
    for (int j = 0; j < 7; j++)
    {
        cout<<guessWord[j];
    }
}

void winChecker() //This checks if the player has solved all the missing letters.
{
    for (int j = 0; j < 7; j++)
    {
        if (guessWord[j] == '_')
        {
          checker ++;
        } 
    }
}

char youWin() //This tells the player that they have won the game.
{   
    if (checker == 0)
    {
      cout<<endl<<endl<<"You win! Congratulations!"<<endl<<endl;
      ifExit = 'Y';
      return ifExit;
    }
}


int main()
{
  srand (time(NULL));

  do{
    cout << "Hangman GAME !\n" << endl;
    refreshScreen();
    displayScreen();
    cout<<endl;
    wordPicker();
    wordVisual();
    wordRefresher(); 
    playerInput();
    tries = 0;
    death = 0;
    ifExit = 'N';
    
    while(tries < 26)
    {
       checker = 0;
       wordRefresher(); 
       if(wrong == 1)
       {
         death ++;
         switch(death)
         {
            case 1:
            {
               screen[1][2] = 'O';
               break;
            }
            case 2:
            {
                screen[2][2] = '|';
                break;
            }
            case 3:
            {
                screen[2][1] = '/';
                break;
            }
            case 4:
            {
                screen[2][3] = '\\';
                break;
            }
            case 5:
            {
                screen[3][1] = '/';
                break;
            }
            case 6:
            {
                screen[3][3] = '\\';
                cout<<endl<<endl<<"-----------------------------------"<<endl<<endl;
                system("CLS");
                cout << "Hangman GAME !\n" << endl;
                displayScreen();
                guessVisual();
                cout<<endl<<"You Lost! \n The answer was ";
                for (int j = 0; j < 7; j++)
                {
                   cout<<randomWord[j];
            
                }
                cout<<endl;
                goto exit;
                break;
            }
         }

       }
       cout<<endl<<endl<<"-----------------------------------"<<endl<<endl;
       system("CLS");
       cout << "Hangman GAME !\n" << endl;
       displayScreen();
       guessVisual();
       winChecker();
       youWin();
       if(ifExit == 'Y')
       {
           break;
       }
       playerInput();
       tries ++;
       
    }
    exit:
    cout<<"Do you want to try again? [Y/N] ";
    cin>>out;
    out = toupper(out);
    system("CLS");
  }
  while (out == 'Y');

}