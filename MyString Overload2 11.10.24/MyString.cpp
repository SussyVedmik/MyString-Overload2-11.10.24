#include "MyString.h"
#include <cstring>
#include <iostream>

int MyString::objectCount = 0;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(int size) {
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(const char* initStr) {
    length = strlen(initStr);
    str = new char[length + 1];
    strcpy(str, initStr);
    objectCount++;
}

MyString::MyString(const MyString& obj) {
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
    objectCount++;
}

MyString::~MyString() {
    delete[] str;
    objectCount--;
}

void MyString::Input() {
    delete[] str;
    str = new char[length + 1];
    std::cout << "Введите строку: ";
    std::cin.getline(str, length);
}

void MyString::Output() const {
    std::cout << str << std::endl;
}

void MyString::MyStrcpy(const MyString& obj) {
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
}

bool MyString::MyStrStr(const char* substr) const {
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c) const {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() const {
    return strlen(str);
}

void MyString::MyStrCat(const MyString& b) {
    char* temp = new char[length + b.length + 1];
    strcpy(temp, str);
    strcat(temp, b.str);
    delete[] str;
    str = temp;
    length += b.length;
}

void MyString::MyDelChr(char c) {
    int pos = MyChr(c);
    if (pos != -1) {
        for (int i = pos; i < length - 1; i++) {
            str[i] = str[i + 1];
        }
        str[length - 1] = '\0';
        length--;
    }
}

int MyString::MyStrCmp(const MyString& b) const {
    int result = strcmp(str, b.str);
    if (result < 0) return -1;
    if (result > 0) return 1;
    return 0;
}

MyString& MyString::operator=(const MyString& obj) {
    if (this != &obj) {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }
    return *this;
}

MyString MyString::operator+(const MyString& b) const {
    MyString temp(length + b.length);
    strcpy(temp.str, str);
    strcat(temp.str, b.str);
    return temp;
}

char& MyString::operator[](int index) {
    if (index >= 0 && index < length) {
        return str[index];
    }
    else {
        throw std::out_of_range("Индекс за пределами строки");
    }
}

MyString& MyString::operator++() {
    char* temp = new char[length + 2];
    strcpy(temp, str);
    strcat(temp, " ");
    delete[] str;
    str = temp;
    length++;
    return *this;
}

MyString MyString::operator++(int) {
    MyString temp(*this);
    ++(*this);
    return temp;
}

void MyString::operator()() {
    std::cout << "Введите строку: ";
    char buffer[256];
    std::cin.getline(buffer, 256);
    delete[] str;
    length = strlen(buffer);
    str = new char[length + 1];
    strcpy(str, buffer);
}

MyString MyString::operator+(char c) const {
    MyString temp(length + 1);
    strcpy(temp.str, str);
    temp.str[length] = c;
    temp.str[length + 1] = '\0';
    return temp;
}

MyString operator+(char c, const MyString& obj) {
    MyString temp(obj.length + 1);
    temp.str[0] = c;
    strcpy(temp.str + 1, obj.str);
    return temp;
}

MyString MyString::operator+(int count) const {
    MyString temp(length + count);
    strcpy(temp.str, str);
    for (int i = 0; i < count; i++) {
        temp.str[length + i] = '*';
    }
    temp.str[length + count] = '\0';
    return temp;
}

MyString operator+(int count, const MyString& obj) {
    return obj + count;
}

int MyString::getObjectCount() {
    return objectCount;
}
