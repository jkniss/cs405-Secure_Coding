// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <stdlib.h> // added to use exit()

// declare function
bool checkOverflow(char user_input[]);

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.
  
  // created new variable to hold value returned from checkOverflow()
  bool overflowFlag = false;
	
  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";
  std::cin >> user_input;

	/* set overflowFlag to value returned by function, checking user input. If true, program will print message and terminate program */

	overflowFlag = checkOverflow(user_input);
	if (overflowFlag == true) {
		std::cout << "Buffer overflow detected, program terminating!!!" << std::endl;
		exit (EXIT_FAILURE);
	}
  

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


bool checkOverflow(char user_input[]) {
    /* Function takes one parameter, user input array.
    Checks the length of this array with pointer arithmetic, and compares the value to MAX_ARRAY. Returns boolean overflowFlag */
    
    bool overflowFlag = false;
    const int MAX_ARRAY = 20;
	long len = *(&user_input + 1) - user_input;
	
	if (len >= MAX_ARRAY || len < 0) {
		overflowFlag = true;
	}
    
    return overflowFlag;
}
