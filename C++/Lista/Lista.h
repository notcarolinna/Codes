#pragma once
class List
{
private:
	int* array;
	int count;
	int size;

	void grow();
public:
	List();

	void add(int element);
	bool remove(int element);
	void removeById(int index);
	int get(int index);
	bool contains(int element);

	int getSize();
	bool isEmpty();
	void clear();
};
