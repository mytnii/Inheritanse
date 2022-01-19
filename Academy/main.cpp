
#include<iostream>
#include<string>
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

	// --------------------------Constructors--------------------------------------

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	//Human()
	//{
	//	set_last_name(last_name);
	//	set_first_name(first_name);
	//	set_age(age);
	//}

	//---------------------------Destructor-----------------------------------------

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

		os.width(2);
		os << age;

		return os;
	}

};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}

	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//--------------------Constructors-------------------------------
	Student(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS
	       ):Human(HUMAN_GIVE_PARAMETRES)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}

	//Student() :Human()
	//{
	//	set_speciality(speciality);
	//	set_group(group);
	//	set_rating(rating);
	//	set_attendance(attendance);
	//}

	//---------------------Destructor--------------------------------

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);

		os.width(20);
		os << left;
		os << speciality;

		os.width(6);
		os << left;
		os << group;

		os.width(2);
		os << right;
		os << rating;

		os.width(2);
		os << right;
		os << attendance;

		return os;
	}
<<<<<<< Updated upstream
=======

	std::ofstream& set_group_txt(std::ofstream& out)const
	{
		Human::set_group_txt(out);

		out.width(20);
		out << left;
		out << speciality;
		out << "|";

		out.width(6);
		out << left;
		out << group;
		out << "|";

		out.width(2);
		out << right;
		out << rating;
		out << "|";

		out.width(2);
		out << right;
		out << attendance;
		out << "|";

		return out;
	}

	std::ifstream& get_group_txt(std::ifstream& in)
	{
		getline(in, speciality, '|');
		getline(in, group, '|');
		std::string buffer;
		getline(in, buffer, '|');
		set_rating(stoi(buffer));
		std::string buffer2;
		getline(in, buffer2, '|');
		set_attendance(stoi(buffer));

		return in;
	}
>>>>>>> Stashed changes
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher:public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}

	void set_speciality(const std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//-------------------------Constructors-----------------------------

	Teacher
	(
		HUMAN_TAKE_PARAMETERS,
		TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETRES)
	{
		set_speciality(speciality);
		set_experience(experience);

		cout << "TConstructor:\t" << this << endl;
	}

	//Teacher() :Human()
	//{
	//	set_speciality(speciality);
	//	set_experience(experience);
	//}

	//--------------------------Destructor--------------------------------

	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);

		os.width(20);
		os << left;
		os << speciality;

		os.width(2);
		os << right;
		os << experience;

		return os;
	}
};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
class Graduate:public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}

	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//------------------Constructors----------------------------

	Graduate
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS,
		GRADUATE_TAKE_PARAMETERS
	) :Student
	   (
		HUMAN_GIVE_PARAMETRES,
		STUDENT_GIVE_PARAMETERS
	   )
	{
		set_subject(subject);

		cout << "GConstructor:\t" << this << endl;
	}

	//Graduate() :Student()
	//{
	//	set_subject(subject);
	//}

	//------------------Destructor-----------------------------

	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Student::print(os);

		os.width(10);
		os << left;
		os << subject;

		return os;

	}
};

<<<<<<< Updated upstream
=======
std::ostream& operator<<(std::ostream& os, const  Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& out, const Human& obj)
{
	return obj.set_group_txt(out);
}
std::ifstream& operator>>(std::ifstream& in, Human& obj)
{
	return obj.get_group_txt(in);
}

void save_to_file( Human* group[], const int size, const std::string file_name)
{
	std::ofstream fout(file_name);

	for (int i = 0; i < size; i++)
	{
		fout.width(15);
		fout << left;
		fout << typeid(*group[i]).name() << "|";
		fout << *group[i] << ";" << endl;

	}

	fout.close();

	system("notepad group.txt");
}

Human* human_factory(const std::string& type)
{
	if (type.find("Student") != std::string::npos)
	{
		return new Student("", "", 0, "", "", 0.0, 0.0);
	}
	if(type.find("Teacher") != std::string::npos)
	{
		return new Teacher("", "", 0, "", 0);
	}
	if (type.find("Graduate") != std::string::npos)
	{
		return new Graduate("", "", 0, "", "", 0, 0, "");
	}
}

Human** load_to_file(const std::string file_name)
{
	std::ifstream fin;
	fin.open(file_name);
	std::string line;
	int str = 0;

	Human** group_txt = nullptr;

	if (fin.is_open())
	{
		std::cout << "Файл открыт" << std::endl;

		while (!fin.eof())
		{
			getline(fin, line, ';');
			cout << line << endl;
			str++;
		}

		str--;

		cout << str << endl;

		cout << fin.tellg() << std::endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << std::endl;

		group_txt = new Human * [str] {};

		for (int i = 0; i < str; i++)
		{
			cout << group_txt[i] << endl;
		}

		for (int i = 0; i < str; i++)
		{
			getline(fin, line, '|');
			cout << line << endl;
			
			group_txt[i] = human_factory(line);
			fin >> *group_txt[i];
			
			cout << *group_txt[i] << endl;

		}

	fin.close();

	return group_txt;

	}
	else
	{
		cout << "Файла не существует" << endl;
	}

	return 0;

}

>>>>>>> Stashed changes

//#define INHERITANCE_CHECK
//#define DEBUG

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	delimiter;
	Human human("Connor", "John", 18);
	delimiter;
	human.print();

	delimiter;
	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
	delimiter;
	stud.print();

	delimiter;
	Teacher teacher("Connor", "John", 18, "Chemistry", 5);
	delimiter;
	teacher.print();

	delimiter;
	Graduate graduate
	(
		"Pinkman", "Jessie", 25,
		"Chemistry", "WW_123", 85, 95,
		"Chemistry"
	);
	delimiter;
	graduate.print();

	delimiter;
#endif // INHERITANCE_CHECK
#ifdef DEBUG

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95),
		new Teacher("Connor", "John", 18, "Chemistry", 5),
		new Graduate("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95, "Chemistry"),
		new Student("Vercetti", "Tomas", 30, "City busines", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 55, "Weapons distribution", 30),
		new Student("Montana", "Antonio", 30, "Criminalistic", "Vice", 90, 80)
	};

	cout << sizeof(group) / sizeof(Human*) << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;
		cout << *group[i] << endl;
		delimiter;
	}

<<<<<<< Updated upstream
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
=======
	save_to_file(group, sizeof(group) / sizeof(Human*), "group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
>>>>>>> Stashed changes
	{
		delete group[i];
	}
#endif // DEBUG


	std::string file = "group.txt";

	Human** group_txt = load_to_file("group.txt");

	for (int i = 0; i < sizeof(group_txt) / sizeof(Human*); i++)
	{
		/*cout << typeid(*group_txt[i]).name() << endl;*/
		/*cout << *group_txt[i] << endl;*/
		delimiter;
	}

	for (int i = 0; i < sizeof(group_txt) / sizeof(Human*); i++)
	{
		delete group_txt[i];
	}

	delete[] group_txt;


}