#pragma once  
#include <iostream>  
using namespace std;  

class Queue {  
private:  
	int _size;  
	int capacity;  
	int initiate;
	int end;
	int* data;  

public:  
	Queue(int size) {  
		capacity = size;  
		_size = 0;  
		data = new int[capacity];  
		initiate = 0;  
		end = 0;
	} 

	~Queue() {
		delete[] data;
	}

	bool full() const {  
		return _size == capacity;  
	}  

	void enqueue(int value) {  
		if (full()) {  
			cout << "The queue is full" << endl;  
			return;  
		}  
		data[end] = value;
		end = (end + 1) % capacity;
		_size++;
	}  

	int dequeue() {  
		if (empty()) {
			cout << "The queue is empty" << endl;
			throw out_of_range("The queue is empty");
		}
		int temp = data[initiate];
		initiate = (initiate + 1) % capacity;
		_size--;
		return temp;
	}  

	bool empty() const {
		return _size == 0;
	}
};
