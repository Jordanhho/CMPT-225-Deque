//============================================================================
// Name        : Deque.h
// Author      : Jordan Ho
//============================================================================
#pragma once
#include <iostream>

class Node {

public:

	int data;
	Node* next;

    Node() {};
    ~Node() {
    	delete next;
    };
};

class Deque {

private:

	Node* front;
	Node* back;
	int count;

public:

Deque();

Deque(const Deque&);

~Deque();

Deque& operator=(const Deque&);

void insert_front(int);

void insert_back(int);

int remove_front();

int remove_back();

int peek_front() const;

int peek_back() const;

bool empty() const;

int size() const;

};
