#include <iostream>

/* El objetivo de este desafio es realizar arreglos dinamicos con objetos y comprender el funcionamiento de
multiples constructores para la creacion de estos*/

class Orden {
private:
	int id;
	char tipo; // 'T' Tazas. 'R' Remeras. 'S' Stickers.
	char estado = 'R'; // 'R' Recibido. 'P' en Progreso. 'L' Listo.
public:
	// Contructor para inicializar bien los objetos del arreglo dinamico
	Orden() {
		id = -1;
		tipo = 'T';
	}
	// Contructor para rellenar los objetos reales
	Orden(int nuevoID, char nuevoTipo, char nuevoEstado) {
		id = nuevoID;
		tipo = nuevoTipo;
		estado = nuevoEstado;
	}

	int getID() {
		return id;
	}
	char getTipo() {
		return tipo;
	}
	char getEstado() {
		return estado;
	}
};

void almacenarPedidos(int numPedidos, Orden* listaPedidos) {
	int id;
	char tipo, estado;
	for (int i = 0; i < numPedidos; i++) {
		id = i;
		std::cout << "De que es el pedido " << i + 1 << "? ('T' Tazas. 'R' Remeras. 'S' Stickers.)\n";
		do
		{
			std::cin >> tipo;
		} while (tipo != 'T' && tipo != 'R' && tipo != 'S');
		std::cout << "En que estado del proceso esta? ('R' Recibido. 'P' en Progreso. 'L' Listo.)";
		std::cin >> estado;
		listaPedidos[i]= Orden(id, tipo, estado);
	}
}

void imprimirLista(int numPedidos, Orden* listaPedidos) {
	for (int i = 0; i < numPedidos; i++) {
		std::cout << "Pedido: " << i + 1 << "\nID: " << listaPedidos[i].getID() << "\nTipo de Pedido: " << listaPedidos[i].getTipo() << "\nEstado del Pedido: " << listaPedidos[i].getEstado() << "\n\n";
	}
}

int main() {
	int numPedidos, seleccion;
	bool listaCreada = false;
	Orden* listaPedidos = nullptr;

	std::cout << "Bienvenido al gestor de pedidos del taller!" << std::endl;
	do{
		std::cout << "Que desea hacer?\n";
		std::cout << "1. Ingresar pedidos\n2. Revisar pedidos\n0. Salir" << std::endl;
		std::cin >> seleccion;
		switch (seleccion){
		case 1:
			// Importante para borrar el espacio de memoria previamente reservado
			if(listaCreada){
				delete[] listaPedidos;
			}
			std::cout << "Cuantos pedidos van a entrar hoy?\n";
			do{
				std::cin >> numPedidos;
			} while (numPedidos < 0);
			listaPedidos = new Orden[numPedidos];
			almacenarPedidos(numPedidos, listaPedidos);
			listaCreada = true;
			break;
		case 2:
			if (listaCreada) {
				imprimirLista(numPedidos, listaPedidos);
				break;
			}
			std::cout << "No hay pedidos en el sistema!\n";
			break;
		case 0:
			std::cout << "Saliendo del sistema...";
			break;
		default:
			std::cout << "Ingrese una opcion valida\n";
			break;
		}
	} while (seleccion != 0);
	
	delete[] listaPedidos;
	return 0;
}