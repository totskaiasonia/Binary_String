#pragma once
#include"S_Node.h"
#include<iostream>
class C_String
{
public:
#pragma region constructors
	C_String();
	C_String(C_String& str);
	C_String(const char* str);
#pragma endregion

#pragma region my methods
	int length();
	void clean();
	void add(char val);
	void add(char* val);
#pragma endregion

#pragma region operators
	char* operator [](int index);
	bool operator ==(C_String& obj);
	bool operator !=(C_String& obj);
	C_String& operator =(C_String& obj);
	C_String* operator +(C_String& obj);
	C_String& operator +=(C_String& obj);
	friend std::ostream& operator <<(std::ostream& out, const C_String& obj)
	{
		S_Node* tmp = obj._head;
		while (tmp != nullptr)
		{
			std::cout << tmp->character;
			tmp = tmp->next;
		}
		return out;
	}
#pragma endregion

	~C_String();
private:
	int num_of_simb;

	S_Node* _head;
};

