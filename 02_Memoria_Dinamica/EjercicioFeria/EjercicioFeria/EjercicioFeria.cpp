#include <iostream>

void almacenarProductos(int numProductos, int* numVentas) {
	for (int i = 0; i < numProductos; i++) {
		std::cout << "Cuanto vendiste del producto " << i + 1 << "?\n";
		std::cin >> numVentas[i];
	}
}

void imprimirTabla(int numProductos, int* numVentas) {
	for (int i = 0; i < numProductos; i++) {
		std::cout << "Producto " << i + 1 << "		" << numVentas[i] << "\n";
	}
}

int sumarProductos(int numProductos, int* numVentas) {
	int sumaTotal=0;
	for (int i = 0; i < numProductos; i++) {
		sumaTotal = sumaTotal + numVentas[i];
	}
	return sumaTotal;
}

int menorVendido(int numProductos, int* numVentas) {
	int numVendido = numVentas[0];
	int menosVendido = 1;
	for (int i = 0; i < numProductos; i++) {
		if (numVendido > numVentas[i]) {
			numVendido = numVentas[i];
			menosVendido = i+1;
		}
	}
	return menosVendido;
}

int masVendido(int numProductos, int* numVentas) {
	int numVendido = numVentas[0];
	int masVendido = 1;
	for (int i = 0; i < numProductos; i++) {
		if (numVendido < numVentas[i]) {
			numVendido = numVentas[i];
			masVendido = i+1;
		}
	}
	return masVendido;
}

int main() {
	int numProductos;

	std::cout << "Cuantos productos llevaste a la feria?" << std::endl;
	std::cin >> numProductos;
	if (numProductos <= 0) {
		std::cout << "Si vas de paseo no tengo nada que hacer!" << std::endl;
		return 0;
	}
	int* numVentas = new int[numProductos];

	almacenarProductos(numProductos, numVentas);
	std::cout << "\nTabla de productos vendidos" << std::endl;
	imprimirTabla(numProductos, numVentas);

	std::cout << "El numero total de productos vendidos fue: " << sumarProductos(numProductos, numVentas) << std::endl;
	std::cout << "El producto menos vendido fue " << menorVendido(numProductos, numVentas) << std::endl;
	std::cout << "El producto mas vendido fue " << masVendido(numProductos, numVentas) << std::endl;

	return 0;
}