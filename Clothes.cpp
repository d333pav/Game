#include <string>

using namespace std;

class Clothes {
private:
	string type = "null";
	string name = "null";
	int weight = -1;
	int id = -1;
public:
	virtual string info() = 0;
	void set_type(string s) { type = s; }
	void set_name(string s) { name = s; }
	void set_weight(int i) { weight = i; }
	void set_id(int i) { id = i; }
	string get_type() { return type; }
	string get_name() { return name; }
	int get_weight() { return weight; }
	int get_id() { return id; }
};

class Hat : public Clothes {
private:
	int effect = -1;
public:
	Hat(int i, string n, int w, int e) {
		set_id(i);
		set_name(n);
		set_weight(w);
		set_effect(e);
		set_type("Hat");
	}
	string info() {
		string s =
			get_type()
			+ "  '" + get_name()
			+ "'  weight: " + to_string(get_weight())
			+ "  effect: " + to_string(get_effect());
		return s;
	}
	void set_effect(int e) { effect = e; }
	int get_effect() { return effect; }
};

class Armor : public Clothes{
private:
	int def;
public:
	Armor(int i, string n, int w, int d) {
		set_id(i);
		set_name(n);
		set_weight(w);
		set_def(d);
		set_type("Armor");
	}
	string info() {
		string s =
			get_type()
			+ "  '" + get_name()
			+ "'  weight: " + to_string(get_weight())
			+ "  defence: " + to_string(get_def());
		return s;
	}
	void set_def(int i) { def = i; }
	int get_def() { return def; }
};

class Boots : public Clothes{
private:
	int sp;
public:
	Boots(int i, string n, int w, int s) {
		set_id(i);
		set_name(n);
		set_weight(w);
		set_sp(s);
		set_type("Boots");
	}
	string info() {
		string s =
			get_type()
			+ "  '" + get_name()
			+ "'  weight: " + to_string(get_weight())
			+ "  sp: " + to_string(get_sp());
		return s;
	}
	void set_sp(int s) { sp = s; }
	int get_sp() { return sp; }
};