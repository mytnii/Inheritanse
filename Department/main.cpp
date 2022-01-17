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
		os << left;
		os << first_name;
		os.width(3);
		os << right;
		os << age;
		os<< " лет  ";
		return os;
	}

	virtual std::istream& employee(std::istream& in)
	{
		getline(in, last_name);
		getline(in, first_name);
		string buffer;
		getline(in, buffer);
		set_age(stoi(buffer));

		return in;
	}

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::istream& operator>>(std::istream& in, Human& obj)
{
	return obj.employee(in);
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
		std::cout << "EConstructor:\t" << this << endl;
	}

	~Employee()
	{
		std::cout << "EDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		os.width(10);
		os << left;
		os << position;
		return os;
	}

	std::istream& employee(std::istream& in)
	{
		Human::employee(in);
		getline(in, position);
		return in;
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
		Employee::print(os);
		os.width(5);
		os << left;
		os << salary;
		return os;
		
	}

	std::istream& employee(std::istream& in)
	{
		Employee::employee(in);
		string buffer;
		getline(in, buffer);
		set_salary(stoi(buffer));

		return in;
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
		Employee::print(os);
		os.width(7);
		os << left;
		os << "тариф: " << rate;

		os.width(10);
		os << left;
		os << " отработано: " << hours;

		os.width(8);
		os << left;
		os << " и того " << get_salary();

		return os;
	}

	std::istream& employee(std::istream& in)
	{
		Employee::employee(in);
		string buffer;
		getline(in, buffer);
		set_rate(stoi(buffer));
		getline(in, buffer);
		set_hours(stoi(buffer));

		return in;
	}
};

//#define EMPLOYEE_DEPARTMENT

void main()
{
	setlocale(LC_ALL, "");

#ifdef EMPLOYEE_DEPARTMENT
	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg", "Ken", 30, "Lawyer", 2000),
		new PermanentEmployee("Diaz", "Ricardo", 50, "Boss", 50000),
		new HourlyEmployee("Vercetty", "Tomas", 30, "Security", 500, 8)
	};
#endif // EMPLOYEE_DEPARTMENT

	Employee* department[] =
	{
		new PermanentEmployee("", "", 0, "", 0),
		new PermanentEmployee("", "", 50, "", 0),
		new HourlyEmployee("", "", 0, "", 0, 0)
	};

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		cin >> *department[i];
	}

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
		fout << string(typeid(*department[i]).name()) + ":" <<  *department[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");

	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		delete department[i];
	}
}