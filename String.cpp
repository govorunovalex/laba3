#include "String.h"


String::String() :data(nullptr), size(0) {}

String::String(char new_data[]) : size(0) {
	while (new_data[size] != '\0') {
		++size;
	}
	data = new char[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = new_data[i];
	}
	data[size] = '\0';
}
String::String(int size, char* new_data) :size(size) {
	data = new char[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = new_data[i];
	}
	data[size] = '\0';
}

String::String(const String& other) :size(other.size) {
	data = new char[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
	data[size] = '\0';
}
String& String::operator+=(const String& other) {
	char* temp = new char[size + other.size + 1];
	int i, j;
	for (i = 0; i < size; ++i) {
		temp[i] = data[i];
	}
	for (j = 0; j < other.size; ++j) {
		temp[i + j] = other.data[j];
	}
	temp[i + j] = '\0';
	delete[] data;
	data = temp;
	size = size + other.size;
	return *this;
}

String& String::operator=(const String& other) {
	delete[] data;
	size = other.size;
	data = new char[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
	data[size] = '\0';
	return *this;
}

String& String::operator+=(const char& c) {
	++size;
	char* temp = new char[size + 1];
	for (int i = 0; i < size - 1; ++i) {
		temp[i] = data[i];
	}
	temp[size - 1] = c;
	temp[size] = '\0';
	delete[] data;
	data = temp;
	return *this;
}

String String::operator+(const String& other) {
	String result(*this);
	result += other;
	return result;
}
char& String::operator[](int i) {
	return data[i];
}
bool String::operator<(const String& other) {
	int max_size = (size > other.size) ? size : other.size;
	for (int i = 0; i < max_size; ++i) {
		if (i >= size) return true;
		if (data[i] < other.data[i])
			return true;
	}
	return false;
}
bool String::operator>(const String& other) {
	return !(*this < other);
}
bool String::operator==(const String& other) {
	if (size != other.size) return false;
	else {
		for (int i = 0; i < size; ++i) {
			if (data[i] != other.data[i])
				return false;
		}
	}
	return true;
}
char* String::get_data() {
	return data;
}
int String::get_size() {
	return size;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.data;
	return out;
}
std::istream& operator>>(std::istream& in, String& str) {
	char c;
	do {
		in.read(reinterpret_cast<char*>(&c), 1);
	} while (c == ' ' || c == '\n' || c == '\t');

	while (c != ' ' && c != '\n' && c != '\t') {
		str += c;
		in.read(reinterpret_cast<char*>(&c), 1);
	}
	return in;
}
int String::substr(const String& str) {
	for (int i = 0; i < size - str.size; ++i) {
		if (data[i] == str.data[0]) {
			int j = 0;
			while (data[i + j] == str.data[j] && j < str.size) ++j;
			if (j == str.size) return i;
		}
	}
	return -1;
}
int String::substr(const char c) const {
	for (int i = 0; i < size; ++i) {
		if (data[i] == c) return i;
	}
	return -1;
}
String* String::split(const char c, int& result_count) const {
	int count = 0;
	for (int i = 0; i < size; ++i) if (data[i] == c) ++count;
	result_count = count + 1;
	if (count == 0) {
		return nullptr;
	}
	String* arr = new String[count + 1];

	int i = 0;
	int prev = 0;
	int curr = 0;
	while (curr < size) {
		while (data[curr] != c && curr < size) ++curr;
		arr[i] = String(curr - prev, data + prev);
		prev = ++curr;
		++i;
	}
	return arr;
}
String::~String() {
	delete[] data;
}

String String::multiply(int k) {
	if (k < 1) return String();

	String result(*this);
	for (int i = 0; i < k - 1; ++i) {
		result += *this;
	}
	return result;
}

int* String::allSubstr(const String& str, int& count) {
	if (substr(str) == -1) {
		count = 0;
		return nullptr;
	}
	count = 0;
	int begin = -1;
	for (int i = 0; i < size - str.size; ++i) {
		int temp;
		if ((temp = substr(str, i)) != -1) {
			++count;
			i = temp;
		}
	}
	int* result = new int[count];
	count = 0;
	for (int i = 0; i < size - str.size; ++i) {
		int temp;
		if ((temp = substr(str, i)) != -1) {
			result[count++] = temp;
			i = temp;

		}
	}
	return result;
}

int String::substr(const String& str, int beginFrom) {
	if (beginFrom >= size - str.size) return -1;
	for (int i = beginFrom; i < size - str.size; ++i) {
		if (data[i] == str.data[0]) {
			int j = 0;
			while (data[i + j] == str.data[j] && j < str.size) ++j;
			if (j == str.size) return i;
		}
	}
	return -1;
}

char String::mostrepeatable() {
	char c = '\0';
	int max = 0;
	int* stat = stat_alph_lower();
	for (int i = 0; i < 26; ++i) {
		if (stat[i] > max) {
			max = stat[i];
			c = char(i + 'a');
		}
	}
	return c;
}

String String::unique() {
	String result;
	for (int i = 0; i < size; ++i) {
		if (result.substr(data[i]) == -1) {
			result += data[i];
		}
	}
	return result;
}

int* String::stat_alph_lower() {
	int* result = new int[26];
	for (int i = 0; i < 26; ++i) {
		result[i] = 0;
	}

	for (int i = 0; i < size; ++i) {
		if (data[i] >= 'a' && data[i] <= 'z') {
			result[data[i] - 'a']++;
		}
	}

	return result;
}


