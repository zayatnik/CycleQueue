#include <iostream>
#pragma once

using namespace std;

class cyclequeue {
private:
	int *a, back, front, n, max;
public:
	cyclequeue() {
		n = 0;
		max = 10;
		back = -1;
		front = -1;
		a = new int[max];
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
			int *tmp = new int[n];
			for (int i = 0; i < max; i++)
				tmp[i] = a[i];
			delete[] a;
			*a = new int[2 * max];
			max = max * 2;
			for (int i = n - 1; i > front - 1; i--)
				a[n + i] = tmp[i];
			for (int i = 0; i < back; i++)
				a[i] = tmp[i];
			delete[] tmp;
			back = (back + 1) % max;
			a[back] = el;
		}
		else {
			if (front == -1) front = 0;
			back = (back + 1) % max;
			a[back] = el;
		}
		n++;
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
				front = (front + 1) % max;
			n--;
			return el;
		}
	}
};
