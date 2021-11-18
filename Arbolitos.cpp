// crear - crear un nodo
// insertar - insertar nodo creado
// mostrar - nodo
// eliminar - nodo

// preOrden
// inOrden
// postOrden

// menu
// busqueda

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	
	Nodo *padre;
	Nodo *derecha;
	Nodo *izquierda;
};

Nodo *crear(int, Nodo *);
Nodo *busquedaNodo(Nodo *, int);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarNodo(Nodo *, int);
void eliminarNodo(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void menu();

int main(void){
	menu();
	return EXIT_SUCCESS;
}

void menu(){
	Nodo *raiz = NULL;
	int dato;
	
	bool bandera;
	short opc;
	
	do{
		printf("1 - Insertar.\n");
		printf("2 - Mostrar.\n");
		printf("3 - Buscar.\n");
		printf("4 - pre orden.\n");
		printf("5 - in orden.\n");
		printf("6 - post orden.\n");
		printf("7 - Eliminar.\n");
		printf("8 - Salir.\n\n");
		scanf("%hi", &opc);
		
		switch(opc){
			case 1:
				while(true){
					printf("Ingrese dato:\n");
					scanf("%i", &dato);
					
					if(!busquedaNodo(raiz, dato)){
						insertarNodo(raiz, dato, NULL);
						break;
					} else {
						printf("El dato ya existe.\n");
					}
				}
				break;
			case 2:
				if(!raiz){
					printf("Vacio.\n");
				} else {
					mostrarNodo(raiz, 0);
				}
				break;
			case 3:
				if(!raiz){
					printf("Vacio.\n");
				} else {
					printf("Ingrese dato buscar:\n");
					scanf("%i", &dato);
					
					if(busquedaNodo(raiz, dato)){
						printf("Encontrado.\n");
					} else {
						printf("NO encontrado.\n");
					}
				}
				break;
			case 4:
				preOrden(raiz);
				printf("\n");
				break;
			case 5:
				inOrden(raiz);
				printf("\n");
				break;
			case 6:
				postOrden(raiz);
				printf("\n");
				break;
			case 7:
				while(true){
					printf("Ingrese dato a eliminar:\n");
					scanf("%i", &dato);
					
					if(!busquedaNodo(raiz, dato)){
						printf("El dato no existe.\n");
					} else {
						eliminarNodo(raiz, dato);
						break;
					}
				}
				break;
		}
	}while(opc != 8);
}

void eliminarNodo(Nodo *raiz, int dato){
	Nodo *encontrado;
	Nodo *padre;
	Nodo *derecha;
	Nodo *izquierda;
	
	encontrado = busquedaNodo(raiz, dato);
	
	// Ultimo hijo - no padre
	if(!encontrado->derecha && !encontrado->izquierda){
		if(encontrado->padre->derecha == encontrado){
			encontrado->padre->derecha = NULL;
		} else {
			encontrado->padre->izquierda = NULL;
		}
		free(encontrado);
	} else{
		// padre de dos hijos
		if(encontrado->derecha && encontrado->izquierda){
			// Si es la raiz
			if(encontrado == raiz){
				Nodo *aux;
				Nodo *aux2;
				
				aux2 = encontrado->izquierda;
				aux = encontrado->derecha;
				
				while(aux->izquierda != NULL){
					aux = aux->izquierda;
				}
				
				aux->izquierda = aux2;
			} 
		} else {
			// Si tiene hijo a la der
			if(encontrado->derecha){
				if(encontrado->padre->derecha == encontrado){
					encontrado->padre->derecha == encontrado->derecha;
				} else {
					encontrado->padre->izquierda == encontrado->derecha;
				}
			} else {
				if(encontrado->padre->derecha == encontrado){
					encontrado->padre->derecha == encontrado->izquierda;
				} else {
					encontrado->padre->izquierda == encontrado->izquierda;
				}
			}
			free(encontrado);
		}
	}
}

void postOrden(Nodo *raiz){
	if(!raiz){
		return;
	} else {
		postOrden(raiz->izquierda);
		postOrden(raiz->derecha);
		printf("%i\t<< - >>\t", raiz->dato);
	}
}

void inOrden(Nodo *raiz){
	if(!raiz){
		return;
	} else {
		inOrden(raiz->izquierda);
		printf("%i\t<< - >>\t", raiz->dato);
		inOrden(raiz->derecha);
	}
}

void preOrden(Nodo *raiz){
	if(!raiz){
		return;
	} else {
		printf("%i\t<< - >>\t", raiz->dato);
		preOrden(raiz->izquierda);
		preOrden(raiz->derecha);
	}
}

void mostrarNodo(Nodo *raiz, int contador){
	if(!raiz){
		return;
	} else {
		mostrarNodo(raiz->derecha, contador + 1);
		
		for(int i = 0; i < contador; i++){
			printf("   ");
		}
		
		printf("%i\n", raiz->dato);
		mostrarNodo(raiz->izquierda, contador + 1);
	}
}

Nodo *crear(int dato, Nodo *padre){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = dato;
	nuevoNodo->padre = padre;
	nuevoNodo->derecha = NULL;
	nuevoNodo->izquierda = NULL;
	
	return nuevoNodo;
}

void insertarNodo(Nodo *&raiz, int dato, Nodo *padre){
	if(!raiz){
		raiz = crear(dato, padre);
	} else {
		if(dato < raiz->dato){
			insertarNodo(raiz->izquierda, dato, raiz);
		} else {
			insertarNodo(raiz->derecha, dato, raiz);
		}
	}
}

Nodo *busquedaNodo(Nodo *raiz, int dato){
	if(!raiz){
		return NULL;
	} else if(raiz->dato == dato){
		return raiz;
	} else if(dato < raiz->dato){
		return busquedaNodo(raiz->izquierda, dato);
	} else {
		return busquedaNodo(raiz->derecha, dato);
	}
}

