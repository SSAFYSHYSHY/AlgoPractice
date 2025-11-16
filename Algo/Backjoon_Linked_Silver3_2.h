#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
	int id;
	int width;
	Node* prev;
	Node* next;
	Node(int i, int w) : id(i), width(w), prev(nullptr), next(nullptr) {}
};

int len;

int main() {

	int cnt = 1;
	while (1) {
		cin >> len;

		if (len == -1) break;

		Node* head = new Node(-1, 0);
		Node* tail = new Node(-1, 0);
		head->next = tail;
		tail->prev = head;

		int used = 0;

		unordered_map<int, Node*> mp;

		while (1) {
			string s;
			cin >> s;

			if (s == "E") break;

			else if (s == "A") {
				int idx, size;

				cin >> idx >> size;

				Node* node = new Node(idx, size);
				node->next = head->next;
				node->prev = head;
				head->next->prev = node;
				head->next = node;

				mp[idx] = node;
				used += size;

				//넘어가는 책.
				while (used > len) {
					Node* last = tail->prev;
					if (last == head) break;

					used -= last->width;
					mp.erase(last->id);

					last->prev->next = tail;
					tail->prev = last->prev;

					delete last;
				}
			}

			else if (s == "R") {
				int id;
				cin >> id;

				if (mp.count(id)) {
					Node* curr = mp[id];
					used -= curr->width;

					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;

					mp.erase(id);
					delete curr;
				}
			}
		}

		cout << "PROBLEM " << cnt++ << ":";
		Node* curr = head->next;
		bool flag = true;

		while (curr != tail) {
			cout << (flag ? " " : " ") << curr->id;
			flag = false;
			curr = curr->next;
		}
		cout << "\n";

		curr = head;
		while (curr) {
			Node* nxt = curr->next;
			delete curr;
			curr = nxt;
		}

	}

}