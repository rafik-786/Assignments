#include <bits/stdc++.h>
using namespace std;

class Number_list {
private:
	int *arr;
	int size;
public:
	Number_list() {
		size = 0;
	}
	void setSize(int size) {
		this->arr = new int(size);
		this->size = size;
	}
	void inputArray(void) {
		for (int i = 0; i < size; i++)cin >> this->arr[i];

	}
	void sort(void) {
		if (size == 0) {
			cout << "No data to sort\n";
			return;
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			}
		}
	}

	void printList(void) {
		for (int i = 0; i < size; i++) cout << this->arr[i] << " ";
		cout << endl;
	}

	pair<int, int> getMaxMin(void) {
		this->sort();
		return {arr[size - 1], arr[0]};
	}

};

int main() {

	Number_list nl;
	nl.setSize(10);
	nl.inputArray();
	nl.sort();
	nl.printList();

	pair<int, int> max_min = nl.getMaxMin();

	cout << "Max: " << max_min.first << endl;
	cout << "Min : " << max_min.second << endl;


	return 0;
}

/*
input
9 8 7 6 5 4 3 2 1 0
*/