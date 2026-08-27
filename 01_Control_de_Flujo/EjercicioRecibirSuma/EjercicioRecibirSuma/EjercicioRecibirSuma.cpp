#include <iostream>

int main() {
	int num1, num2;

	std::cout << "Ingrese el primer numero para luego multiplicar por otro" << std::endl;
	std::cin >> num1;
	std::cout << "Ahora ingrese el segundo numero" << std::endl;
	std::cin >> num2;
	std::cout << "El resultado de multiplicar " << num1 << " por " << num2 << " es " << num1 * num2 << std::endl;

	return 0;
}