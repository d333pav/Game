#include "Floor.cpp"
#include <vector>
#include <iostream>

int main() {
	Floor_Factory* ff;
	Floor* f;
	for (int i = 3; i < 6; ++i) {
		ff = new Floor_Factory(i);
		f = ff->create();
		cout << f->get_enemy()->info() << endl << "Chest:" << endl;
		for (Clothes* c : f->get_chest()) cout << "   "<< c->info() << endl;
		cout << endl << endl;
	}
	int n;
	cin >> n;

	return 0;
}