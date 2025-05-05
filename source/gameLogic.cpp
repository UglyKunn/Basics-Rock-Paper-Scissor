#include <iostream>
#include "gameLogic.h"
#include <random>
#include <conio.h>

void singlePlayer() {
  int input = 0;
  std::cout << "Please choose between [1] Rock, [2] Paper & [3] Scissor: ";
  std::cin >> input;

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1,3);
  int result = dist(mt);

  std::cout << result << std::endl;
  std::string textResult[3] = {"Rock","Paper","Scissor"};
  if(input!=result) {
   switch(input) {
    case 1:
      std::cout << "The computer chose : " << result << std::endl;
      (result==2)? std::cout << "You Lose! Better luck next time!" << std::endl : std::cout << "You Win! Congratulations!" << std::endl;
     break;
    case 2:
      std::cout << "The computer chose : " << textResult[result] << std::endl; 
      (result==3)? std::cout << "You Lose! Better luck next time!" << std::endl : std::cout << "You Win! Congratulations!" << std::endl;
     break;
    case 3:
      std::cout << "The computer chose : " << textResult[result] << std::endl;
      (result==1)? std::cout << "You Lose! Better luck next time!" << std::endl : std::cout << "You Win! Congratulations!" << std::endl;
     break;
    default: std::cout << "Invalid Input! Please try again!";
   }
  }
  else {
    std::cout << "Its a draw!" << std::endl;
  }
}

void twoPlayers() {
  int input = 0;
  int player[2] = {0,0};
  for(int i = 0; i <= 1; i++) {
    std::cout << "Player " << i + 1 << ", please choose between [1] Rock, [2] Paper & [3] Scissor: ";
    std::cin >> input;
    player[i] = input;
    system("cls");
  }
  std::string textResult[3] = {"Rock","Paper","Scissor"};
  if(player[0] != player[1]) {
   switch(player[0]) {
    case 1:
      std::cout << "Player 1 chose : " << textResult[player[0]-1] << std::endl;
      std::cout << "Player 2 chose : " << textResult[player[1]-1] << std::endl;
      (player[1]==2)? std::cout << "Player 2 won Congratulations!" << std::endl : std::cout << "Player 1 won! Congratulations!" << std::endl;
     break;
    case 2:
      std::cout << "Player 1 chose : " << textResult[player[0]-1] << std::endl;
      std::cout << "Player 2 chose : " << textResult[player[1]-1] << std::endl; 
      (player[1]==3)? std::cout << "Player 2 won Congratulations!" << std::endl : std::cout << "Player 1 won! Congratulations!" << std::endl;
     break;
    case 3:
      std::cout << "Player 1 chose : " << textResult[player[0]-1] << std::endl;
      std::cout << "Player 2 chose : " << textResult[player[1]-1] << std::endl;
      (player[1]==1)? std::cout << "Player 2 won Congratulations!" << std::endl : std::cout << "Player 1 won! Congratulations!" << std::endl;
     break;
    default: std::cout << "Invalid Input! Please try again!";
   }
  }
  else {
    std::cout << "Its a draw!" << std::endl;
  }

 }


