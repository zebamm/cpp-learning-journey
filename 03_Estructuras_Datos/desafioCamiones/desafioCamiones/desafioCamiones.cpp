#include <iostream>

struct Camion {
	int id;
	int capacidad = 0;
	char estado = 'D';
};

void almacenarCamiones(int tamFlota, Camion* flota) {
	for (int i = 0; i < tamFlota; i++) {
		flota[i].id = i;
		std::cout << "Que capacidad tiene el camion " << i + 1 << "?\n";
		do {
			std::cin >> flota[i].capacidad;
		} while (flota[i].capacidad < 0);
		std::cout << "En que estado esta el camion ahora mismo? ('D' para disponible, 'E' por si esta en ruta)\n";
		do {
			std::cin >> flota[i].estado;
		} while (flota[i].estado != 'D' && flota[i].estado != 'E');
	}
}

int asignarViaje(int tamFlota, int nuevoCarg, Camion* flota) {
	for (int i = 0; i < tamFlota; i++) {
		if (flota[i].estado == 'D' && flota[i].capacidad >= nuevoCarg) {
			flota[i].estado = 'E';
			return flota[i].id;
		}
	}
	return -1;
}

int main() {
	int tamFlota;
	int nuevoCarg;

	std::cout << "Cuantos camiones hay disponibles hoy?" << std::endl;
	std::cin >> tamFlota;
	if (tamFlota <= 0) {
		std::cout << "Entoces no hay nada que hacer!";
		return 0;
	}
	Camion* flota = new Camion[tamFlota];

	almacenarCamiones(tamFlota, flota);

	std::cout << "Que peso tiene el cargamento que se debe enviar hoy?" << std::endl;
	std::cin >> nuevoCarg;

	int viaje = asignarViaje(tamFlota, nuevoCarg, flota);
	if (viaje >= 0) {
		std::cout << "El viaje se ha asignado al camion de id:" << viaje;
	}
	else{
		std::cout << "No hay ningun camion que cumpla con los requisitos para el viaje!";
	}
	delete[] flota;

	return 0;
}