#include "Enemy_Factory.cpp"
#include "Clothes_Factory.cpp"
#include <vector>

class Floor {
private:
	int f;
	Enemy* enemy;
	vector<Clothes*> chest;
public:
	Floor(int i) { f = i; }
	void set_floor(int i) { f = i; }
	void set_enemy(Enemy* e) { enemy = e; }
	void set_chest(vector<Clothes*> v) { chest = v; }
	int get_floor() { return f; }
	Enemy* get_enemy() { return enemy; }
	vector<Clothes*> get_chest() { return chest; }

	bool fight() {

		return 0;
	}
};

class Floor_Factory {
private:
	int f = 1;
public:
	Floor_Factory(int i) { f = i; }
	Floor* create() {
		Enemy_Factory* ef;
		if (f % 5 == 0) ef = new Boss_Factory(f);
		else ef = new Mob_Factory(f);
		Floor* floor = new Floor(f);
		floor->set_enemy(ef->create());

		int r = rand() % 3 + 1;
		vector<Clothes*> v;
		Clothes_Factory* cf = new Hat_Factory(f);
		for (int i = 0; i < r; ++i) {
			switch (rand() % 3) {
			case 0: cf = new Hat_Factory(f); break;
			case 1: cf = new Armor_Factory(f); break;
			case 2: cf = new Boots_Factory(f); break;
			}
			v.push_back(cf->create());
		}
		floor->set_chest(v);

		return floor;
	}
};