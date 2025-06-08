#pragma once
#include <iostream>

using namespace std;


template <typename T>
class Vector {
private:
	T* data;
	int size;
	int capacity;

	void resize(int c) {
		capacity = c;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		//delete[] newData;
	}

public:
	Vector() {
		size = 0;
		capacity = 1;
		data = new T[capacity];
	}
	
	~Vector() {
		delete[] data;
	}

	int Size() {
		return size;
	}

	int Capacity() {
		return capacity;
	}

	bool is_empty() {
		return size == 0;
	}

	T at(int index) {
		if (index >= size) {
			cout << "The index you entered is out of boundries" << endl;
			throw out_of_range("The index you entered is out of boundries");
		}

		return data[index];
	}

	void push(T item) {
		if (size >= capacity) {
			resize(capacity * 2);
		}

		*(data + size) = item;
		size++;
	}

	void insert(int index, T item) {
		if (index > size) {
			cout << "Out of boundries" << endl;
			return;
		}

		if (size > capacity) {
			resize(capacity * 2);
		}

		for (int i = size; i > index; i--) {
			*(data + (i)) = *(data + (i - 1));
		}

		*(data + index) = item;
		size++;
	}

	void prepend(T item) {
		if (size > capacity) {
			resize(capacity * 2);
		}

		for (int i = size; i > 0; i--) {
			*(data + (i)) = *(data + (i - 1));
		}

		*(data) = item;
		size++;
	}

	T pop() {
		if (size == 0) {
			cout << "the array is empty" << endl;
			throw out_of_range("Vector is empty");
		}
		size--;
		T temp = data[size];

		resize(size);
	
		return temp;
	}

	void delete_element(int index) {
		if (index > size) {
			cout << "Out of boundries" << endl;
			return;
		}

		for (int i = index; i < size ; i++) {
			*(data + i) = *(data + (i + 1));
		}

		size--;
	}

	void remove(T item) {
		for (int i = 0; i < size; i++) {
			if (data[i] == item) {
				delete_element(i);
				--i;
			}
		}
	}

	T find(T item) {
		for (int i = 0; i < size; i++) {
			if (data[i] == item) {
				return i;
			}
		}
		return -1;
	}

};
