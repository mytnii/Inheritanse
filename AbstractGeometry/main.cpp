#define _USE_MATH_DEFINES

#include<iostream>
#include<Windows.h>
using namespace std;

namespace AbstractGeometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,

		some_colore,
		consol_red = 0xCC,
		consol_green = 0xAA,
		consol_blue = 0x99,
		consol_default = 0x07
	};

	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:
		const int get_start_x()const
		{
			return start_x;
		}
		const int get_start_y()const
		{
			return start_y;
		}
		const int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 300) start_x = 300;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 300) start_y = 300;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 20) line_width = 20;
			this->line_width = line_width;
		}
		Shape(Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}

		virtual~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
	};

	class Quadrangle :public Shape
	{
	public:
		Quadrangle
		(
			Color color, unsigned int start_x,
			unsigned int start_y, unsigned int line_width
		) :Shape(color, start_x, start_y, line_width) {};

		~Quadrangle() {};
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
			if (side <= 10)side = 10;
			this->side = side;
		}

		Square
		(
			double side, Color color,
			unsigned int start_x, unsigned int start_y, unsigned int line_width
		) :Quadrangle(color, start_x, start_y, line_width)
		{
			set_side(side);
		}

		~Square() {};

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}

		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, consol_default);*/

			HWND hConsole = GetConsoleWindow();
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			SelectObject(hdc, hPen);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		void print()const
		{
			cout << "Стороны квадрата:\t" << side << endl;
			cout << "Площадь квадрата:\t" << get_area() << endl;
			cout << "Периметр квадрата:\t" << get_perimeter() << endl;
			while (!GetAsyncKeyState(VK_ESCAPE))
			{
				draw();
			}
		}
	};

	class Rectangle :public Quadrangle
	{
		double length;
		double width;
	public:
		const double get_length()const
		{
			return length;
		}
		const double get_width()const
		{
			return width;
		}
		void set_length(double length)
		{
			if (length <= 15) length = 15;
			this->length = length;
		}
		void set_width(double width)
		{
			if (width <= 10)width = 10;
			this->width = width;
		}

		Rectangle
		(
			double length, double width, Color color,
			unsigned int start_x, unsigned int start_y,
			unsigned int line_width
		) :Quadrangle(color, start_x, start_y, line_width)
		{
			set_length(length);
			set_width(width);
		}

		~Rectangle() {};

		double get_area()const
		{
			return length * width;
		}
		double get_perimeter()const
		{
			return (length + width) * 2;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + length, start_y + width);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		void print()const
		{
			cout << "Длинна прямоугольника:\t" << length << endl;
			cout << "Ширина прямоугольника:\t" << width << endl;
			cout << "Площадь прямоугольника:\t" << get_area() << endl;
			cout << "Периметр прямоугольника:\t" << get_perimeter() << endl;
			while (!GetAsyncKeyState(VK_ESCAPE))
			{
				draw();
			}
		}

	};

	class RoundShape :public Shape
	{
	public:
		RoundShape
		(
			Color color, unsigned int start_x,
			unsigned int start_y, unsigned int line_width
		) : Shape(color, start_x, start_y, line_width)
		{

		};

		~RoundShape()
		{

		}
	};

	class Circle :public RoundShape
	{
		double radius;
	public:
		const double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius <= 10) radius = 10;
			this->radius = radius;
		}

		Circle
		(
			double radius, Color color, unsigned int start_x,
			unsigned int start_y, unsigned int line_width
		) :RoundShape(color, start_x, start_y, line_width)
		{
			set_radius(radius);
		}

		~Circle()
		{

		}

		double get_diameter()const
		{
			return radius * 2;
		}
		double get_area()const
		{
			return M_PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return M_PI * get_diameter();
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			Ellipse(hdc, start_x, start_y, start_x + radius, start_y + radius);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		void print()const
		{
			cout << "Радиус круга:\t" << radius << endl;
			cout << "Диаметр круга:\t" << get_diameter() << endl;
			cout << "Площадь круга:\t" << get_area() << endl;
			cout << "Периметр круга:\t" << get_perimeter() << endl;
			while (!GetAsyncKeyState(VK_ESCAPE))
			{
				draw();
			}
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle
		(
			Color color, unsigned int start_x,
			unsigned int start_y, unsigned int line_width
		) :Shape(color, start_x, start_y, line_width)
		{

		}

		~Triangle()
		{

		}
	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		const double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 10) side = 10;
			this->side = side;
		}

		EquilateralTriangle
		(
			double side, Color color, unsigned int start_x,
			unsigned int start_y, unsigned int line_width
		) :Triangle(color, start_x, start_y, line_width)
		{
			set_side(side);
		}

		~EquilateralTriangle()
		{

		}

		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const
		{
			return 0, 5 * side * get_height();
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			const POINT point[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};

			Polygon(hdc, point, sizeof(point) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hConsole, hdc);
		}
		void print()const
		{
			cout << "Стороны равностороннего треугольника:\t" << side << endl;
			cout << "Высота равностороннего треугольника:\t" << get_height() << endl;
			cout << "Площадь равностороннего треугольника:\t" << get_area() << endl;
			cout << "Периметр равностороннего треугольника:\t" << get_perimeter() << endl;
			while(!GetAsyncKeyState(VK_ESCAPE))
			{
				draw();
			}
		}

	};
		class IsoscelesTriangle :public Triangle
		{/*
			double hip;
			double base;*/
		public:
			/*const double get_hip()const
			{
				return hip;
			}
			const double get_base()const
			{
				return base;
			}
			void set_hip(double hip)
			{
				if (hip <= 10)hip = 10;
				this->hip = hip;
			}
			void set_base(double base)
			{
				if (base <= 20)base = 20;
				this->base = base;
			}*/

			IsoscelesTriangle
			(
				/*double hip, double base,*/
				Color color, unsigned int start_x,
				unsigned int start_y, unsigned int line_width
			) :Triangle(color, start_x, start_y, line_width)
			{
				/*set_hip(hip);
				set_base(base);*/
			}

			~IsoscelesTriangle()
			{

			}


		};

		class IsoscelesRightTriangle :public IsoscelesTriangle
		{
			double hip;
			double base;
		public:
			const double get_hip()const
			{
				return hip;
			}
			const double get_base()const
			{
				return base;
			}
			void set_hip(double hip)
			{
				if (hip <= 10) hip = 10;
				this->hip = hip;
			}
			void set_base(double hip)
			{
				this->base = hip * sqrt(2);
			}

			IsoscelesRightTriangle
			(
				double hip, Color color, unsigned int start_x,
				unsigned int start_y, unsigned int line_width
			) :IsoscelesTriangle(color, start_x, start_y, line_width)
			{
				set_hip(hip);
				set_base(hip);
			}

			~IsoscelesRightTriangle()
			{

			}

			double get_height()const
			{
				return sqrt(pow(hip, 2) - pow(base / 2, 2));
			}
			double get_area()const
			{
				return 0.5 * base * get_height();
			}
			double get_perimeter()const
			{
				return hip * 2 + base;
			}

			void draw()const
			{
				HWND hConsole = GetConsoleWindow();
				HDC hdc = GetDC(hConsole);
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				const POINT point[] =
				{
					{start_x, start_y},
					{start_x, start_y + hip},
					{start_x + hip, start_y + hip}
				};

				Polygon(hdc, point, sizeof(point) / sizeof(POINT));

				DeleteObject(hBrush);
				DeleteObject(hPen);
				ReleaseDC(hConsole, hdc);
			}
			void print()const
			{
				cout << "Бедра равнобедренного прямоугольного треугольника:\t"
					 << hip << endl;
				cout << "Основание равнобедренного прямоугольного треугольника:\t"
					 << base << endl;
				cout << "Высота равнобедренного прямоугольного треугольника:\t"
					 << get_height() << endl;
				cout << "Площадь равнобедренного прямоугольного треугольника:\t"
					 << get_area() << endl;
				cout << "Периметр равнобедренного прямоугольного треугольника:\t"
					 << get_perimeter() << endl;
				while (!GetAsyncKeyState(VK_ESCAPE))
				{
					draw();
				}
			}
		};

		class IsoscelesObtuseTriangle :public IsoscelesTriangle
		{
			double hip;
			double base;
		public:
			const double get_hip()const
			{
				return hip;
			}
			const double get_base()const
			{
				return base;
			}
			void set_hip(double hip)
			{
				if (hip <= 10) hip = 10;
				this->hip = hip;
			}
			void set_base(double hip)
			{
				this->base = hip * sqrt(2);
			}

			IsoscelesObtuseTriangle
			(
				double hip, Color color, unsigned int start_x,
				unsigned int start_y, unsigned int line_width
			) :IsoscelesTriangle(color, start_x, start_y, line_width)
			{
				set_hip(hip);
				set_base(hip);
			}

			~IsoscelesObtuseTriangle()
			{

			}

			double get_height()const
			{
				return sqrt(pow(hip, 2) - pow(base / 2, 2));
			}
			double get_area()const
			{
				return 0.5 * base * get_height();
			}
			double get_perimeter()const
			{
				return hip * 2 + base;
			}

			void draw()const
			{
				HWND hConsole = GetConsoleWindow();
				HDC hdc = GetDC(hConsole);
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				const POINT point[] =
				{
					{start_x, start_y},
					{start_x + 50, start_y + hip},
					{start_x +50 + hip, start_y + hip}
				};

				Polygon(hdc, point, sizeof(point) / sizeof(POINT));

				DeleteObject(hBrush);
				DeleteObject(hPen);
				ReleaseDC(hConsole, hdc);
			}
			void print()const
			{
				cout << "Бедра равнобедренного тупоугольного треугольника:\t"
					<< hip << endl;
				cout << "Основание равнобедренного тупоугольного треугольника:\t"
					<< base << endl;
				cout << "Высота равнобедренного тупоугольного треугольника:\t"
					<< get_height() << endl;
				cout << "Площадь равнобедренного тупоугольного треугольника:\t"
					<< get_area() << endl;
				cout << "Периметр равнобедренного тупоугольного треугольника:\t"
					<< get_perimeter() << endl;
				while (!GetAsyncKeyState(VK_ESCAPE))
				{
					draw();
				}
			}
		};

		class IsoscelesAcuteTriangle :public IsoscelesTriangle
		{
			double hip;
			double base;
		public:
			const double get_hip()const
			{
				return hip;
			}
			const double get_base()const
			{
				return base;
			}
			void set_hip(double hip)
			{
				if (hip <= 20)hip = 20;
				this->hip = hip;
			}
			void set_base(double base)
			{
				if (base <= 10)base = 10;
				this->base = base;
			}

			IsoscelesAcuteTriangle
			(
				double hip, double base, Color color, unsigned int start_x,
				unsigned int start_y, unsigned int line_width
			) :IsoscelesTriangle(color, start_x, start_y, line_width)
			{
				set_hip(hip);
				set_base(base);
			}

			~IsoscelesAcuteTriangle()
			{

			}

			double get_height()const
			{
				return sqrt(pow(hip, 2) - pow(base / 2, 2));
			}
			double get_area()const
			{
				return 0.5 * base * get_height();
			}
			double get_perimeter()const
			{
				return hip * 2 + base;
			}

			void draw()const
			{
				HWND hConsole = GetConsoleWindow();
				HDC hdc = GetDC(hConsole);
				HPEN hPen = CreatePen(PS_SOLID, line_width, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				const POINT point[] =
				{
					{start_x, start_y + hip},
					{start_x + base, start_y + hip},
					{start_x + base / 2, start_y + hip - get_height()}
				};

				Polygon(hdc, point, sizeof(point) / sizeof(POINT));

				DeleteObject(hBrush);
				DeleteObject(hPen);
				ReleaseDC(hConsole, hdc);
			}
			void print()const
			{
				cout << "Бедра равнобедренного остроугольного треугольника:\t"
					<< hip << endl;
				cout << "Основание равнобедренного остроугольного треугольника:\t"
					<< base << endl;
				cout << "Высота равнобедренного остроугольного треугольника:\t"
					<< get_height() << endl;
				cout << "Площадь равнобедренного остроугольного треугольника:\t"
					<< get_area() << endl;
				cout << "Периметр равнобедренного остроугольного треугольника:\t"
					<< get_perimeter() << endl;
				while (!GetAsyncKeyState(VK_ESCAPE))
				{
					draw();
				}
			}
		};
}
void main()
{
	setlocale(LC_ALL, "");

	AbstractGeometry::Square square(250, AbstractGeometry::Color::green, 100, 300, 5);
	square.print();

	system("pause");
	system("cls");

	AbstractGeometry::Rectangle rectangle(400, 250, AbstractGeometry::Color::red, 300, 300, 5);
	rectangle.print();

	system("pause");
	system("cls");

	AbstractGeometry::Circle circle(200, AbstractGeometry::Color::blue, 300, 300, 5);
	circle.print();

	system("pause");
	system("cls");

	AbstractGeometry::EquilateralTriangle equil_triangle
	(
		200, AbstractGeometry::Color::blue,
		300, 300, 5
	);
	equil_triangle.print();

	system("pause");
	system("cls");

	AbstractGeometry::IsoscelesObtuseTriangle isoscel_obtuse_triangle
	(
		200, AbstractGeometry::Color::red,
		300, 300, 5
	);
	isoscel_obtuse_triangle.print();

	system("pause");
	system("cls");

	AbstractGeometry::IsoscelesRightTriangle isoscel_right_triangle
	(
		300, AbstractGeometry::Color::red,
		300, 300, 5
	);
	isoscel_right_triangle.print();

	system("pause");
	system("cls");

	AbstractGeometry::IsoscelesAcuteTriangle isoscel_acute_triangle
	(
		300, 200, AbstractGeometry::Color::red,
		300, 300, 5
	);
	isoscel_acute_triangle.print();
}