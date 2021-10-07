#include"C_Binary_String.h"

int main()
{
	C_String* str = new C_String("Hello");
	C_String* str2 = new C_String(*str);
	C_String* res = *str + *str2;
	*str += *str2;
	std::cout << *str;
}