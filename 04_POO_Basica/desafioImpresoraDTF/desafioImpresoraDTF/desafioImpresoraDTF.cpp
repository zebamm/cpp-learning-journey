#include <iostream>

class Impresora {
private:
	int tinta = 100;
public:
	int calcularTinta(int cantidad) {
		int resto = tinta - cantidad * 5;
		return resto;
	}
	void imprimir(int cantidad) {
		if (calcularTinta(cantidad) >= 0) {
			tinta = tinta - cantidad * 5;
			std::cout << "Se imprimieron exitosamente " << cantidad << " stickers!" << std::endl;
		} else{
			std::cout << "No hay suficiente tinta para trabajar!" << std::endl;
		}
	}
	void mantenimiento() {
		tinta = 100;
		std::cout << "Se recargo la tinta al maximo" << std::endl;
	}
	int obtenerTinta() {
		return tinta;
	}
};

int main() {
	Impresora DTFUV1;
	int decision;

	do
	{
		std::cout << "Bienvenido a la interfaz de manejo de impresoras\n";
		std::cout << "Seleccione que le gustaria hacer:\n";
		std::cout << "1. Imprimir stickers\n2. Verificar tinta\n3. Cargar Tinta\n0. Salir\n";
		std::cin >> decision;

		switch (decision){
		case 1:
			int cantidad;
			std::cout << "Cuantos stickers desea imprimir?\n";
			std::cin >> cantidad;
			DTFUV1.imprimir(cantidad);
			break;
		case 2:
			std::cout << "La a la impresora le queda un " << DTFUV1.obtenerTinta() << "% de tinta.\n";
			break;
		case 3:
			DTFUV1.mantenimiento();
			break;
		case 0:
			std::cout << "Apagando el sistema...";
			break;
		default:
			std::cout << "Por favor ingrese una opcion valida\n";
			break;
		}
	} while (decision != 0);

	return 0;
}