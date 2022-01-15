/*Построить иерархию геометрических фигур: Квадрат, Прямоугольник, Круг, Треугольник.
   Для каждой фигуры вывести ее особые свойства (первичные параметры), площадь, периметр 
   и наривать каждую фигуру.*/

#define _USE_MATH_DEFINES

#include <Windows.h>
#include <iostream>

#define delimiter std::cout <<"----------------------------------------------------\n"

enum Color
{
	consol_green  = 0xAA,
	consol_blue  = 0xBB,
	consol_red   = 0xCC,
	consol_white = 0x07,
 
	red   = 0x000000FF, 
	green = 0x0000FF00,
	blue  = 0x00FF0000
};

namespace GeometriShapes
{
	class Shape
	{
	protected:
		Color color;
	public:

		//------------------------Constructors----------------------------------

		Shape(enum::Color color) :color(color)
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

		//---------------------------Destructor-------------------------------

		~Quadrangle()
		{
			std::cout << "QuDestructor:\t" << this << std::endl;
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
			set_side(side);

			std::cout << "SqConstructor:\t" << this << std::endl;
		}

		//------------------------------Destructor------------------------------------------

		~Square()
		{
			std::cout << "SqDestructor:\t" << this << std::endl;
		}

		//------------------------------Methods-------------------------------------------------

		double area(double side)const
		{
			return pow(side, 2);
		}
		double perimeter(double side)const
		{
			return side * 4;
		}
		void drawing()const
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
			SetConsoleTextAttribute(hConsole, consol_white);
		}
		void print()const
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

		double area(double length, double width)const
		{
			return length * width;
		}
		double perimeter(double length, double width)const
		{
			return (length + width) * 2;
		}
		void drawing()const
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
			SetConsoleTextAttribute(hConsole, consol_white);

		}
		void print()const
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
			return 0.5 * side * height();
		}
		double perimeter()const
		{
			return side * 3;
		}
		void draving()const
		{
			int count = side - 1;

			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < i; j++)
				{
					std::cout << " ";
				}

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);

				for (int j = 0; j <= count; j++)
				{
						std::cout << " *";
				}

			SetConsoleTextAttribute(hConsole, consol_white);

				std::cout << std::endl;
				count--;
			}
		}
		void print()const
		{
			std::cout << "Стороны равностороннего треугольника: " << side << std::endl;
			std::cout << "Высота равностороннего треугольника: " << height() << std::endl;
			std::cout << "Площадь равностороннего треугольника: " << area() << std::endl;
			std::cout << "Периметр равностороннего треугольника: " << perimeter() << std::endl;
			std::cout << std::endl;
			draving();
		}
	};

	class IsoscelesTriangle :public Triangle
	{
		double side_A;
		double side_B;
	public:
		double get_side_A()const
		{
			return side_A;
		}
		double get_side_B()const
		{
			return side_B;
		}

		void set_side_A(double side_A)
		{
			if (side_A <= 0)
			{
				side_A = 1;
			}
			this->side_A = side_A;
		}
		void set_side_B(double side_B)
		{
			if (side_B <= 0)
			{
				side_B = 1;
			}
			this->side_B = side_B;
		}

		//------------------------------Constructors-----------------------------

		IsoscelesTriangle(Color color, double side_A, double side_B):Triangle(color)
		{
			set_side_A(side_A);
			set_side_B(side_B);

			std::cout << "IsTrConstructor:\t" << this << std::endl;
		}

		//-------------------------------Destructor-------------------------------

		~IsoscelesTriangle()
		{
			std::cout << "IsTrDestructor:\t" << this << std::endl;
		}

		//-------------------------------Mhetods------------------------------------

		double height()const
		{
			return sqrt(pow(side_A, 2) - pow(side_B / 2, 2));
		}
		double area()const
		{
			return 0.5 * side_B * height();
		}
		double perimeter()const
		{
			return side_A * 2 + side_B;
		}
		void draving()const
		{

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			for (int i = 0; i < side_A; i++)
			{
			SetConsoleTextAttribute(hConsole, color);
				for (int j = 0; j <= i; j++)
				{
					std::cout << " *";
				}

			SetConsoleTextAttribute(hConsole, consol_white);
				std::cout << std::endl;
			}

		}
		void print()const
		{
			std::cout << "Длина сторон равнобедренного треугольник: " << side_A << std::endl;
			std::cout << "Длина основания равнобедренного треугольника: " << side_B << std::endl;
			std::cout << "Высота равнобедренного треугольника: " << height() << std::endl;
			std::cout << "Площадь равнобедренного треугольника: " << area() << std::endl;
			std::cout << "Периметр равнобедренного треугольника: " << perimeter() << std::endl;
			std::cout << std::endl;
			draving();
		}

	};

	class RoundShape :public Shape
	{
	public:

		//----------------------------constructors-------------------------

		RoundShape(Color color) :Shape(color)
		{
			std::cout << "RoShConstructor:\t" << this << std::endl;
		}

		//----------------------------Destructor----------------------------

		~RoundShape()
		{
			std::cout << "RoShDestructor:\t" << this << std::endl;
		}
	};

	class Circle :public RoundShape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}

		void set_radius(double radius)
		{
			if (radius <= 0)
			{
				radius = 1;
			}
			this->radius = radius;
		}

		//----------------------------Constructors---------------------------

		Circle(Color color, double radius) :RoundShape(color)
		{
			set_radius(radius);

			std::cout << "CiConstructor:\t" << this << std::endl;
		}

		//------------------------------Destructor------------------------------

		~Circle()
		{
			std::cout << "CiDestructor:\t" << this << std::endl;
		}

		//-------------------------------Mhetods----------------------------------

		double diameter()const
		{
			return radius * 2;
		}
		double area()const
		{
			return M_PI * pow(radius, 2);
		}
		double perimeter()const
		{
			return diameter() * M_PI;
		}
		void drawing()const
		{
			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);

			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hBrush);
			/*SetDCBrushColor(hdc, RGB(255, 0, 0));*/

			Ellipse(hdc, 1300, 300, 1300 + diameter(), 300 + diameter());

			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void print()const
		{
			std::cout << "Радиус круга: " << radius << std::endl;
			std::cout << "Диаметр круга: " << diameter() << std::endl;
			std::cout << "Площадь круга: " << area() << std::endl;
			std::cout << "Периметр круга: " << perimeter() << std::endl;
			std::cout << std::endl;
			
			while (!GetAsyncKeyState(VK_RETURN))
			{
				drawing();
			}
		}
		
	};

}

int main()
{
	setlocale(LC_ALL, "");

	GeometriShapes::Square square(consol_green, 5);
	delimiter;
	square.print();
	delimiter;

	GeometriShapes::Rectangle rectangle(consol_blue, 5, 10);
	delimiter;
	rectangle.print();
	delimiter;

	GeometriShapes::EquilateralTriangle equilateral_triangle(consol_red, 8);
	delimiter;
	equilateral_triangle.print();
	delimiter;

	GeometriShapes::IsoscelesTriangle isosceles_triangle(consol_blue, 10, 5);
	delimiter;
	isosceles_triangle.print();
	delimiter;

	GeometriShapes::Circle circle(blue, 200);
	delimiter;
	circle.print();
	delimiter;

	
	return 0;
}