#include<iostream>
#include<string>
#include<fstream>

using namespace std;


#define delimiter cout << "\n---------------------------------------------------------------\n" << endl;
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRES last_name, first_name, age
class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return first_name;
	}

	const std::string& get_first_name()const
	{
		return first_name;
	}

	unsigned int get_age()const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//          Constructors

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os)const
	{
		os.width(10);
		os << left;
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << " лет";
		return os;
	}

	virtual std::ofstream& print(std::ofstream& os)const
	{
		os << left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age;
		return os;
	}

	virtual std::ifstream& scan(std::ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}

std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
	return obj.scan(is);
}

#define EMPLOYEE_TAKE_PARAMETERS const std::string& position
#define EMPLOYEE_GIVE_PARAMETERS position

class Employee :public Human
{
	std::string position;
public:
	const std::string get_position()const
	{
		return position;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}
	virtual double get_salary()const = 0;

	Employee(HUMAN_TAKE_PARAMETERS, EMPLOYEE_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETRES)
	{
		set_position(position);
		cout << "EConstructor:\t" << this << endl;
	}

	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os) << " ";
		return os << position;
	}

	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os.width(10);
		os << position;
		return os;

	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> position;
		return is;
	}

};

#define PERMANENT_EMPLOYEE_TAKE_PARAMETERS double salary
#define PERMANENT_EMPLOYEE_GIVE_PARAMETERS  salary

class PermanentEmployee :public Employee
{
	double salary;
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}

	PermanentEmployee
	(
		HUMAN_TAKE_PARAMETERS,
		EMPLOYEE_TAKE_PARAMETERS,
		PERMANENT_EMPLOYEE_TAKE_PARAMETERS
	) :Employee(HUMAN_GIVE_PARAMETRES, EMPLOYEE_GIVE_PARAMETERS)
	{
		set_salary(salary);
		cout << "PEConstructor:\t" << this << endl;
	}

	~PermanentEmployee()
	{
		cout << "PEDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Employee::print(os) << " ";
		os << right;
		os.width(10);
		os << salary;

		return os;
		
	}

	std::ofstream& print(std::ofstream& os)const
	{
		Employee::print(os) << " ";
		os << right;
		os.width(10);
		os << salary;

		return os;

	}
	ifstream& scan(ifstream& is)
	{
		Employee::scan(is);
		is >> salary;
		return is;
	}
};

#define HOURLY_EMPLOYEE_TAKE_PARAMETERS double rate, int hours
#define HOURLY_EMPLOYEE_GIVE_PARAMETERS  rate, hours


class HourlyEmployee :public Employee
{
	double rate;
	int hours;
public:
	double get_rate()const
	{
		return rate;
	}

	int get_hourse()const
	{
		return hours;
	}
	double get_salary()const
	{
		return rate * hours;
	}
	void set_rate(double rate)
	{
		this->rate = rate;
	}
	void set_hours(int hours)
	{
		this->hours = hours;
	}

	HourlyEmployee
	(
		HUMAN_TAKE_PARAMETERS,
		EMPLOYEE_TAKE_PARAMETERS,
		HOURLY_EMPLOYEE_TAKE_PARAMETERS
	) :Employee(HUMAN_GIVE_PARAMETRES, EMPLOYEE_GIVE_PARAMETERS)
	{
		set_rate(rate);
		set_hours(hours);
		cout << "HEConstructor:\t" << this << endl;
	}

	~HourlyEmployee()
	{
		cout << "HEDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Employee::print(os) << " ";
		os << "тариф:";
		os.width(10);
		os << right;
		os << rate;
		os << " ,отработано: ";
		os.width(5);
		os << hours << " и того " << get_salary();
		return os;
	}

	std::ofstream& print(std::ofstream& os)const
	{
		Employee::print(os) << " ";
		os.width(10);
		os << right;
		os << rate;
		os.width(3);
		os << hours;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Employee::scan(is);
		is >> rate >> hours;
		return is;
	}
};

Employee* EmployeeFactory(const string& type)
{
	if (type.find("PermanentEmployee") != std::string::npos)
	{
		return new PermanentEmployee("", "", 0, "", 0);
	}
	if (type.find("HourlyEmployee") != std::string::npos)
	{
		return new HourlyEmployee("", "", 0, "", 0, 0);
	}
}

//#define SAVE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef SAVE_TO_FILE
	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg", "Ken", 30, "Lawyer", 2000),
		new PermanentEmployee("Diaz", "Ricardo", 50, "Boss", 50000),
		new HourlyEmployee("Vercetty", "Tomas", 30, "Security", 500, 8)
	};

	double total_salary = 0;

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{


		//department[i]->print();
		cout << *department[i] << endl;
		total_salary += department[i]->get_salary();
		delimiter
	}

	cout << "Общая зарплата всего отдела: " << total_salary << endl;
	delimiter;

	ofstream fout("file.txt");

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		fout.width(25);
		fout << left;
		fout << string(typeid(*department[i]).name()) + ":";
		fout << *department[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		delete department[i];
	}
#endif // SAVE_TO_FILE

	Employee** department = nullptr;
		int n = 0;

	ifstream fin("file.txt");

	if (fin.is_open())
	{
		string employee_type;
		for (; !fin.eof(); n++)
		{
			getline(fin, employee_type);
		}
		cout << n << endl;
		department = new Employee * [n] {};

		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;
		for (int i = 0; i < n; i++)
		{
			getline(fin, employee_type, ':');
			department[i] = EmployeeFactory(employee_type);
			fin >> *department[i];
		}
		for (int i = 0; i < n; i++)
		{
			cout << *department[i] << endl;
		}

		for (int i = 0; i < n; i++)
		{
			delete department[i];
		}

	}
	else
	{
		cerr << "Error: file not found" << endl;
	}

	delete[] department;
	fin.close();
}