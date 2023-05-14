#include <stdio.h>
#include <stdlib.h>

#include <stdexcept>
#include "myStr.h"


String::String(const char* inData)
{
    InitCopyIn(inData);
}

String::String(const String& dataStr) 
{
    InitCopyIn(dataStr.arrey);
}

String::String(String&& moved) noexcept: arrey(moved.arrey), size(moved.size)
{
    moved.arrey = nullptr;
    moved.size = 0;
}

String::~String() 
{
    delete[] arrey;
    arrey = nullptr;
    size = 0;
}

void String::InitCopyIn(const char* inCopyData)
{
    delete[] arrey;
    arrey = new char[strlen(inCopyData)+ 1];
    if (strlen(inCopyData) != 0) { memcpy(arrey, inCopyData, strlen(inCopyData));}
    size = strlen(inCopyData);
    arrey[size] = '\0';
}

String String::Merge(const char* arrey1, const char* arrey2)
{
    String answer;
    answer.size = strlen(arrey1) + strlen(arrey2);
    answer.arrey = new char[answer.size + 1];

    memcpy(answer.arrey, arrey1, strlen(arrey1));
    memcpy(answer.arrey + strlen(arrey1), arrey2, strlen(arrey2));

    answer.arrey[answer.size] = '\0';

    return answer;
}

void String::Append(const char* inData)
{
    *this = std::move(Merge(arrey, inData));
}

void String::Append(const String& inDataStr)
{
    *this = std::move(Merge(arrey, inDataStr.arrey));
}

void String::operator+=(const String& inDataStr)
{
    Append(inDataStr);
}

void String::operator+=(const char* inData)
{
    Append(inData);
}

String& String::operator=(const char* inData)
{
    InitCopyIn(inData);
    return *this;
}

String& String::operator=(const String& inDataStr)
{
    InitCopyIn(inDataStr.arrey);
    return *this;
}

String& String::operator=(String&& moved) noexcept
{
    InitCopyIn(moved);
   
    return *this;
}

String operator+(const String& arr1, const String& arr2)
{
    return String::Merge(arr1.Text(), arr2.Text());
}

String operator+(const String& arr1, const char* arr2)
{
    return String::Merge(arr1.Text(), arr2);
}

String operator+(const char* arr1, const String& arr2)
{
    return String::Merge(arr1, arr2.Text());
}
