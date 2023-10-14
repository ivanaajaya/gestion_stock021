#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TadLisRegProd.h"
short menu();

int main() {
	T_Lista Lis;
	Tcad rubro;
	int op;

	Lis=InicializarLista();
	CargaLista(&Lis);
	
	do{
		system("CLS"); //Borra la pantalla
		op=menu();
		switch (op){
		case 1: 
			CargaLista(&Lis);
			break;
		case 2:
			fflush(stdin);
			printf("Ingrese un rubro para modificar los precios:");
			leecad(rubro,TamMax);
			strupr(rubro);
			ModificaPrecio(&Lis,rubro);
			break;
		case 3: 
			EliminaReg(&Lis);
			break;
		case 4:
			Mostrarstock_min(Lis);//Mostrar_Lis(Lis);//Mostrarstock_min(Lis,N);
			break;
		case 5:
			ventas(&Lis);//ventas(Lis,N);
			break;
		case 6:
			Mostrar_LisRub(Lis);//Mostrar_Lis(Lis);
			break;
		};
		system("PAUSE");//Pausa la ejecución del programa.
	}while (op!=0);
	//Mostrar_Agrupados_Rubro(Lis,N);
	//Mostrar_Lis(Lis);
	return 0;
}

short menu(){
	
	short op;
	printf("1- Alta(Agregar un nuevo Producto)\n");
	printf("2- Modificar precio\n");
	printf("3- Dar de baja(Eliminar)\n");
	printf("4- Mostrar los productos que estan por debajo del stock minimo\n");
	printf("5- VENTAS: Total a pagar\n");
	printf("6- Mustra los produtos agrupados por rubro\n");
	printf("0- SALIR\n");
	do{
		printf ("Seleccione una opción:");
		scanf("%hd",&op);
	}while(op<0||op>6);
	
	return op;
}
