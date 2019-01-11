#include "pch.h"

bool IsPalindrome(std::string s);

int main()
{

	std::string p[15] = {
	"Deleveled", "non", "Racecar", "Kayak",
	"Madam", "Level", "Civic", "Noon", "Mom",
	"Rotator", "Don't nod", "I did, did I",
	"yes yes", "Bow wow", "This is a test"
	};

	int len = std::size(p);

	for ( int i = 0; i < len; i++ )
	{

		std::string str = p[i].c_str();		
		bool result  = IsPalindrome(str);

		if (result)
			std::cout << str.c_str() << " is a palindrome" << std::endl;
		else
			std::cout << str.c_str() << " is not a palindrome" << std::endl;
		
	}

	std::cin.get();
}

bool IsPalindrome(std::string p)
{	
	std::string str;
	std::remove_copy_if(p.begin(), p.end(), std::back_inserter(str), ispunct);	
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	std::vector<char> letters(str.begin(), str.end());	
	const int mid = letters.size() / 2;
	
	int counter = 0;
	bool result = true;

	for (auto const& value : letters) {
		if (counter <= mid)
		{
			if (value != letters.at((letters.size() - 1 - counter)))
				result = false;
		}		
		counter += 1;
	}

	return result;

}

