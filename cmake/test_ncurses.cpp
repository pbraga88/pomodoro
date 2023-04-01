#include <ncurses.h>

int main()
{
    // Initialize ncurses
    initscr();
    
    // Print a prompt and get user input
    printw("Enter a command: ");
    char input_command[256];
    getstr(input_command);
    
    // Clear the screen
    clear();

    // Print the user's input
    printw("You entered: %s", input_command);
    
    // Refresh the screen to display the output
    refresh();

    // Wait for a keypress before exiting
    getch();

    // End ncurses
    endwin();

    return 0;
}