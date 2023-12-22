#include <iostream>
#include <string>

int main() {
    std::string input = "i love you";
    std::string outputString;
    std::string tempString;

    for (int i = input.length() - 1; i >= 0; --i) {
        if (input[i] != ' ') {
            tempString += input[i];
        }
        else {
            std::reverse(tempString.begin(), tempString.end());
            outputString += tempString + ' ';
            tempString = "";
        }
    }

    std::reverse(tempString.begin(), tempString.end());
    outputString += tempString;

    std::cout << outputString << std::endl;

    return 0;
}
