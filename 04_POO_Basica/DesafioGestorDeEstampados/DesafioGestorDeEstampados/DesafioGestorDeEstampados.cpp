/* En este desafío se busca diseñar un sistema de gestión de pedidos
para la producción de pedidos personalizados. El objetivo de este
ejercicio es aprender sobre los constructores de clase y su utilización */

#include <iostream>

class Pedido {
private:
    int idPedido;
    char tipoArticulo; // El tipo del pedido. 'T' para Tazas, 'R' para Remeras y 'S' para stickers
    char estado; // El estado actual del pedido. 'P' para Pendiente, 'L' para Listo
public:
    // Constructor de clase
    Pedido(int nuevoID, char nuevoTipo, char nuevoEstado){
        idPedido = nuevoID;
        tipoArticulo = nuevoTipo;
        estado = 'P';
    }

    // Función para cambiar el estado del objeto
    void CambiarEstado(char nuevoEstado){
        estado = nuevoEstado;
    }

    // El getter para mostrar el resúmen del objeto
    void mostrarObjeto(){
        std::cout << "ID: " << idPedido << "\nTipo de Articulo: " << tipoArticulo << "\nEstado: " << estado << std::endl;
    }
};

// El main es unicamente utilizado para crear los objetos con el constructor, cambiarlo
// y ver que visualicen los cambios
int main(){
    int ID;
    char tipo, estado;
    
    ID = 0;
    tipo = 'T'; //Taza
    Pedido nuevoPedido0(ID, tipo, estado);
    ID = 1;
    tipo = 'S'; //Stickers
    Pedido nuevoPedido1(ID, tipo, estado);

    nuevoPedido0.mostrarObjeto();
    nuevoPedido1.mostrarObjeto();

    nuevoPedido0.CambiarEstado('L'); // Cambiamos el estado a "L", Listo
    nuevoPedido1.CambiarEstado('L');

    nuevoPedido0.mostrarObjeto();
    nuevoPedido1.mostrarObjeto();

    return 0;
}

// Este fue un desafío útil unicamente para aprender del uso de constructores, pero hasta ver más sobre
// arrays dinámicos todavía no me siento cómodo con él