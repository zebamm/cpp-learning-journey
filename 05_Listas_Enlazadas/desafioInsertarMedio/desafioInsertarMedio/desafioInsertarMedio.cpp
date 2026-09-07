#include <iostream>

/* El objetivo de este desafio es lograr insertar un elemento en medio de una lista enlazada, manteniendo
el resto de la lista en el orden correcto */

struct Nodo {
private:
	int id;
	Nodo* siguiente;

	friend class Lista;
public:
	Nodo(int nuevoID) {
		id = nuevoID;
		siguiente = nullptr;
	}

	~Nodo(){
		std::cout << "Nodo de ID: " << id << " eliminado con exito\n";
	}
};

class Lista {
private:
	Nodo* cabeza;
public:
	Lista() {
		cabeza = nullptr;
	}
	void insertarFinal(int nuevoID) {
		Nodo* nuevoNodo = new Nodo(nuevoID);

		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
			return;
		}

		Nodo* explorador = cabeza;
		while (explorador->siguiente != nullptr) {
			explorador = explorador->siguiente;
		}
		explorador->siguiente = nuevoNodo;
	}

	// Función dedicada para insertar el nodo en el lugar en particular
	/* La idea es crear el nodo, encontrar el nodo anterior que debe apuntar al nuevo y también guardar al siguiente
	nodo de la lista, y así insertar el nuevo nodo de forma que el nodo anterior lo apunte al nuevo y el nuevo nodo
	apunte al siguiente de la lista*/
	void insertarMedio(int nuevoID, int idAnterior) {
		if (cabeza == nullptr) {
			std::cout << "Error! Lista vacia, inserte un elemento en la lista antes!\n";
			return;
		}

		Nodo* explorador = cabeza;
		Nodo* siguiente = explorador->siguiente;
		while (explorador != nullptr && explorador->id != idAnterior) {
			explorador = explorador->siguiente;
		}
		if (explorador == nullptr) {
			std::cout << "ID no encontrado\n";		delete nuevoNodo;
			return;
		}
		Nodo* nuevoNodo = new Nodo(nuevoID);
		siguiente = explorador->siguiente;
		explorador->siguiente = nuevoNodo;
		nuevoNodo->siguiente = siguiente;
		std::cout << "Nodo de ID " << nuevoID << " insertado con exito despues del Nodo ID: " << idAnterior << "\n";
	}

	void eliminarMedio(int idEliminar){
		if (cabeza == nullptr) {
			std::cout << "Error! Lista vacia, inserte un elemento en la lista antes\n";
			return;
		}

		Nodo* actual = cabeza;
		Nodo* anterior = actual;
		if (actual->id == idEliminar) {
			cabeza = actual->siguiente;
			delete actual;
			return;
		}

		while (actual != nullptr && actual->id != idEliminar) {
			anterior = actual;
			actual = actual->siguiente;
		}
		if (actual == nullptr) {
			std::cout << "ID no encontrado\n";
			return;
		}
		anterior->siguiente = actual->siguiente;
		delete actual;
		std::cout << "Nodo de ID " << idEliminar << " eliminado con exito\n";
	}

	void imprimirLista() {
		if (cabeza == nullptr) {
			std::cout << "Error! Lista vacia, insertar un elemento en la lista antes\n";
			return;
		}

		Nodo* explorador = cabeza;
		while (explorador != nullptr) {
			std::cout << "Nodo ID: " << explorador->id << "\n\n";
			explorador = explorador->siguiente;
		}
	}

	~Lista() {
		Nodo* explorador = cabeza;
		while (explorador != nullptr) {
			Nodo* siguiente = explorador->siguiente;
			std::cout << "Eliminando nodo de ID: " << explorador->id << "\n";
			delete explorador;
			explorador = siguiente;
		}
	}
};

int main() {
	int seleccion, idAnterior, idEliminar;
	int id = 0;
	Lista ListaEnlazada;

	std::cout << "Bienvenido al gestor de nodos de la lista enlazada\n";
	do{
		std::cout << "Que desea hacer?\n";
		std::cout << "1. Insertar nuevo nodo\n2. Insertar nodo en medio de la lista\n3. Visualizar lista\n4. Eliminar un nodo en particular\n\n0. Salir\n\n";
		std::cin >> seleccion;

		switch (seleccion){
		case 1:
			ListaEnlazada.insertarFinal(id);
			id++;
			break;
		case 2:
			std::cout << "Despues de que nodo ID quiere ingresar el nuevo nodo?\n";
			std::cin >> idAnterior;
			ListaEnlazada.insertarMedio(id, idAnterior);
			id++; // El id va a ir cambiando incluso si no hay elementos en la lista; 
			break;
		case 3:
			ListaEnlazada.imprimirLista();
			break;
		case 4:
			std::cout << "Que ID de nodo desea eliminar?\n";
			std::cin >> idEliminar;
			ListaEnlazada.eliminarMedio(idEliminar);
			break;
		case 0:
			std::cout << "Saliendo del sistema...\n";
			break;
		default:
			std::cout << "Ingrese una opción valida por favor\n";
			break;
		}
	} while (seleccion != 0);

	return 0;
}