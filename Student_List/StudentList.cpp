#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct student {
	string firstName;
	string lastName;
	int id;
	int GPA;
};

vector<student> sl;

int i = 0;

string input = "";
double input2 = 0;

void getStudents() {
	string content;

	sl.empty();

	ifstream f;
	f.open("StudentText.txt");
	content.assign((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));
	f.close();

	int studentCount = 0;

	for (int i = 0; i < content.length(); i++)
	{
		if (content.at(i) == '-') {
			string n1 = "";
			string n2 = "";
			int num = 0;
			int gpa = 0;

			cout << "ey: " << n1 << "," << n2 << "," << num << "," << gpa << "," << endl;

			sl.insert(sl.begin(), student());
			sl[0].firstName = n1;
			sl[0].lastName = n2;
			sl[0].id = num;
			sl[0].GPA = gpa;

			studentCount++;
		}
	}

	cout << "Student Count: " << studentCount << endl;
}

void ADD() {
	input = "";
	input2 = 0;

	string content = "";
	string s = "";

	cout << endl << "Please Input the student's first name: ";
	cin >> input;
	s += "-" + input + ", ";

	cout << endl << "Please Input the student's last name: ";
	cin >> input;
	s += input + ", ";

	cout << endl << "Please Input the student's id: ";
	cin >> input2;
	s += to_string(input2) + ", ";

	cout << endl << "Please Input the student's GPA: ";
	cin >> input2;
	input2 = float(int(input2 * 100 + 0.5)) / 100;
	cout << input2 << endl;
	s += to_string(input2);

	ifstream ifs;
	ifs.open("StudentText.txt");
	content.assign((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	ifs.close();

	content += s + "\n";
	cout << content << endl;

	ofstream f;
	f.open("StudentText.txt");
	f << content;
	cout << "len: " << content.length() << endl;
}

void PRINT() {
	cout << endl;

	string content = "";

	ifstream ifs;
	ifs.open("StudentText.txt");
	content.assign((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	ifs.close();

	ofstream f;
	f.open("StudentText.txt");
	f << content;
	cout << "len: " << content.length() << endl;

	if (content.length() > 0) {
		cout << content;
	}
	else {
		cout << "No students in database!" << endl;
	}
	cout << endl;
}

void DELETE() {
	getStudents();

	int deleteId = 0;

	cout << endl << "Please input the id of the Student you want to delete: ";
	cin >> deleteId;

	for (i = 0; i < sl.size(); i++) {
		if (deleteId == sl[i].id) {
			break;
		}
	}

	if (deleteId == sl[i].id) {
		cout << endl << "Deleted: " << sl[i].firstName << " " << sl[i].lastName << "." << endl;
		sl.erase(sl.begin() + i);
	}
	else {
		cout << "Student not found, cannot delete." << endl;
	}

	cout << endl;
}

void CLEAR() {
	ofstream f;
	f.open("StudentText.txt");
	f << "";
	cout << endl << "Cleared." << endl << endl;
}

int main() {
	while (true) {

		cout << "Please enter one of these commands: add, print, delete, clear, or exit." << endl << endl;

		cin >> input;

		if (input == "ADD" || input == "add") {
			ADD();
		}
		else if (input == "PRINT" || input == "print") {
			PRINT();
		}
		else if (input == "DELETE" || input == "delete") {
			DELETE();
		}
		else if (input == "CLEAR" || input == "clear") {
			CLEAR();
		}
		else if (input == "GET" || input == "get") {
			getStudents();
		}
		else if (input == "exit" || input == "quit") {
			exit(0);
		}
	}

	return 0;
}
