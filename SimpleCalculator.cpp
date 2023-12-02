/*
TASK - 2
--------------- SIMPLE CALCULATOR ---------------------
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform
*/

#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "-----------Simple Calculator-----------\n";
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /.\n";
            break;
    }

    return 0;
}
