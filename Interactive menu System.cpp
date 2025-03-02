#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int number;
int rows;
int limit;
string str;

void showMenu() {
    cout << "========= Interactive Utility Program =========\n";
    cout << "1. Factorial Calculator\n";
    cout << "2. Number Pyramid\n";
    cout << "3. Sum of Even or Odd Numbers\n";
    cout << "4. Reverse a String\n";
    cout << "5. Exit\n";
    cout <<"==============================================\n";
}

int factorial(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

void numberPyramid(int rows) {
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows - i; ++j) {
            cout << " ";
        }
        for (int k = 1; k <= i; ++k) {
            cout << k << " ";
        }
        cout << endl;
    }
}

int sumEvenOrOdd(int limit, bool even) {
    int sum = 0;
    int i = even ? 2 : 1;
    do {
        sum += i;
        i += 2;
    } while (i <= limit);
    return sum;
}

string reverseString(string str) {
    int n = str.length();
    int i = 0, j = n - 1;
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}
string reverseString(const string& str) {
    string reversedStr = str; 
    std::reverse(reversedStr.begin(), reversedStr.end()); 
    return reversedStr; 
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            cout << "Enter a number to calculate: ";
            cin >> number;
            cout << "Factorial of " << number << " is " << factorial(number) << endl;
            break;

            case 2:
            int rows;
            cout << "Enter the number of rows for the pyramid: ";
            cin >> rows;
            numberPyramid(rows);
            break;
        
            case 3:
            int limit;
            char choice;
            cout << "Enter the limit: ";
            cin >> limit;
            cout << "Sum even or odd numbers? (e/o): ";
            cin >> choice;
            bool even = (choice == 'e');
            cout << "Sum is " << sumEvenOrOdd(limit, even) << endl;
            break;

            case 4:
            string str;
            cout << "Enter a string to reverse: ";
            cin >> str;
            cout << "Reversed string: " << reverseString(str) << endl;
            break;

            case 5:
            cout << "Thank you for using this menu System!\n";
            break;
            default:
            cout << "Invalid Number. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}