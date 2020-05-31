#include "String.h"


int main() {
	char data[] = "123";
	String s1(data);
	s1 += 'a';
	std::cout << s1 << std::endl;
	String s2, s3;
	std::cin >> s2;
	std::cin >> s3;
	std::cout << "s3 in s2 on pos: " << s2.substr(s3) << std::endl;
	std::cout << s1 + s2 << "|" << std::endl;
	char find_and_split;
	std::cin >> find_and_split;
	std::cout << s2.substr(find_and_split) << std::endl;
	int n;
	String* arr = s2.split(find_and_split, n);
	std::cout << "Split result:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << std::endl;
	}
	int* arr2 = s2.allSubstr(s3, n);
	std::cout << "All substr result:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << arr2[i] << std::endl;
	}
	std::cout << "Used characters in s2:\n";
	int* stat = s2.stat_alph_lower();
	for (int i = 0; i < 26; ++i) {
		std::cout << char(i + 'a') << " : " << stat[i] << std::endl;
	}
	std::cout << "Most repeatable in s2:\n";
	std::cout << s2.mostrepeatable() << std::endl;

	std::cout << "Unique characters in s2:\n";
	std::cout << s2.unique() << std::endl;
	delete[] stat;
	delete[] arr;
	delete[] arr2;
	return 0;
}
