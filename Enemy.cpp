#include "Weapon.cpp"
#include <string>

using namespace std;

class Enemy {
private:
	string name;
	int hp;
	int dmg;
	int exp;
	int money;
public:
	virtual string info() = 0;
	void set_name(string s) { name = s; }
	void set_hp(int i) { hp = i; }
	void set_dmg(int i) { dmg = i; }
	void set_exp(int i) { exp = i; }
	void set_money(int i) { money = i; }
	string get_name() { return name; }
	int get_hp() { return hp; }
	int get_dmg() { return dmg; }
	int get_exp() { return exp; }
	int get_money() { return money; }
};

class Mob : public Enemy {
private:
	Weapon* weapon;
public:
	string info() {
		string s = "Enemy:   Name: " + get_name()
			+ "  hp: " + to_string(get_hp())
			+ "  dmg: " + to_string(get_dmg())
			+ "  exp: " + to_string(get_exp())
			+ "  money " + to_string(get_money())
			+ "  weapon: ";
		return s;
	}
	void set_weapon(Weapon* w) { weapon = w; }
	Weapon* get_weapon() { return weapon; }
};

class Boss : public Enemy {
private:
	string roar;
	int effect;
	//Relic relic;
public:
	string info() {
		string s = "Boss:   Name: " + get_name()
			+ "  hp: " + to_string(get_hp())
			+ "  dmg: " + to_string(get_dmg())
			+ "  exp: " + to_string(get_exp())
			+ "  money " + to_string(get_money())
			+ "  roar: " + roar
			+ "  effect: " + to_string(effect);
		return s;
	}
	void set_roar(string s) { roar = s; }
	void set_effect(int i) { effect = i; }
	string get_roar() { return roar; }
	int get_effect() { return effect; }
};