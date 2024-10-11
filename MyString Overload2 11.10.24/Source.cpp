#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
    MyString str1("Ich");
    MyString str2("bin");
    str1.Output();
    str2.Output();

    MyString str3 = str1 + str2;
    str3.Output();

    MyString str4;
    str4.MyStrcpy(str1);
    str4.Output();

    int cmp = str1.MyStrCmp(str2);
    cout << "Результат сравнения: " << cmp << endl;

    int index = str1.MyChr('e');
    cout << "Индекс символа 'e': " << index << endl;

    str1.MyDelChr('h');
    str1.Output();

    str4();
    str4.Output();

    MyString str5 = str4 + 'A';
    str5.Output();

    MyString str6 = 'B' + str4;
    str6.Output();

    MyString str7 = str4 + 10;
    str7.Output();

    MyString str8 = 10 + str4;
    str8.Output();

    MyString str9 = str4++;
    str9.Output();
    str4.Output();

    ++str4;
    str4.Output();

    cout << "Количество объектов: " << MyString::getObjectCount() << endl;

    return 0;
}
