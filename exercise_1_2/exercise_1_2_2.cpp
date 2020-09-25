#include <iostream>

int main()
{
    // Part 2: Palindrome Check

    // Input string from command-line
    std::string str;
    std::cout << "Enter String:" << std::endl;
    std::cin >> str;

    // Palindrome Check
    int left = 0;
    int right = str.size() - 1;
    bool is_palindrome = true;

    while (left < right) {
    	if (str[left] != str[right]) {
    		is_palindrome = false;
    		break;
    	}
    	left++;
    	right--;
    }

    std::cout << str << " is" << (is_palindrome ? "" : " NOT") << " a Palindrome" << std::endl;

    return 0;
}
