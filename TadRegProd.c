#include "TadRegProd.h"
#include <stdio.h>
#include <string.h>
T_Producto Cargar_Registro(long cod){
	T_Producto aux;
	
	printf("Rubro: ");
	leecad(aux.Rub,TamMax);
	strupr(aux.Rub); //  -> Convierte las letras minusculas de cadena, en mayusculas.
	printf("Descripcion: ");
	leecad(aux.Descr,TamMax);
	strlwr(aux.Descr); // -> Convierte las letras mayusculas de cadena, en minusculas.
	
	aux.Cod=cod;
	
	printf("Precio: ");
	scanf("%f",&aux.precio);
	printf("Cantidad: ");
	scanf("%d",&aux.Cant);
	printf("StockMinimo: ");
	scanf("%d",&aux.stockMIN);
	
	
	return aux;
}

long RetornaCod(T_Producto p){
	return p.Cod;
}
int RetornaCant(T_Producto p){
	return p.Cant;
}
int comparaRub(T_Producto a,Tcad rub){
	int res;
	res=comparaCad(a.Rub,rub);
	return res;
}
void RetornaRub(T_Producto aux, Tcad cad){
	strcpy(cad, aux.Rub);
}
int retornastockMIN(T_Producto aux){
	return aux.stockMIN;
}
float retornaprecio(T_Producto aux){
	return aux.precio;
}
void Modif(T_Producto *prod){//AUMENTA O MENRMA UN PRECIO
	float porcen;
	
	do{
		printf("Ingrese porcentaje hasta 99: ");
		scanf("%f",&porcen);
	}while(porcen < -100 && porcen > 100);
	
	prod->precio=prod->precio+porcen/100*prod->precio;
}

float calcula_precioTo(T_Producto aux,int cant){
	float total=0.0;
	total=aux.precio * cant;
	return total;
}
void actualizaStock(T_Producto *lis,int cant){
	lis->Cant=lis->Cant-cant;
}
void Mostrar_Registro(T_Producto aux){
	
	printf("\nRubro: %s",aux.Rub);
	printf("\nDescripcion: %s",aux.Descr);
	printf("\nCodigo: %ld",aux.Cod);
	printf("\nPrecio: %.2f",aux.precio);
	printf("\nCantidad: %d",aux.Cant);
	printf("\nStockMin: %d\n",aux.stockMIN);
}
