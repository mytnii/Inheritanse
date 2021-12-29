
#include<iostream>
#include<string>
using namespace std;

#define delimiter cout << "\n---------------------------------------------------------------\n" << endl;

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

	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}

};

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
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	       ):Human(last_name, first_name, age)
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

class Teacher:Human
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
		const std::string & last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
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

class Graduate:Student
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
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student
	   (
		last_name, first_name, age,
		speciality, group, rating, attendance
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

void main()
{
	setlocale(LC_ALL, "");

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
}