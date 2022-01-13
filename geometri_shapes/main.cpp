/*Построить иерархию геометрических фигур: Квадрат, Прямоугольник, Круг, Треугольник.
   Для каждой фигуры вывести ее особые свойства (первичные параметры), площадь, периметр 
   и наривать каждую фигуру.*/

#include <Windows.h>
#include <iostream>

#define delimiter std::cout <<"----------------------------------------------------\n"
enum Color
{
	green = 0xAA,
	blue = 0xBB,
	yellow = 0xEE,
	white = 0x07
};

namespace GeometriShapes
{

	class Shape
	{
	protected:
		Color color;
	public:

		//------------------------Constructors----------------------------------

		Shape(Color color) :color(color)
		{
			std::cout << "ShConstructor:\t" << this << std::endl;
		}

		//-------------------------Destructor------------------------------------
		virtual ~Shape()
		{
			std::cout << "ShDestructor:\t" << this << std::endl;
		}
	};

	class Quadrangle:public Shape
	{
	public:

		//---------------------------Constructors-----------------------------

		Quadrangle(Color color) :Shape(color)
		{
			std::cout << "QuConstructor" << this << std::endl;
		}

	};

	class Square :public Quadrangle
	{
		double side;
	public:

		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)
			{
				side = 1;
			}
			this->side = side;
		}

		//----------------------------Constructors-------------------------------------

		Square(Color color, double side):Quadrangle(color)
		{
			this->side = side;

			std::cout << "SqConstructor:\t" << this << std::endl;
		}

		//------------------------------Destructor------------------------------------------

		~Square()
		{
			std::cout << "SqDestructor:\t" << this << std::endl;
		}

		//------------------------------Methods-------------------------------------------------

		double area(double side)
		{
			return pow(side, 2);
		}
		double perimeter(double side)
		{
			return side * 4;
		}
		void drawing()
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					std::cout << " *";
				}

				std::cout << std::endl;
			}
			SetConsoleTextAttribute(hConsole, Color::white);
		}
		void print()
		{
			std::cout << "Стороны квадрата: " << side << std::endl;
			std::cout << "Площадь кварата: " << area(side) << std::endl;
			std::cout << "Периметр квадрата: " << perimeter(side) << std::endl;
			std::cout << std::endl;
			drawing();
			std::cout << std::endl;
		}
	};

	class Rectangle :public Quadrangle
	{
		double length;
		double width;
	public:
		double get_lenght()const
		{
			return length;
		}
		double get_width()const
		{
			return width;
		}

		void set_lenght(double length)
		{
			if (length <= 0)
			{
				length = 1;
			}
			this->length = length;
		}
		void set_width(double width)
		{
			if (width <= 0)
			{
				width = 1;
			}
			this->width = width;
		}

		//---------------------------Constructors----------------------------------------

		Rectangle(Color color, double length, double width) :Quadrangle(color)
		{
			this->length = length;
			this->width = width;

			std::cout << "ReConstructor:\t" << this << std::endl;
		}

		//-----------------------------Destructor--------------------------------------------

		~Rectangle()
		{
			std::cout << "ReDestructor:\t" << this << std::endl;
		}

		//------------------------------Methods-------------------------------------------------

		double area(double length, double width)
		{
			return length * width;
		}
		double perimeter(double length, double width)
		{
			return (length + width) * 2;
		}
		void drawing()
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					std::cout << " *";
				}

				std::cout << std::endl;
			}
			SetConsoleTextAttribute(hConsole, white);

		}
		void print()
		{
			std::cout << "Длинна прямоугольника: " << length << std::endl;
			std::cout << "Ширина прямоугольник: " << width << std::endl;
			std::cout << "Площадь прямоугольника: " << area(length, width) << std::endl;
			std::cout << "Периметр прямоугольника: " << perimeter(length, width) << std::endl;
			std::cout << std::endl;
			drawing();


		}
	};

	class Triangle :public Shape
	{
		
	public:
		//----------------------------------Constructors------------------------------------

		Triangle(Color color):Shape(color)
		{
			std::cout << "TrConstructor:" << this << std::endl;
		}

		//-----------------------------------Destructor---------------------------------------

		~Triangle()
		{
			std::cout << "TrDestructor:\t" << this << std::endl;
		}

	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)
			{
				++side;
			}
			this->side = side;
		}

		//-------------------------------Constructors----------------------------------------------

		EquilateralTriangle(Color color, double side) :Triangle(color)
		{
			set_side(side);

			std::cout << "EqTrConstructor:\t" << this << std::endl;
		}

		~EquilateralTriangle()
		{
			std::cout << "EqTrDestructor:\t" << this << std::endl;
		}

		double height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double area()const
		{
			return 0, 5 * side * height();
		}
		double perimeter()const
		{
			return side * 3;
		}
		void draving()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < side; i++)
			{
				for (int j = side / 2; j)
			}
		}
	};

}

int main()
{
	setlocale(LC_ALL, "");

	GeometriShapes::Square square(green, 5);
	delimiter;
	square.print();
	delimiter;

	GeometriShapes::Rectangle rectangle(blue, 5, 10);
	delimiter;
	rectangle.print();
	delimiter;
	
	return 0;
}