#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
	string name;
	int x, y, z;
	
public:
	Student(string name, int x, int y, int z) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	string getName() { return name; }
	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }
};

int N;
vector<Student> student;

bool compare(Student a, Student b) {
	if (a.getX() != b.getX()) {
		return a.getX() > b.getX();
	}
	else if (a.getY() != b.getY()) {
		return a.getY() < b.getY();
	}
	else if (a.getZ() != b.getZ()) {
		return a.getZ() > b.getZ();
	}
	else
		return a.getName() < b.getName();
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0;i < N;i++) {
		string name;
		int x, y, z;
		cin >> name >> x >> y >> z;
		student.push_back(Student(name, x, y, z));
	}

	sort(student.begin(), student.end(), compare);

	for (int i = 0;i < N;i++) {
		cout << student[i].getName() << '\n';
	}
}