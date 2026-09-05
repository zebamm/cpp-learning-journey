#include <iostream>

/* El objetivo de este desafio es lograr aprender como se elimina un nodo individual que se encuentra en medio
de una lista enlazada y que mantener la lista estable */

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

	~Nodo() {
		std::cout << "Nodo de ID: " << id << " eliminado\n";
	}
};

class Lista {
private:
	Nodo* cabeza;
public:
	Lista() {
		cabeza = nullptr;
	}

	void agregarNodo(int nuevoID) {
		Nodo* nuevoNodo = new Nodo(nuevoID);

		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
		} else {
			Nodo* explorador = cabeza;

			while (explorador->siguiente != nullptr) {
				explorador = explorador->siguiente;
			}

			explorador->siguiente = nuevoNodo;
		}
	}

	// Funcion dedicada para la eliminacion de un nodo en particular
	/* La idea es guardar la direccion del nodo anterior y del siguiente nodo al que eliminamos para poder 
	conectarlos despues que se elimine el nodo y se mantenga enlazada la lista */
	void eliminarNodo(int idEliminar) {
		Nodo* actual = cabeza;

		if (actual != nullptr) {
			if (actual->id == idEliminar) {
				// En caso de que se elimine la cabeza, asignamos la nueva cabeza antes de eliminar
				cabeza = actual->siguiente;
				delete actual;
			} else {
				Nodo* anterior = actual;
				while (actual != nullptr && actual->id != idEliminar) {
					anterior = actual;
					actual = actual->siguiente;
				}
				if (actual == nullptr) {
					std::cout << "No existe un nodo con ese ID!\n";
				} else {
					anterior->siguiente = actual->siguiente;
					delete actual;
				}
			}
		} else {
			std::cout << "ERROR! Inserte un elemento en la lista antes!\n";
		}
	}

	void imprimirLista() {
		Nodo* explorador = cabeza;

		if (explorador != nullptr) {
			while (explorador != nullptr) {
				std::cout << "Nodo ID: " << explorador->id << "\n\n";
				explorador = explorador->siguiente;
			}
		} else {
			std::cout << "ERROR! Inserte un elemento en la lista antes!\n";
		}
	}
	~Lista() {
		Nodo* actual = cabeza;
		while (actual != nullptr) {
			std::cout << "Eliminando nodo de ID:" << actual->id << "\n";
			Nodo* siguiente = actual->siguiente;
			delete actual;
			actual = siguiente;
		}
	}
};

int main() {
	int seleccion, idEliminar;
	int id = 0;
	Lista listaNodos;

	std::cout << "Bienvenido al gestor de nodos de la lista enlazada\n";
	do{
		std::cout << "Que desea hacer?\n";
		std::cout << "1. Ingresar nodo en la lista\n2. Visualizar lista\n3. Eliminar un nodo individual\n\n0. Salir\n\n";
		std::cin >> seleccion;
		switch (seleccion){
		case 1:
			std::cout << "Insertando nuevo nodo...\n";
			listaNodos.agregarNodo(id);
			id++;
			break;
		case 2:
			listaNodos.imprimirLista();
			break;
		case 3:
			std::cout << "Que ID de nodo desea eliminar?\n";
			std::cin >> idEliminar;
			listaNodos.eliminarNodo(idEliminar);
			break;
		case 0:
			std::cout << "Saliendo del sistema...\n";
			break;
		default:
			std::cout << "Inserte una opcion valida\n";
			break;
		}
	} while (seleccion != 0);

	return 0;
}