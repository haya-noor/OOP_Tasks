#include<iostream>
#include<iostream>
using namespace std;

//Base class SHAPES
class shapes
{
protected:
	float length, width;

public:
	shapes()
	{
		length = 0.0;
		width = 0.0;
	}

	~shapes() {}

	void setter(float l, float w)
	{
		length = l;
		width = w;
	}

	virtual void getter() = 0;
	virtual float area() = 0;
};


// Derived class 2D
class two_D :public shapes
{
public:
	two_D() :shapes() {}

	~two_D() {}

	void setter(float l, float w)
	{
		shapes::setter(l, w);
	}

	virtual void getter() = 0;

	virtual float area() = 0;

};


//Derived class 3D
class three_D :public shapes
{
protected:
	float height;

public:
	three_D() :shapes()
	{
		height = 0;
	}

	~three_D() {}

	void setter(float l, float w, float h)
	{
		shapes::setter(l, w);
		height = h;
	}

	virtual void getter() = 0;

	virtual float area() = 0;

	virtual float volume() = 0;
};

//Child class CIRCLE of 2D 
class circle :public two_D
{
protected:
	float radius;
	string color;

public:
	circle() :two_D()
	{
		radius = 0.0;
		color = " ";
	}

	~circle() {}

	void setter(float l, float w, float r, string c)
	{
		two_D::setter(l, w);
		radius = r;
		color = c;
	}

	virtual void getter()
	{
		cout << "Enter length:";
		cin >> length;
		cout << "Enter width:";
		cin >> width;
		cout << "Enter radius:";
		cin >> radius;
		cout << "Enter color:";
		cin >> color;
	}

	virtual float area()
	{
		float a;
		cout << "Area of circle:";
		a = 3.14 * radius * radius;
		return a;
	}
};


//Child class SQUARE of 2D
class square :public two_D
{
protected:
	int side;
	string color;

public:
	square() :two_D()
	{
		side = 0;
		color = " ";
	}

	~square() {}

	void setter(float l, float w, int s, string c)
	{
		two_D::setter(l, w);
		side = s;
		color = c;
	}

	virtual void getter()
	{
		cout << "Enter width:";
		cin >> width;
		cout << "Enter length of one side:";
		cin >> side;
		cout << "Enter color:";
		cin >> color;
	}

	virtual float area()
	{
		cout << "Area of square:";
		return side * side;
	}

};


//Child class CUBE  of 3D
class cube :public three_D
{
public:
	cube() :three_D() {}

	~cube() {}

	void setter(float l, float w, float h)
	{
		three_D::setter(l, w, h);
	}

	virtual void getter()
	{
		cout << "Enter length:";
		cin >> length;
		cout << "Enter width:";
		cin >> width;
		cout << "Enter height:";
		cin >> height;
	}

	virtual float area()
	{
		cout << "Area of cube:";
		return 6 * height * height;
	}

	virtual float volume()
	{
		cout << "\nVolume of cube:";
		return height * height * height;
	}
};


//Child class PYRAMID  of 3D
class pyramid :public three_D
{
private:
	float base;

public:
	pyramid() :three_D() {}

	~pyramid() {}

	void setter(float l, float w, float h, float b)
	{
		three_D::setter(l, w, h);
		base = b;
	}

	virtual void getter()
	{
		cout << "Enter length:";
		cin >> length;
		cout << "Enter width:";
		cin >> width;
		cout << "Enter height:";
		cin >> height;
		cout << "Enter base:";
		cin >> base;
	}

	virtual float area()
	{
		cout << "Area of pyramid:";
		return length * width * height;
	}

	virtual float volume()
	{
		float vol;
		cout << "\nVolume of pyramid:";
		vol = (length * width * height) / 3;
		return vol;
	}
};

int main()
{
	two_D* t;

	three_D* th;


	cout << "Enter all the values positive.\n";

	cout << "Circle:\n";
	circle c;
	t = &c;
	cout << "Circle getter:\n";
	c.getter();
	cout << "Circle area:\n";
	cout << c.area();


	cout << "\nSquare:\n";
	square sq;
	t = &sq;
	cout << "Square getter:\n";
	sq.getter();
	cout << "Square area:\n";
	cout << sq.area();


	cout << "\nCube:\n";
	cube cu;
	th = &cu;
	cout << "Cube getter:\n";
	th->getter();

	cout << th->area();

	cout << th->volume();

	cout << endl;
	cout << "Pyramid:\n";
	pyramid p;
	th = &p;
	cout << "Pyramid getter:\n";
	p.getter();
	cout << p.area();
	cout << p.volume();
}