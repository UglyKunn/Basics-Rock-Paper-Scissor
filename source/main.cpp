#include <iostream>
#include "RPSgameConfig.h"
#include "gameLogic.h"
#include <windows.h>
#include <thread>
#include <chrono>

void cmdFormatting()
{
  system("mode 70,10"); // Width : Height
  HWND windowHwnd = GetConsoleWindow();
  int screenWidth = GetSystemMetrics(SM_CXSCREEN);
  int screenHeight = GetSystemMetrics(SM_CYSCREEN);
 
  RECT windowRect;
  GetWindowRect(windowHwnd, &windowRect);
  
  int windowWidth = windowRect.right - windowRect.left;
  int windowHeight = windowRect.bottom - windowRect.top;

  int finalPositionX = (screenWidth-windowWidth)/2;
  int finalPositionY = (screenHeight-windowHeight)/2;

  SetConsoleTitle("Rock Paper Scissor");
  
  //MoveWindow(windowHwnd, finalPositionX, finalPositionY, windowWidth, windowHeight, FALSE);
  SetWindowPos(windowHwnd, NULL, finalPositionX, finalPositionY, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
  
}

int main (int argc, char *argv[]) {

  cmdFormatting();
  
  int gameLoop = 1;

  while(gameLoop) {
    int numP = 0;
    std::cout << "Welcome to Rock, Paper & Scissor!"<< std::endl;
    std::cout << "Game Version: " << RPSgame_VERSION_MAJOR << "." << RPSgame_VERSION_MINOR << std::endl;
    std::cout << "Project Name: " << Project_Name << std::endl;
  
    std::cout << "Enter Number of players [1 or 2] : ";
    std::cin >> numP;
    int contGame = 1;
    
    while (contGame) {
      if(numP == 1) {
        singlePlayer();
        contGame = 0;
      }
      else if (numP == 2) {
        twoPlayers();
        contGame = 0;
      }
      else {
        std::cout << "Invalid Input! Try again!" << std::endl;
      }

    }
    std::cout << "Would you like to play again?" << std::endl;
    std::cout << "[1] Yes  [0] No : ";
    std::cin >> gameLoop;
    system("cls");
  } // EO gameLoop
  std::cout << "Thank you for playing!" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return 0;
}


