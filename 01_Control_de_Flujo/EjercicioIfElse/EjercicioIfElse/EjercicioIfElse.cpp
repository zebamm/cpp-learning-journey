#include <iostream>	

int main() {
	int num;
	std::cout << "Par o Impar?" << std::endl << "Ingrese el numero que desea saber si es par o impar: ";
	std::cin >> num;
	if (num % 2 == 0) {
		std::cout << std::endl << "El numero ingresado, " << num << ", es par";
		return 0;
	}
	std::cout << std::endl << "El numero ingresado, " << num << ", es impar";
	return 0;
}