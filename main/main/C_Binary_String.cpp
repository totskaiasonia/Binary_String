#include "C_Binary_String.h"

C_String::C_String()
{
	this->num_of_simb = 0;
	this->_head = new S_Node;
	this->_head->character = new char[10];
	this->_head->next = nullptr;
	this->_head->prev = nullptr;
}
C_String::C_String(C_String& str)
{
	this->num_of_simb = 0;
	this->_head = new S_Node;
	this->_head->character = NULL;
	this->_head->next = nullptr;
	this->_head->prev = nullptr;
	S_Node* tmp = str._head;
	for (int i = 0; i < str.length(); i++)
		this->add(str[i]);
}
C_String::C_String(const char* str)
{
	this->num_of_simb = 0;
	this->_head = new S_Node;
	this->_head->character = NULL;
	this->_head->next = nullptr;
	this->_head->prev = nullptr;
	for (int i = 0; i < strlen(str); i++)
		this->add(str[i]);
}

int C_String::length()
{
	return this->num_of_simb;
}
void C_String::clean()
{
	S_Node* dead_node = this->_head->next;
	this->_head->next = nullptr;
	delete dead_node;
	this->_head->character = (char*)" ";
	this->num_of_simb = 1;
}
void C_String::add(char val)
{
	if (this->_head->character == NULL)
	{
		this->_head->character = new char[10];
		int tmp2 = val;
		_itoa_s(tmp2, this->_head->character, 10, 2);
	}
	else
	{
		S_Node* tmp = this->_head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new S_Node;
		tmp->next->character = new char[10];
		int tmp2 = val;
		_itoa_s(tmp2, tmp->next->character, 10, 2);
		tmp->next->next = nullptr;
		tmp->next->prev = tmp;
	}
	this->num_of_simb++;
}
void C_String::add(char* val)
{
	if (this->_head->character == NULL)
	{
		this->_head->character = new char[10];
		this->_head->character = val;
	}
	else
	{
		S_Node* tmp = this->_head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new S_Node;
		tmp->next->character = new char[10];
		tmp->next->character = val;
		tmp->next->next = nullptr;
		tmp->next->prev = tmp;
	}
	this->num_of_simb++;
}

char* C_String::operator [](int index)
{
	char* returned = nullptr;
	S_Node* tmp = this->_head;
	for (int i = 0; i < this->num_of_simb; i++)
	{
		if (i == index)
		{
			returned = tmp->character;
			break;
		}
		tmp = tmp->next;
	}
	return returned;
}
bool C_String::operator ==(C_String& obj)
{
	bool is_equal = true;
	for (int i = 0; i < this->num_of_simb; i++)
	{
		if (*(*this)[i] != *obj[i])
		{
			is_equal = false;
			break;
		}
	}
	return is_equal;
}
bool C_String::operator !=(C_String& obj)
{
	return !(*this == obj);
}
C_String& C_String::operator =(C_String& obj)
{
	this->num_of_simb = obj.num_of_simb;
	this->_head = obj._head;
	return *this;
}
C_String* C_String::operator +(C_String& obj)
{
	C_String* res = new C_String(*this);
	S_Node* tmp = res->_head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = obj._head;
	tmp->next->prev = tmp;
	return res;
}
C_String& C_String::operator +=(C_String& obj)
{
	this->num_of_simb += obj.num_of_simb;
	S_Node* tmp = this->_head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = obj._head;
	tmp->next->prev = tmp;
	return *this;
}

C_String::~C_String()
{
	delete this->_head;
}