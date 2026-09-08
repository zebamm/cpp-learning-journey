#include <iostream>

/* El objetivo de este desafío es implementar una lista doblemente enlazada, es decir, que el sistema
debe permitir la navegación bidireccional y mantener la integridad de dos punteros por cada nodo en
operaciones de inserción y recorrido */

struct Nodo {
private:
	int id;
	Nodo* anterior; // Puntero hacía el nodo anterior
	Nodo* siguiente;

	friend class Lista;
public:
	Nodo(int nuevoID) {
		id = nuevoID;
		anterior = nullptr;
		siguiente = nullptr;
	}

	~Nodo() {
		std::cout << "Nodo de ID: " << id << " eliminado\n";
	}
};

class Lista {
private:
	Nodo* cabeza;
	Nodo* cola;
public:
	Lista() {
		cabeza = nullptr;
		cola = nullptr;
	}

	void insertarFinal(int nuevoID) {
		Nodo* nuevoNodo = new Nodo(nuevoID);

		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
			cola = nuevoNodo;
			return;
		}

		cola->siguiente = nuevoNodo;
		nuevoNodo->anterior = cola; // Declaramos el puntero anterior del nuevo nodo como la cola ya que este esta en el nodo anterior
		cola = nuevoNodo; // Declaramos el nuevo final de lista
	}

	void insertarMedio(int nuevoID, int idAnterior) {
		if (cabeza == nullptr) {
			std::cout << "ERROR! Lista vacía. Inserte un elemento en la lista antes!\n";
			return;
		}
		
		Nodo* explorador = cabeza;
		while (explorador != nullptr && explorador->id != idAnterior) {
			explorador = explorador->siguiente;
		}
		if (explorador == nullptr) {
			std::cout << "Nodo ID no encontrado\n";
			return;
		}

		Nodo* nuevoNodo = new Nodo(nuevoID);
		nuevoNodo->siguiente = explorador->siguiente; // Asignamos al nuevo nodo el puntero siguiente del nodo anterior
		explorador->siguiente = nuevoNodo; // Cambiamos el puntero de siguiente del nodo anterior hacía el nuevo nodo
		nuevoNodo->anterior = explorador; // Asignamos el anterior del nuevo nodo al nodo anterior
		/* Caso limite : en caso de que se este inserte al final de la lista, asignamos la nueva cola como el nuevo nodo y
		cerramos la ejecucion para evitar que se intente acceder a memoria externa */
		if (cola == explorador) {
			cola = nuevoNodo;
			return;
		}
		nuevoNodo->siguiente->anterior = nuevoNodo; // Finalmente asignamos el puntero anterior del nodo siguiente al nuevo nodo
	}

	void eliminarMedio(int idEliminar) {
		if (cabeza == nullptr) {
			std::cout << "ERROR! Lista vacía. Inserte un elemento en la lista antes!\n";
			return;
		}

		Nodo* explorador = cabeza;
		while (explorador != nullptr && explorador->id != idEliminar) {
			explorador = explorador->siguiente;
		}
		if (explorador == nullptr) {
			std::cout << "Nodo ID no encontrado";
			return;
		}
		
		/* Caso Limite: en caso de que se este eliminando la cabeza asignamos a la nueva cabeza como el nodo siguiente
		y cerramos la ejecución para evitar que se intente acceder a memoria externa */
		if (cabeza == explorador) {
			cabeza = explorador->siguiente;
			/* Caso limite: en caso de que haya un solo elemento en la lista, asignamos tanto la cabeza como la
			cola como nullptr */
			if (cola == explorador) {
				cola = explorador->siguiente;
			}else {
				cabeza->anterior = nullptr;
			}
			delete explorador;
			return;
		}
		explorador->anterior->siguiente = explorador->siguiente; // Hacemos un puente entre el nodo anterior y el siguiente
		/* Caso limite: en caso de que se este eliminando la cola asignamos la nueva cola como el nodo anterior y
		cerramos la ejecucion para evitar que se intente acceder a memoria externa */
		if (explorador == cola) {
			cola = explorador->anterior;
			delete explorador;
			return;
		}
		explorador->siguiente->anterior = explorador->anterior; // Si no es la cola, hacemos el puente entre el nodo siguiente y el anterior
		delete explorador;
	}

	void imprimirListaAsc() {
		if (cabeza == nullptr) {
			std::cout << "ERROR! Lista vacía. Inserte un elemento en la lista antes!\n";
			return;
		}
		Nodo* explorador = cabeza;
		while (explorador != nullptr) {
			std::cout << "Nodo ID: " << explorador->id << "\n\n";
			explorador = explorador->siguiente;
		}
	}
	void imprimirListaDesc() {
		if (cabeza == nullptr) {
			std::cout << "ERROR! Lista vacía. Inserte un elemento en la lista antes!\n";
			return;
		}
		Nodo* explorador = cola;
		while (explorador != nullptr) {
			std::cout << "Nodo ID: " << explorador->id << "\n\n";
			explorador = explorador->anterior;
		}
	}

	~Lista() {
		Nodo* explorador = cabeza;
		while (explorador != nullptr){
			Nodo* siguiente = explorador->siguiente;
			std::cout << "Eliminando Nodo de ID: " << explorador->id << "\n";
			delete explorador;
			explorador = siguiente;
		}
	}
};

int main() {
	int seleccion, idEliminar, idAnterior;
	int id = 0;
	Lista ListaEnlazada;

	std::cout << "Bienvenido al gestor de nodo de la lista enlazada\n";
	do{
		std::cout << "Que desea hacer?\n";
		std::cout << "1. Insertar nodo\n2. Insertar nono en medio de la lista\n3. Visualizar lista\n4. Eliminar un nodo en particular\n\n0. Salir\n\n";
		std::cin >> seleccion;
		switch (seleccion){
		case 1:
			ListaEnlazada.insertarFinal(id);
			id++;
			break;
		case 2:
			std::cout << "Después de que nodo ID desea insertar el nuevo nodo?";
			std::cin >> idAnterior;
			ListaEnlazada.insertarMedio(id, idAnterior);
			id++;
			break;
		case 3:
			do{
				std::cout << "En que orden desea visualizar la lista?\n";
				std::cout << "1. Ascendente\n2. Descendente\n\n";
				std::cin >> seleccion;
				switch (seleccion) {
				case 1:
					ListaEnlazada.imprimirListaAsc();
					break;
				case 2:
					ListaEnlazada.imprimirListaDesc();
					break;
				default:
					std::cout << "Inserte una opcion valida por favor\n";
					break;
				}
			} while (seleccion != 1 && seleccion != 2);
			break;
		case 4:
			std::cout << "Que Nodo ID desea eliminar?\n";
			std::cin >> idEliminar;
			ListaEnlazada.eliminarMedio(idEliminar);
			break;
		case 0:
			std::cout << "Saliendo del sistema...\n";
			break;
		default:
			std::cout << "Inserte un valor valido por favor\n";
			break;
		}
	} while (seleccion != 0);

	return 0;
}