#include <iostream>

/* El objetivo de este desafio es diseñar e implementar una estructura de datos dinámica
personalizada (una Lista Enlazada) basada en nodos. El sistema debe permitir la inserción 
de elementos al final de la cadena, el recorrido secuencial para lectura, 
y la correcta liberación de la memoria fragmentada a través del destructor. */

struct Producto {
private:
    int id;
    int stock;
    Producto* siguiente;

    friend class Inventario;
public:
    Producto(int nuevoID, int nuevoStock){
        id = nuevoID;
        stock = nuevoStock;
        siguiente = nullptr;
    }
};

class Inventario {
private:
    Producto* cabeza;
public:
    Inventario(){
        cabeza = nullptr;
    }

    void insertarProducto(int nuevoID, int nuevoStock){
        Producto* nuevoProducto = new Producto(nuevoID, nuevoStock);

        if(cabeza == nullptr){
            cabeza = nuevoProducto;
        } else {
            Producto* explorador = cabeza;

            while(explorador->siguiente != nullptr){
                explorador = explorador->siguiente;
            }

            explorador->siguiente = nuevoProducto;
        }
    }

    void imprimirLista(){
        Producto* explorador = cabeza;
        if(explorador != nullptr){
            while(explorador != nullptr){
                std::cout << "Producto " << explorador->id + 1 << "\nID: " << explorador->id << "\nStock: " << explorador->stock << "\n\n";
                explorador = explorador->siguiente;
            }
        } else {
            std::cout << "Lista vacía! Ingresar productos antes!\n";
        }
    }

    ~Inventario(){
        Producto* actual = cabeza;

        while(actual != nullptr){
            std::cout << "Borrando producto " << actual->id + 1 << "...\n";
            Producto* siguienteProd = actual->siguiente;
            delete actual;
            actual = siguienteProd;
        }
    }
};

int main(){
    int seleccion, id = 0, stock;
    Inventario listaProd;

    std::cout << "Bienvenido a la interfaz de manejo de inventario\n";
    do{
        std::cout << "Que desea hacer hoy?\n";
        std::cout << "1. Ingresar un nuevo producto\n2. Visualizar el catálogo\n\n0. Salir\n";
        std::cin >> seleccion;

        switch (seleccion){
        case 1:
            std::cout << "Que stock tiene el nuevo producto?\n";
            do
            {
                std::cin >> stock;
            } while (stock <= 0);
            listaProd.insertarProducto(id, stock);
            id++;
            break;
        case 2:
            listaProd.imprimirLista();
            break;
        case 0:
            std::cout << "Saliendo del sistema...\n";
        default:
            break;
        }
    } while (seleccion != 0);
    
    return 0;
}