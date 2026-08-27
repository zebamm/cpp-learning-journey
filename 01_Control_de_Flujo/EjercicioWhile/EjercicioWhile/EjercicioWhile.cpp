#include <iostream>

int main() {
	int num;

	std::cout << "Ingrese un numero mayor a cero: ";
	std::cin >> num;

	while (num <= 0) {
		std::cout << std::endl << "Numero no valido, intentelo de nuevo: ";
		std::cin >> num;
	}
	
	std::cout << std::endl << "Gracias! Ingresaste el numero: " << num << std::endl;
	return 0;
}