#pragma once
#include <iostream>
class String {
	char* data;
	int size;
public:
	String();

	String(char new_data[]);
	String(int size, char* new_data);
	String(const String& other);
	String& operator+=(const String& other);
	String& operator=(const String& other);
	String& operator+=(const char& c);
	String operator+(const String& other);
	char& operator[](int i);
	bool operator<(const String& other);
	bool operator>(const String& other);
	bool operator==(const String& other);
	char* get_data();
	int get_size();
	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);
	int substr(const String& str);
	int substr(const char c) const;
	String* split(const char c, int& result_count) const;
	~String();
	String multiply(int k);
	int* allSubstr(const String& str, int& count);
	int substr(const String& str, int beginFrom);
	char mostrepeatable();
	String unique();
	int* stat_alph_lower();
};