#include "List.h"

#include <cstddef>

List::List()
{
	this->count = 0;
	this->size = 10;
	this->array = new int[size];
}

void List::add(int element)
{
	if (count == size)
	{
		// grow();
	}

	array[count] = element;
	count++;
}

int List::get(int index)
{
	if (index > count || index < 0)
	{
		return NULL;
	}

	return array[index];
}

bool List::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (element == array[i])
			return true;
	}

	return false;
}

bool List::remove(int element)
{
	for (int i = 0; i < count; i++) {
		if (element == array[i]) {
			for (int j = i; j < count - 1; j++) {
				array[j] = array[j + 1];
			}
			array[count - 1] = NULL;
			count--;
			return true;
		}
	}

	return false;
}

void List::removeById(int index)
{
	for (int j = index; j < count - 1; j++) {
		array[j] = array[j + 1];
	}
	array[count - 1] = NULL;
	count--;
}

int List::getSize()
{
	return size;
}

bool List::isEmpty()
{
	return count == 0;
}

void List::clear()
{

	delete array;

	this->count = 0;
	this->size = 10;
	this->array = new int[size];
}





