#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
using namespace std;

int Total = 0;
int speed = 0;
int maxScore = 100;

class Question
{
private:
  string Question_Text;
  string Answer_1;
  string Answer_2;
  string Answer_3;
  string Answer_4;

  int Correct_Answer;
  int Question_Score;

public:
  void setValues(string, string, string, string, string, int, int);
  void askQuestions ( );
};

int main() {
  string name;
  int age;
  int choice;
  cout<< "Welcome to the best quiz game in the history of humanity, maybe ever"<<endl;
  cout<< "Are you ready to play the quiz? "<<endl;
  cout<<endl;
  cout<< "Press 1 if you are ready to begin "<<endl;
  cout<< "Press 0 if you wish to exit the program"<<endl;

  cin >> choice;
  if(choice == 1){
    cout<< "\nWelcome to the game "<< name<< endl;
  }
  else{
    return 0;
  }
  ofstream myfile;
  myfile.open ("data.txt", ios::app);
  myfile << "Player: "<<endl;
  cout<<endl;
  cout<< "To begin with, please enter your name:"<<endl;
  cin >> name;
  cout<< "Please enter your age"<< endl;
  cin >> age;
  myfile << "Name: "<< name<<" Age: "<<age<<endl;

  system("pause");
  Question q1;
  Question q2;
  Question q3;
  Question q4;

  q1.setValues("How fast can a hamster run?",
               "16 km/h",
               "5 km/h",
               "15 km/h",
               "Fast enough to break arduino",
               1,
               25);
  q2.setValues("Who invented Calculus?",
               "Barrack Obama",
               "Isaac Newton",
               "Galileo Galilei",
               "Gottfierd Willhelm",
               2,
               25);
  q3.setValues("When Donald Trump got elected?",
               "2011",
               "2015",
               "2016",
               "2014",
               3,
               25);
  q4.setValues("How many states does United States of America have?",
               "50",
               "51",
               "47",
               "49",
               1,
               25);

  q1.askQuestions();
  q2.askQuestions();
  q3.askQuestions();
  q4.askQuestions();

cout<<endl;
cout<< "Your total score is: "<< Total<< "out of: "<<maxScore<<endl;
myfile<< "Total player "<<name<< " score is: "<<Total<<" out of "<<maxScore<<endl;
myfile.close();

if(Total>= 50){
  cout<<endl;
  cout<<" Great news! You made it! "<<endl;
}
else{
  cout<<endl;
  cout<<" You only got " <<Total<< "and that's not enough to make it through the quiz"<<endl;
  cout<<" Better luck next time!"<<endl;
}
return 0;
}
void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa){

  Question_Text = q;
  Answer_1 = a1;
  Answer_2 = a2;
  Answer_3 = a3;
  Answer_4 = a4;
  Correct_Answer = ca;
  Question_Score = pa;


}
void Question::askQuestions(){
  //we need to set up run values, for instance if a kid runs 10% faster, then run = 1, if 20%, then run = 2
  srand(time(NULL)); //<------ Frederik you need to change this value to the random arduino value
  int run;
  run = rand() % 4+1; //also this one!

  cout<<endl;
  cout << Question_Text <<endl;
  cout<< "1. "<< Answer_1 <<endl;
  cout<< "2. "<< Answer_2 <<endl;
  cout<< "3. "<< Answer_3 <<endl;
  cout<< "4. "<< Answer_4 <<endl;

  cout<<" Score for this questions is: "<< Question_Score<< endl;
  cout<<" What is your guess? "<<endl;
  cout<< "The answer will be confirmed in 7 seconds" <<endl;
  usleep(7000000);
  if(run== Correct_Answer){
    cout<<endl;
    cout<< "Congratulations, you are right!" <<endl;
    Total = Total + Question_Score;
    cout<< "Score: "<< Total << " out of: "<< maxScore<<endl;
  }
  else{
    cout<<endl;
    cout<< "Ding-Dong Your answer is wrong..."<<endl;
    cout<< "Your answer: "<<run<<endl;
    cout<< "Correct answer is: "<< Correct_Answer<< endl;
    cout<<endl;
    cout<< "Score: 0"<< " out of: "<< Question_Score<<endl;
  }
}
