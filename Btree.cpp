#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
};


Nodo* crearNodo(int valor) {
    Nodo* nodo = new Nodo();
    nodo->valor = valor;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    } else if (valor <= raiz->valor) {
        raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
    } else {
        raiz->derecho = insertarNodo(raiz->derecho, valor);
    }
    return raiz;
}

bool buscarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    } else if (raiz->valor == valor) {
        return true;
    } else if (valor <= raiz->valor) {
        return buscarNodo(raiz->izquierdo, valor);
    } else {
        return buscarNodo(raiz->derecho, valor);
    }
}

int encontrarMaximo(Nodo* raiz) {
    if (raiz->derecho == NULL) {
        return raiz->valor;
    } else {
        return encontrarMaximo(raiz->derecho);
    }
}

Nodo* eliminarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    } else if (valor < raiz->valor) {
        raiz->izquierdo = eliminarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = eliminarNodo(raiz->derecho, valor);
    } else {
        if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
            delete raiz;
            raiz = NULL;
        }
        else if (raiz->izquierdo == NULL) {
            Nodo* temp = raiz;
            raiz = raiz->derecho;
            delete temp;
        } else if (raiz->derecho == NULL) {
            Nodo* temp = raiz;
            raiz = raiz->izquierdo;
            delete temp;
        }
        else {
            int maximoIzquierdo = encontrarMaximo(raiz->izquierdo);
            raiz->valor = maximoIzquierdo;
            raiz->izquierdo = eliminarNodo(raiz->izquierdo, maximoIzquierdo);
        }
    }
    return raiz;
}
void imprimirEnOrden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirEnOrden(raiz->izquierdo);
        cout << raiz->valor << " ";
        imprimirEnOrden(raiz->derecho);
    }
}

void imprimirPreOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << " ";
        imprimirPreOrden(raiz->izquierdo);
        imprimirPreOrden(raiz->derecho);
    }
}

void imprimirPostOrden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirPostOrden(raiz->izquierdo);
        imprimirPostOrden(raiz->derecho);
        cout << raiz->valor << " ";
    }
}

bool esArbolVacio(Nodo* raiz) {
    return (raiz == NULL);
}

void anularArbol(Nodo* &raiz) {
    if (raiz != NULL) {
        anularArbol(raiz->izquierdo);
        anularArbol(raiz->derecho);
        delete raiz;
        raiz = NULL;
    }
}

int main() {
    Nodo* raiz = NULL;

    int opcion;
    int valor;

    do {
        cout << "____Menu____" << endl;
        cout << "1. Insertar valor" << endl;
        cout << "2. Eliminar valor" << endl;
        cout << "3. Imprimir en orden" << endl;
        cout << "4. Imprimir en preorden" << endl;
        cout << "5. Imprimir en postorden" << endl;
        cout << "6. Buscar valor" << endl;
        cout << "7. Eliminar arbol" << endl;
        cout << "8. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "dame un valor ";
                cin >> valor;
                raiz = insertarNodo(raiz, valor);
                break;
            case 2:
                cout << "dame el valor que quieres eliminar: ";
                cin >> valor;
                raiz = eliminarNodo(raiz, valor);
                break;
            case 3:
                cout << "Imprimir en order: ";
                imprimirEnOrden(raiz);
                cout << endl;
                break;
            case 4:
                cout << "Imprimir en preOrder: ";
                imprimirPreOrden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "Imprimir en postOrder: ";
                imprimirPostOrden(raiz);
                cout << endl;
                break;

            case 6:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                if (buscarNodo(raiz, valor)) {
                    cout << "El valor está en el árbol." << endl;
                } else {
                    cout << "El valor no está en el árbol." << endl;
                }
                break;
            case 7:
                anularArbol(raiz);
                cout << "El árbol ha sido eliminado." << endl;
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }

        cout << endl;

    } while (opcion != 8);

    return 0;
}
