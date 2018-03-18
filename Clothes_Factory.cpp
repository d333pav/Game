#include "Clothes.cpp"

class Clothes_Factory {
private:
	int floor;
public:
	virtual Clothes* create() = 0;
	void set_floor(int f) { floor = f; }
	int get_floor() { return floor; }
};

class Hat_Factory : public Clothes_Factory {
public:
	Hat_Factory(int f) { set_floor(f); }
	Clothes* create() {
		string s;
		int w;
		int e;
		switch (rand() % 2){
			case 0: w = 1; s = "Cat ears"; e = 1; break;
			case 1: w = 2; s = "Tall hat"; e = 2; break;
		}
		Hat* h = new Hat(1, s, w, e);
		return h;
	}
};

class Armor_Factory : public Clothes_Factory {
public:
	Armor_Factory(int f) { set_floor(f); }
	Clothes* create() {
		string s;
		int w;
		int d;
		switch (rand() % 2) {
		case 0: w = 1; s = "Wooden armor"; d = get_floor()*1; break;
		case 1: w = 2; s = "Iron armor"; d = get_floor()*2; break;
		}
		Armor* h = new Armor(1, s, w, d);
		return h;
	}
};

class Boots_Factory : public Clothes_Factory {
public:
	Boots_Factory(int f) { set_floor(f); }
	Clothes* create() {
		string s;
		int w;
		int sp;
		switch (rand() % 2) {
		case 0: w = 1; s = "Slippers"; sp = get_floor()*1; break;
		case 1: w = 2; s = "Common boots"; sp = get_floor()*2; break;
		}
		Boots* h = new Boots(1, s, w, sp);
		return h;
	}
};