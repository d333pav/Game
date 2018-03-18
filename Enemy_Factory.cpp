#include "Enemy.cpp"

class Enemy_Factory {
private:
	int floor;
public:
	virtual Enemy* create() = 0;
	void set_floor(int f) { floor = f; }
	int get_floor() { return floor; }
};

class Mob_Factory : public Enemy_Factory {
public:
	Mob_Factory(int f) { set_floor(f); }
	Enemy* create() {
		Weapon* w = new Weapon;
		Mob* m = new Mob;
		m->set_weapon(w); //example
		m->set_dmg(get_floor() * 10);
		m->set_hp(get_floor() * 10);
		m->set_exp (get_floor() * 10);
		m->set_money(get_floor() * 10);
		string s;
		switch (rand() % 2) {
		case 0: s = "Ghost"; break;
		case 1: s = "Spider"; break;
		}
		m->set_name(s);
		return m;
	}
};

class Boss_Factory : public Enemy_Factory {
public:
	Boss_Factory(int f) { set_floor(f); }
	Enemy* create() {
		//Relic* w = new Relic;
		Boss* m = new Boss;          //example
		string r;
		int e;
		switch (rand() % 2) {
		case 0: e = 1; r = "rrooooar"; break;
		case 1: e = 2; r = "arrrrrrg"; break;
		}
		m->set_dmg(get_floor() * 100);
		m->set_hp(get_floor() * 100);
		m->set_exp(get_floor() * 100);
		m->set_money(get_floor() * 100);
		string s;
		switch (rand() % 2) {
		case 0: s = "Egh"; break;
		case 1: s = "Uno"; break;
		}
		m->set_name(s);
		m->set_effect(e);
		m->set_roar(r);
		return m;
	}
};