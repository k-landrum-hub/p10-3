/*
* groups simlar numbers in arrays
* korbin landrum
* 10/29/26 
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes
void displayRun(int values[], int size);
bool hasRun(int values[], int size);

int main() {
    // Initialize random seed
    srand((time(0)));

    // Step 1: Hard-coded Test Arrays
    int test1[] = { 1, 2, 3 };
    int test2[] = { 2, 2 };
    int test3[] = { 4, 4, 1 };
    int test4[] = { 1, 5, 5 };
    int test5[] = { 6, 6, 6, 3, 3 };
    int test6[] = { 1, 5, 5, 5, 5, 5, 2 };

    cout << "Test Arrays\n\n";

    int* tests[] = { test1, test2, test3, test4, test5, test6 };
    int sizes[] = { 3, 2, 3, 3, 5, 7 };

    for (int k = 0; k < 6; k++) {
        cout << "Test " << k + 1 << ": ";
        if (hasRun(tests[k], sizes[k])) {
            cout << "has run: ";
        }
        else {
            cout << "no run:  ";
        }
        displayRun(tests[k], sizes[k]);
        cout << "\n";
    }

    // Step 2: Generate 20 Random Die Tosses
    cout << "\n20 Random Die Tosses\n\n";
    const int DICE_SIZE = 20;
    int dice[DICE_SIZE];

    for (int i = 0; i < DICE_SIZE; i++) {
        dice[i] = rand() % 6 + 1; // Generates number 1 through 6
    }

    if (hasRun(dice, DICE_SIZE)) {
        cout << "has run: ";
    }
    else {
        cout << "no run:  ";
    }
    displayRun(dice, DICE_SIZE);
    cout << endl;

    return 0;
}

// Determines if an array contains at least one set of adjacent duplicates
bool hasRun(int values[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (values[i] == values[i + 1]) {
            return true;
        }
    }
    return false;
}

