#include <iostream>

/* El objetivo de este desafío es consolidar la creación de arreglos dinámicos de objetos, 
el uso de sobrecarga de constructores y observar el ciclo de vida  de los objetos mediante
la implementación de destructores. */

class Impresion{
private:
    int id;
    int peso;
    char estado; //'E' para Espera, 'I' para Imprimiendo, 'F' para Finalizado
public:
    // Flags para detectar objetos no iniciados correctamente
    Impresion(){
        id = -1;
        peso = 0;
        estado = 'N';
    }
    Impresion(int nuevoID, int nuevoPeso){
        id = nuevoID;
        peso = nuevoPeso;
        estado = 'E'; // Al iniciar un objeto correctamente el estado se inicia como 'E'
    }

    void cambiarEstado(char nuevoEstado){
        estado = nuevoEstado;
    }

    int getID(){
        return id;
    }

    int getPeso(){
        return peso;
    }

    char getEstado(){
        return estado;
    }

    //Destructor, su unica función en este caso es reportar que objeto fue eliminado
    ~Impresion(){
        std::cout << "El archivo de id " << id << " fue eliminado\n";
    }
};

void almacenarImpresiones(int numImpr, Impresion* listaImpr){
    int id, peso;
    for(int i = 0; i < numImpr; i++){
        id = i;
        std::cout << "Cuanto pesa el archivo de pedido " << i + 1 << "?(En kb)\n";
        do{
            std::cin >> peso;
        }while(peso <= 0);
        listaImpr[i] = Impresion(id, peso);
    }
}

void imprimirLista(int numImpr, Impresion* listaImpr){
    for(int i = 0; i < numImpr; i++){
        std::cout << "Pedido de impresion " << i + 1 << "\nID: " << listaImpr[i].getID() << "\nPeso: " << listaImpr[i].getPeso() << "\nEstado: " << listaImpr[i].getEstado() << "\n\n";
    }
}

int main(){
    int seleccion, numImpr, id;
    char nuevoEstado;
    bool listaCreada = false;
    Impresion* listaImpr = nullptr;

    std::cout << "Bienvenido al gestor de archivos de impresión" << std::endl;
    do{
        std::cout << "Que desea hacer hoy?\n";
        std::cout << "1. Ingresar un nuevo lote de impresiones\n2. Ver estado del lote\n3. Cambiar estado de un pedido\n0. Salir\n";
        std::cin >> seleccion;
        switch (seleccion)
        {
        case 1:
            if(listaCreada){
                delete[] listaImpr;
            }
            std::cout << "De cuantos pedidos es el lote?\n";
            std::cin >> numImpr;
            listaImpr = new Impresion[numImpr];
            almacenarImpresiones(numImpr, listaImpr);
            listaCreada = true;
            break;
        case 2:
            if(listaCreada){
                imprimirLista(numImpr, listaImpr);
                break;
            }
            std::cout << "No hay ningún lote ingresado!\n";
            break;
        case 3:
            if(listaCreada){
                std::cout << "Que pedido quiere cambiar su estado? (ID)\n";
                std::cin >> id;
                std::cout << "En que estado esta el pedido ahora?('E' para Espera, 'I' para Imprimiendo, 'F' para Finalizado)\n";
                do
                {
                    std::cin >> nuevoEstado;
                } while (nuevoEstado != 'E' && nuevoEstado != 'I' && nuevoEstado != 'F');
                
                listaImpr[id].cambiarEstado(nuevoEstado);
                break;
            }
            std::cout << "No hay ningun lote ingresado!\n";
            break;
        case 0:
            std::cout << "Saliendo del sistema...";
            break;
        
        default:
            std::cout << "Por favor ingrese una opción valida\n\n";
            break;
        }
    } while (seleccion != 0);

    delete[] listaImpr;
    return 0;    
}