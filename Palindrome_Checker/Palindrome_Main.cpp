
#include<iostream>
#include<string>
#include<regex> //to remove non alphanumeric symbols


bool isPalindrome(std::string input);
void checkResult(bool result);

int main() 
{
	std::string str;
	
	std::cout << "Please type in a word" << std::endl;
	std::getline(std::cin, str);
	
	checkResult(isPalindrome(str));

	std::getchar();
	return 0;
}

bool isPalindrome(std::string input) {
	//remove all but alphanumeric symbols script, including whitespace (regex)
	std::string str = std::regex_replace(input, std::regex("[^A-Za-z0-9]"), "");

	//make all characters lowercase
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	bool result = false;
	int j = str.length() - 1;
	int i = 0;
	while (i != (str.length() / 2)) {
		
		
		if (str[i] != str[j]) {
			//std::cout << str[i] << " " << str[j] << std::endl;
			result = false;
			break;
		}
		else {
			//std::cout << str[i] << " " << str[j] << std::endl;
			result = true;
			++i;
			--j;
		}

			
	}
	return result;

}

void checkResult(bool result) {
	if (result) {
		std::cout << "This is a palindrome" << std::endl;
	}
	else
		std::cout << "This is not a palindrome" << std::endl;
}

