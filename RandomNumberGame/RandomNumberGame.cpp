#include <iostream>
#include <cstdlib>
#include <ctime>

// Add system specific commands
void clear_screen() {
#ifdef _WIN32
	std::system("cls");
#else
	// Assuming POSIX
	std::system("clear");
#endif
}

int main() {
	char repeater;
	do {
		// initialize variables
		int num, guess, tries = 0;
		srand(time(0));
		num = rand() % 100 + 1;
		double min = 1;
		double max = 100;
		// greeting
		std::cout << "This program generates a random number\n";
		std::cout << "between 1 and 100 and then prompts the\n";
		std::cout << "user to guess the number. The program\n";
		std::cout << "counts the number of guesses until the\n";
		std::cout << "user enters the correct number\n";
		std::cout << "======================================\n";

		do {
			std::cout << "Enter a guess between " << min << " and " << max << " : ";
			std::cin >> guess;
			tries++;

			if (guess > num) {
				std::cout << "Too high, try again!\n\n";
				max = guess;
			}
			else if (guess < num) {
				std::cout << "Too low, try again!\n\n";
				min = guess;
			}
			else
				std::cout << "\nCorrect! You got it in " << tries << " guesses!\n";
		} while (guess != num);
		std::cout << "Would you like to play again? (y/n) ";
		std::cin >> repeater;
		if (repeater == 'y')
			clear_screen();
	} while (repeater != 'n');
	return 0;	
}