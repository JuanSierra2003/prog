#include<iostream>
#include<cstring>

struct Vector3D
{
	//Atributos
	double x;
	double y;
	double z;



	//Funciones de Visualizacion

	//Imprime un vector
	void print()
	{
		std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")\n";
	}

	//Devuelve una string con el vector con 3 cifras significativas
	char* representation()
	{
		char *text = new char[32];
		std::sprintf(text, "(%.2e, %.2e, %.2e)", this->x, this->y, this->z);
		return text;
	}



	//Definicion de Operadores

	//Redefine el operador +
	Vector3D operator+(Vector3D v)
	{
		return Vector3D(this->x + v.x, this->y + v.y, this->z + v.z);
	}

	//Redefine operador +=
	void operator+=(Vector3D v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	//Redefine el operador * para producto punto
	double operator*(Vector3D v)
	{
		return this->x*v.x + this->y*v.y + this->z*v.z;
	}

	//Redefine el operador * para producto con escalar
	Vector3D operator*(double alpha)
	{
		return Vector3D(this->x*alpha, this->y*alpha, this->z*alpha);
	}

	//Redefine el operador *= para producto con escalar
	void operator*=(double alpha)
	{
		this->x *= alpha;
		this->y *= alpha;
		this->z *= alpha;
	}

	//Redefine el operador ==
	int operator==(Vector3D v)
	{
	 return(this->x == v.x && this->y == v.y && this->z == v.z);
	}



	//Constructores y Destructor

	//Constructor por defecto
	Vector3D()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	//Constructor con valores iniciales
	Vector3D(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//Destructor
	~Vector3D()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}
};

int main(int argc, char const *argv[])
{
	Vector3D vector1 = Vector3D(1.0, 2.0, 3.0);
	Vector3D vector2 = Vector3D(4.0, 5.0, 6.0);
	Vector3D vector3 = vector1 + vector2;

	std::cout << vector1.representation() << " * " << vector2.representation() << " = " << vector1*vector2 << std::endl;
	std::cout << vector1.representation() << " + " << vector2.representation() << " = ";
	vector3.print();
	std::cout << "\n";

	std::cout << vector2.representation() << "*2 = ";
	(vector2*2).print();
	std::cout << "\n";
	
	std::cout << vector1.representation() << "*3 = ";
	vector1*=3;
	vector1.print();
	std::cout << "\n";
	
	std::cout << vector1.representation() << " + " << vector2.representation() << " = ";
	vector1 += vector2;
	vector1.print();
	std::cout << "\n";
	
	std::cout << vector1.representation() << " == " << vector2.representation() << " : " << (vector1 == vector2) << std::endl;
	std::cout << vector1.representation() << " == " << vector1.representation() << " : " << (vector1 == vector1);
	return 0;
}