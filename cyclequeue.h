#include <iostream>
#pragma once
#define N 10

using namespace std;

class cyclequeue {
private:
	int a[N], back, front;
public:
	cyclequeue() {
		back = -1;
		front = -1;
	}

	bool isempty() {
		if (front == -1) return true;
		else return false;
	}

	bool isfull() {
		if (front == back + 1) {
			return true;
		}
		return false;
	}


	void push(int el) {
		if (isfull()) {
			cout << "cyclequeue's full";
		}
		else {
			if (front == -1) front = 0;
			back = (back + 1) % N;
			a[back] = el;
		}
	}

	int pop() {
		int el;
		if (isempty()) {
			cout << "cyclequeue's empty" << endl;
			return 0;
		}
		else {
			el = a[front];
			if (front == back) {
				front = -1;
				back = -1;
			}
			else 
				front = (front + 1) % N;
			return el;
		}
	}
};
