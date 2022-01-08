
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

	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
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

	//             Constructors
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

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
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

	//                  Constructors

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

	//                Destructor

	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
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

	//           Constructors

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

	//           Destructor

	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	void print()const
	{
		Student::print();
		cout << subject << endl;

	}
};


//#define INHERITANCE_CHECK

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
		group[i]->print();
		delimiter;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}