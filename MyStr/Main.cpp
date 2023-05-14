#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "myStr.h"
#include <list>

bool lexicographComp(const String& txt1, const String& txt2)
{
    return !std::lexicographical_compare(txt1.Text(), txt1.Text() + txt1.Length(), txt2.Text(), txt2.Text() + txt2.Length(), [](char tXt1, char tXt2) { return tolower(tXt1) < tolower(tXt2); });
}

int main()
{
    std::cout << "strings count:\n";
    size_t count = 0;
    std::cin >> count;

    std::cout << "enter strings:\n";
    std::list<String> strings;

    const int maxLen = 1000;
    char str[maxLen];
    for (int i = 0; i < count; ++i) 
    {
        std::cin >> str;
        strings.emplace_back(str);
    }

    strings.sort(lexicographComp);

    std::cout << "strings in reverse lexicographic order:\n";
    for (const String& s : strings)
        std::cout << s.Text() << "\n";

    std::cout << "sum of strings:\n";

    String a;
    a = " hjfo_tf+f a ya ustal pilit svoy string";
    std::cout << "a = " << a << "\n";

    String b; 
    b = "ff g+_)(dgfh privrt vsem";
    std::cout << "b = " << b << "\n";

    String c = a + b;
    std::cout << "a + b = " << c << "\n";
    

    return 0;
}

