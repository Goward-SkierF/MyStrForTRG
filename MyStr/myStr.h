#pragma once
class String
{
public:

	explicit String(const char* inData);
	String(const String& dataStr);
	String(String&& moved) noexcept;
	~String();

	String() = default;
	

	static String Merge(const char* arrey1, const char* arrey2);
	void Append(const char* inData);
	void Append(const String& inDataStr);
	void InitCopyIn(const char* inCopyData);

	void operator+=(const String& inDataStr);
	void operator+=(const char* inData);
	String& operator=(const char* inData);
	String& operator=(const String& inDataStr);
	String& operator=(String&& moved) noexcept;

	explicit operator const char* () { return arrey; };
	operator char* () const { return arrey; };

	const char* Text() const { return arrey; };
	size_t Length() const { return size; };
	
private:
	char* arrey = nullptr;
	size_t size = 0;
	
};

String operator+(const String& left, const String& right);
String operator+(const String& left, const char* right);
String operator+(const char* left, const String& right);
