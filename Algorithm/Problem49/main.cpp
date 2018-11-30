#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>

//1,1,3,5,8,13,3,5,8,8,5
const std::string str = "Adjectives are used with nouns to make the meaning more specific. If you use the noun ¡®bear¡¯ it can mean any animal of that species.As soon as you say ¡®a large, brown bear¡¯ you have given two of its attributes(colour and size).A noun is said to be modified by its adjectives.djectives have two main features : ";
bool isalpha(char n) {
	return n >= 'A' && n <= 'z';
}
int main() {

	std::map<char, int> histogram;

	for (auto & ch : str) {
		if (isalpha(ch)) histogram[ch]++;
	}


	for (auto & ch : histogram) {
		std::cout << ch.first << " " << ch.second << std::endl;
	}
}