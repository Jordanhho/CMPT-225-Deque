//============================================================================
// Name        : Deque.cpps
// Author      : Jordan Ho
//============================================================================
#include <iostream>
#include "stdexcept"
#include "deque.h"


Deque::Deque() {

	front = NULL;
	back = NULL;
	count = 0;
}



Deque::Deque(const Deque& double_queue) {

	front = double_queue.front;
	back = double_queue.back;
	count = double_queue.count;
	Node* frontcopy = double_queue.front;
	Node* temp = front;

	for(int i = 0; i < count; i++) {
		front->data = frontcopy->data;
		frontcopy = frontcopy->next;
		front = front->next;
	}
	front = temp;
	back = double_queue.back;
}



Deque::~Deque() {

	delete front;
	delete back;
}



Deque& Deque::operator=(const Deque& double_queue) {

	front = double_queue.front;
	back = double_queue.back;
	count = double_queue.count;
	return *this;
}



void Deque::insert_front(int element) {

	Node* temp = new Node();
	temp->data = element;

	if ( empty() ) {
		front = temp;
		back = temp;
	}

	else {
		Node* temp_two = front;
		front = temp;
		front->next = temp_two;
	}
	count++;
}



void Deque::insert_back(int element) {

	Node* temp = new Node();
	temp->data = element;
	temp->next = NULL;

	if ( empty() ) {
		front = temp;
		back = temp;
	}

	else {
		Node* temp_two = new Node();
		temp_two->data = element;
		temp_two->next = NULL;
		back->next = temp;
		back = back->next;
		back->next = NULL;
	}

	count++;
}



int Deque::remove_front() {

	if ( empty() ) {
		throw std::runtime_error("ERROR EMPTY!");
	}

	Node* temp = front->next;
	int front_value = front->data;

	if (front != NULL) {
		front = NULL;
		front = temp;
	}

	else {
		front = NULL;
	}

	count--;
	return front_value;
}



int Deque::remove_back() {

	if ( empty() ) {
		throw std::runtime_error("ERROR EMPTY!");
	}

	Node* temp = front;

	for(int i = 0; i < count-2; i++) {
		temp = temp->next;
	}

	int back_value = back->data;
	back->next = NULL;
	back->data = temp->data;
	back = temp;
	count--;
	return back_value;
}



int Deque::peek_front() const {

	if ( empty() ) {
		throw std::runtime_error("ERROR EMPTY!");
	}

	else {
		return front->data;
	}
}



int Deque::peek_back() const {

	if ( empty() ) {
		throw std::runtime_error("ERROR EMPTY!");
	}

	else {
		return back->data;
	}
}



bool Deque::empty() const {

	if (count == 0) {
		return true;
	}

	else {
		return false;
	}
}



int Deque::size() const {

	return count;
}

