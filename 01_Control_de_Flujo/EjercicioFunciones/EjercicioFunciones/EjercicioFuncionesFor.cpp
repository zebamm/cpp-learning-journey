#include <iostream>

void imprimirTabla(int num) {
	for (int i = 1; i <= 10; i++) {
		std::cout << "\n" << num << " x " << i << " = " << num * i;
	}
}

int main() {
	int num;

	std::cout << "Ingrese un numero mayor a 0: ";
	std::cin >> num;

	while (num <= 0) {
		std::cout << "\nError! Ingrese un numero valido: ";
		std::cin >> num;
	}

	std::cout << "\nGracias! La tabla de multiplicacion de " << num << " hasta el 10 es:";
	imprimirTabla(num);
	return 0;
}