/*Есть 2 типа сотрудников - с постоянной оплатой и с почасовой оплатой.
  Нужно создать массив разнотипных сотрудников, 
  и вычислить зарплату для каждого отдельного струдника, и для всего отдела.
  Можно сохранить сотдуников в файл и загрузить их из файла.*/

#include<iostream>
#include<string>
#include<fstream>

#define delimiter std::cout << "\n----------------------------------------------\n\n";

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

	 std::ostream& print(std::ostream& os)const
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
		in << last_name;
		in << "|";

		in.width(10);
		in << std::left;
		in << first_name;
		in << "|";

		in.width(5);
		in << std::right;
		in << age;
		in << "|  ";

		return in;
	}

	virtual std::ifstream& get_group_txt(std::ifstream& out)
	{
		getline(out, last_name, '|');
		getline(out, first_name, '|');
		std::string buffer;
		getline(out, buffer, '|');
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
		in.width(10);
		in << std::left;
		in << position;
		in <<"|";

		return in;
	}

	std::ifstream& get_group_txt(std::ifstream& out)
	{
		Human::get_group_txt(out);
		getline(out, position, '|');

		std::cout << position << std::endl;

		std::size_t found = position.find_first_not_of(" ");

		position.erase(1, found - 1);

		std::cout << position << std::endl;

		

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
		in.width(5);
		in << std::right;
		in << salary;
		in << "|;";

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
		in.width(5);
		in << std::right;
		in << payment;
		in << "|;";

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

void print(  const Human** group,  int size)
{
	delimiter;

	for (int i = 0; i < size; i++)
	{
		std::cout << *group[i] << std::endl;
	}

	delimiter;

}

void print( Human** group, int size)
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
		fout.width(25);
		fout << std::left;
		fout << typeid(*group[i]).name() << "|";
		fout << *group[i] << std::endl;
	}
	fout.close();

	system("notepad employes.txt");

}

Human** load_from_file(const std::string file_name)
{
	std::ifstream fin;
	fin.open("employes.txt");
	std::string line;
	int str = 0;

	Human** employes_txt = nullptr;

	if (fin.is_open())
	{
		std::cout << "Файл открыт" << std::endl;

		while (!fin.eof())
		{
			getline(fin, line, ';');
			std::cout << line << std::endl;
			str++;
		}

		--str;
		/*std::cout << fin.tellg() << std::endl;*/
		fin.clear();
		fin.seekg(0);
		/*std::cout << fin.tellg() << std::endl;*/

		employes_txt = new Human * [str] {};

		std::cout << str << std::endl;

		for (int i = 0; i < str; i++)
		{
			std::cout << employes_txt[i] << std::endl;
		}
		for (int i = 0; i < str; i++)
		{
			getline(fin, line, '|');

			if (line.find("class Permanent_paymen") != std::string::npos)
			{
				employes_txt[i] = new Permanent_payment("last_name", "first_name", 0, "position", 0);
			}
			else if (line.find("class Hourly_pay") != std::string::npos)
			{
				employes_txt[i] = new Hourly_pay("last_name", "first_name", 0, "position", 0);
			}

			fin >> *employes_txt[i];

			/*std::cout << *employes_txt[i] << std::endl;*/
		}

		return employes_txt;
	}
	else
	{
		std::cout << "Файла не существует" << std::endl;
	}

	fin.close();

	return 0;

}

void del(const Human** employes, const int size)
{
	for (int i = 0; i < size; i++)
	{
		delete employes[i];
	}
}

void del( Human** employes, const int size)
{
	for (int i = 0; i < size; i++)
	{
		delete employes[i];
	}
}


//#define DEBAG
//#define LOAD_FROM_FFILE

void main()
{
	setlocale(LC_ALL, "");

	const Human* employes[] =
	{
		new Permanent_payment("Иван", "Иванов", 35, "Туниядец", 30000),
		new Hourly_pay("Петя", "Петров", 40, "Продавец", 1200),
	};

	delimiter;

	delimiter;

	print(employes, sizeof(employes) / sizeof(Human*));

	save_to_file(employes, sizeof(employes) / sizeof(Human*), "employes.txt");

	del(employes, sizeof(employes) / sizeof(Human*));

	 Human** employes_txt = load_from_file("employes.txt");

#ifdef DEBUG
	std::ifstream fin("employes.txt");
	int count = 0;
	const Human** employes_txt = nullptr;

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

			if (line.find("class Permanent_paymen") != std::string::npos)
			{
				employes_txt[i] = new Permanent_payment("", "", 0, "", 0);
			}
			else if (line.find("class Hourly_pay") != std::string::npos)
			{
				employes_txt[i] = new Hourly_pay("", "", 0, "", 0);
			}
			/*std::string buffer;
			getline(fin, buffer, ',');*/
		}
		fin.close();
	}
	else
	{
		std::cerr << "Ошибка: Файл не существует" << std::endl;
	}

	/*print(employes_txt, count);*/

	/*for (int i = 0; i < count; i++)
	{
		delete employes_txt[i];
	}

	delete[] employes_txt;*/

#endif // DEBUG

#ifdef LOAD_FROM_FFILE

	std::ifstream fin;
	fin.open("employes.txt");
	std::string line;
	int str = 0;

	Human** employes_txt = nullptr;

	if (fin.is_open())
	{
		std::cout << "Файл открыт" << std::endl;

		while (!fin.eof())
		{
			getline(fin, line, ';');
			std::cout << line << std::endl;
			str++;
		}

		--str;
		std::cout << fin.tellg() << std::endl;
		fin.clear();
		fin.seekg(0);
		std::cout << fin.tellg() << std::endl;

		employes_txt = new Human * [str] {};

		std::cout << str << std::endl;

		for (int i = 0; i < str; i++)
		{
			std::cout << employes_txt[i] << std::endl;
		}
		for (int i = 0; i < str; i++)
		{
			getline(fin, line, ':');

			if (line.find("class Permanent_paymen") != std::string::npos)
			{
				employes_txt[i] = new Permanent_payment("last_name", "first_name", 0, "position", 0);
			}
			else if (line.find("class Hourly_pay") != std::string::npos)
			{
				employes_txt[i] = new Hourly_pay("last_name", "first_name", 0, "position", 0);
			}

			fin >> *employes_txt[i];

			std::cout << *employes_txt[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Файла не существует" << std::endl;
	}

	fin.close();

#endif // LOAD_FROM_FILE

	print(employes_txt, sizeof(employes) / sizeof(Human*));
	
	del(employes_txt, sizeof(employes) / sizeof(Human*));

}