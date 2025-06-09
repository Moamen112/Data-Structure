#pragma once

using namespace std;

template <typename T>

class LinkedList {
private:
	struct Node {
		T item;
		Node* next;

		Node(T value) {
			item = value;
			next = nullptr;
		}
	};

	Node* head;
	int _size;
	Node* tail;

public:
	LinkedList() {
		head = nullptr;
		_size = 0;
		tail = nullptr;
	}

	int size() {
		return _size;
	}

	bool is_empty() {
		return head == NULL || _size == 0;
	}

	T value_at(int index) {
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}

		if (index > _size) {
			throw  out_of_range("Out of range");
		}

		Node* temp = head;
		
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		return temp->item;
	}

	void push_front(T value) {
		Node* tempNode = new Node(value);
		if (is_empty()) {
			head = tail = tempNode;
			_size++;
			return;
		}

		tempNode->next = head;
		head = tempNode;
		_size++;
	}

	T pop_front() {
		T temp;
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}

		if (_size == 1) {
			temp = head->item;
			head = NULL;
			_size--;
			return temp;
		}

		temp = head->item;
		head = head->next;
		_size--;
		return temp;
		
	}

	void push_back(T value) {
		Node* tempNode = new Node(value);
		if (tail == NULL || head == NULL) {
			head  = tempNode;
			tail = tempNode;
			_size++;
			return;
		}

		tail->next = tempNode;
		tail = tempNode;
		_size++;
	}

	T pop_back() {
		T temp;
		Node* prevPt = nullptr;

		for (prevPt = head; prevPt->next != tail; prevPt = prevPt->next) {
			;
		}

		temp = tail->item;
		*prevPt->next = NULL;
		tail = prevPt;
		_size--;
		return temp;
	}

	T front() {
		return head->item;
	}

	T back() {
		return tail->item;
	}

	void insert(int index, T value) {
		Node* tempNode = new Node(value);
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}

		if (index > _size) {
			throw  out_of_range("Out of range");
		}

		if (index == 0) {
			tempNode->next = head;
			head = tempNode;
			_size++;
			return;
		}

		Node* tempPt = head;

		for (int i = 1; i < index; i++) {
			tempPt = tempPt->next;
		}

		tempNode->next = tempPt->next;
		tempPt->next = tempNode;
		_size++;
		
	}

	void erase(int index) {
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}

		if (index > _size) {
			throw  out_of_range("Out of range");
		}

		if (index == 0) {
			head = head->next;
			_size--;
			return;
		}

		Node* temp = head;

		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}

		if (temp->next == tail) {
			temp->next = NULL;
			tail = temp->next;
			_size--;
			return;
		}

		temp->next = temp->next->next;
		_size--;

	}

	T value_n_from_end(int n) {
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}

		if (n == _size) {
			return head->item;
		}

		if (n == 1) {
			return tail->item;
		}

		Node* pt = head;

		for (int i = 0; i < _size - (n); i++) {
			pt = pt->next;
		}

		return pt->item;
	}

	void reverse() {
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}
		Node* current = head;
		Node* next = nullptr;
		Node* prev = nullptr;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		tail = head;
		head = prev;
	}

	void remove_value(T value) {
		if (is_empty()) {
			throw out_of_range("The list is empty");
		}
		Node* temp = head;

		while (temp->next->item != value) {
			temp = temp->next;
		}

		temp->next = temp->next->next;
		_size--;
	}

	void print_all() {
		Node* temp = head;

		while (true) {
			if (temp == NULL) {
				break;;
			}
			cout << temp->item << " - ";
			temp = temp->next;
		}

		cout << endl;
	}

};



