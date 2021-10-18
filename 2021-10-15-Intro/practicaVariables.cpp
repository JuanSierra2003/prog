#include <iostream>

int main()
{
	float _float;
	std::cout << "Float (No inicializado): " << _float << std::endl;
	bool _bool = false;
	std::cout << "Bool: " << _bool << std::endl;
	double _double;
	std::cout << "Double: Direccion de memoria " << &_double << " Talla " << sizeof(double) << std::endl;
	float _float2 = 1.0e40;
	std::cout << "Float (Inicializado): " << _float2 << std::endl;
	/*Al inicializar una variable numerica en un valor mas grande al que puede almacenar
	en el espacio reservado para esta el programa otorga el valor inf*/
	return 0;
}