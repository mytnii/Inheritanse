/*���� 2 ���� ����������� - � ���������� ������� � � ��������� �������.
  ����� ������� ������ ����������� �����������, 
  � ��������� �������� ��� ������� ���������� ���������, � ��� ����� ������.
  ����� ��������� ���������� � ���� � ��������� �� �� �����.*/

#include<iostream>
#include<string>
#include<fstream>

#define delimiter std::cout << "\n----------------------------------------------\n\n";
class Human;
std::ifstream& operator<<(std::ifstream& out, Human& obj);


class Human
{
	std::string last_name;
	std::string first_name;
	int age;

public:

	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}

	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}

	void set_age(const int age)
	{
		this->age = age;
	}

	//---------------------Constructors--------------------------

	Human(const std::string last_name, const std::string first_name, const int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);

		std::cout << "Hconstructor:\t" << this << std::endl;
	}

	//-----------------------Destructor---------------------------

	virtual ~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

	//------------------------Metods--------------------------------

	virtual std::ostream& print(std::ostream& os)const
	{
		os.width(10);
		os << std::left;
		os << last_name;

		os.width(10);
		os << std::left;
		os << first_name;

		os.width(5);
		os << std::right;
		os << age;
		os << "  ";

		return os;
	}

	virtual std::ofstream& set_group_txt(std::ofstream& in)const
	{
		in.width(10);
		in << std::left;
		in << last_name + ",";

		in.width(10);
		in << std::left;
		in << first_name + ",";

		in.width(5);
		in << std::right;
		in << age;
		in << ",";

		return in;
	}

	virtual std::ifstream& get_group_txt(std::ifstream& out)
	{
		getline(out, last_name, ',');
		getline(out, first_name, ',');
		std::string buffer;
		getline(out, buffer, ',');
		set_age(stoi(buffer));

		return out;
	}
};

class Employee :public Human
{
	std::string position;

public:

	void set_position(const std::string& position)
	{
		this->position = position;
	}

	//-------------------------Constructors------------------------------

	Employee
	(
		const std::string& last_name, const std::string first_name, const int age,
		const std::string& position
	):Human(last_name, first_name, age)
	{
		set_position(position);

		std::cout << "EConstructor:\t" << this << std::endl;
	}

	//-----------------------Destructor----------------------------------------

	~Employee()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}

	//-----------------------Metods---------------------------------------------

	std::ofstream& set_group_txt(std::ofstream& in)const
	{
		Human::set_group_txt(in);
		in.width(15);
		in << std::left;
		in << position + ",";

		return in;
	}

	std::ifstream& get_group_txt(std::ifstream& out)
	{
		Human::get_group_txt(out);
		getline(out, position, ',');

		return out;
	}
	 std::ostream& print(std::ostream& os)const
	{
		Human::print(os);

		os.width(10);
		os << std::left;
		os << position;

		return os;
	}
};

class Permanent_payment :public Employee
{
	int salary;

public:

	void set_salary(const int salary)
	{
		this->salary = salary;
	}

	//------------------Constructors--------------------------

	Permanent_payment
	(
		const std::string& last_name, const std::string& first_name, const int age,
		const std::string position,
		const double salary
	) :Employee
	(
		last_name, first_name, age,
		position
	)
	{
		set_salary(salary);

		std::cout << "PpConstructor:\t" << this << std::endl;
	}

	//--------------------Destructor--------------------------------

	~Permanent_payment()
	{
		std::cout << "PpDestructor:\t" << this << std::endl;
	}

	//--------------------Metods--------------------------------------

	std::ofstream& set_group_txt(std::ofstream& in)const
	{
		Employee::set_group_txt(in);
		in.width(10);
		in << std::right;
		in << salary;
		in << ";";

		return in;
	}

	std::ifstream& get_group_txt(std::ifstream& out)
	{
		Employee::get_group_txt(out);
		std::string buffer;
		getline(out, buffer, ';');
		set_salary(stoi(buffer));

		return out;
	}

	std::ostream& print(std::ostream& os)const
	{
		Employee::print(os);
		
		os.width(10);
		os << std::right;
		os << salary;

		return os;
	}
};

class Hourly_pay :public Employee
{
	int payment;

public:

	void set_payment(const double payment)
	{
		this->payment = payment;
	}

	//-----------------------Constructors-------------------------------

	Hourly_pay
	(
		const std::string& last_name, const std::string& first_name, const int age,
		const std::string& position,
		const double payment
	) :Employee
	(
		last_name, first_name, age,
		position
	)
	{
		set_payment(payment);

		std::cout << "HpConstructor:\t" << this << std::endl;
	}

	//---------------------------Destruction------------------------------

	~Hourly_pay()
	{
		std::cout << "HpDestructor:\t" << this << std::endl;
	}

	//---------------------------Metods-----------------------------------

	std::ofstream& set_group_txt(std::ofstream& in)const
	{
		Employee::set_group_txt(in);
		in.width(10);
		in << std::right;
		in << payment;
		in << ";";

		return in;
	}

	std::ifstream& get_group_txt(std::ifstream& out)
	{
		Employee::get_group_txt(out);
		std::string buffer;
		getline(out, buffer, ';');
		set_payment(stoi(buffer));

		return out;
	}

	 std::ostream& print(std::ostream& os)const
	{
		Employee::print(os);

		os.width(10);
		os << std::right;
		os << payment;

		return os;
	}

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& in, const Human& obj)
{
	return obj.set_group_txt(in);
}

std::ifstream& operator>>(std::ifstream& out,  Human& obj)
{
	return obj.get_group_txt(out);
}

void print(const Human** group, const int size)
{
	delimiter;

	for (int i = 0; i < size; i++)
	{
		std::cout << *group[i] << std::endl;
	}

	delimiter;

}

void save_to_file(const Human* group[], const int size, const std::string file_name)
{
	std::ofstream fout(file_name);


	for (int i = 0; i < size; i++)
	{
		fout << typeid(*group[i]).name() << ":";
		fout << *group[i] << std::endl;
	}
	fout.close();
}

//Human** load_from_file(const std::string file_name)
//{
//	std::ifstream fin(file_name);
//		int count = 0;
//		Human** employes_txt = nullptr;
//
//	if (fin.is_open())
//	{
//		std::string buffer;
//
//		while (!fin.eof())
//		{
//			getline(fin, buffer, ';');
//			count++;
//		}
//
//		std::cout << count << std::endl;
//
//		employes_txt = new Human * [--count]{};
//		fin.clear();
//		fin.seekg(0);
//		for (int i = 0; i < count; i++)
//		{
//			getline(fin, buffer, '\t');
//
//			if (buffer == "class Permanent_paymen")
//			{
//				employes_txt[i] = new Permanent_payment("", "", 0, "", 0);
//				fin >> *employes_txt[i];
//			}
//			else if (buffer == "class Hourly_pay")
//			{
//				employes_txt[i] = new Hourly_pay("", "", 0, "", 0);
//				fin >> *employes_txt[i];
//			}
//		}
//		fin.close();
//	}
//	else
//	{
//		std::cerr << "������: ���� �� ����������" << std::endl;
//	}
//
//	return 0;
//
//}



void main()
{
	setlocale(LC_ALL, "");

	const Human* employes[] =
	{
		new Permanent_payment("����", "������", 35, "��������", 30000),
		new Hourly_pay("����", "������", 40, "��������", 1200),
	};

	print(employes, sizeof(employes) / sizeof(Human*));

	save_to_file(employes, sizeof(employes) / sizeof(Human*), "employes.txt");

	system("notepad employes.txt");



	for (int i = 0; i < sizeof(employes) / sizeof(Human*); i++)
	{
		delete employes[i];
	}

	//Human** employees = load_from_file("group.txt");

	std::ifstream fin("employes.txt");
	int count = 0;
		const Human**employes_txt = nullptr;

	if (fin.is_open())
	{
		std::string line;

		while (!fin.eof())
		{
			getline(fin, line, ';');
			count++;
		}
		count--;

		std::cout << count << std::endl;

		fin.clear();
		fin.seekg(0);
		for (int i = 0; i < count; i++)
		{
			getline(fin, line, ':');

			if (line == "class Permanent_paymen")
			{
				employes_txt[i] = new Permanent_payment("", "", 0, "", 0);
			}
			else if (line == "class Hourly_pay")
			{
				employes_txt[i] = new Hourly_pay("", "", 0, "", 0);
			}
			std::string buffer;
			getline(fin, buffer, ';');
		}
		fin.close();
	}
	else
	{
		std::cerr << "������: ���� �� ����������" << std::endl;
	}

	print(employes_txt, count);

	for (int i = 0; i < count; i++)
	{
		delete employes_txt[i];
	}


}