#include <iostream>

int main() {
	int num;

	std::cout << "Ingrese un numero mayor a cero: ";
	std::cin >> num;

	while (num <= 0) {
		std::cout << "\nError! Vuelva a intentarlo: ";
		std::cin >> num;
	}

	std::cout << "\nGracias! La tabla de multiplicacion de " << num << " del 1 al 10 es: ";

	for (int i = 1; i < 11; i++) {
		std::cout << "\n" << num << " x " << i << " = " << num * i;
	}
	return 0;
}