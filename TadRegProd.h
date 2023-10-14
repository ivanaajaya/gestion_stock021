#include "TadCadena.h"

typedef struct{
	Tcad Rub,Descr;
	long Cod;
	float precio;
	int Cant,stockMIN;
}T_Producto;

T_Producto Cargar_Registro(long);
void Mostrar_Registro(T_Producto);
void Modif(T_Producto *prod);
long RetornaCod(T_Producto);
int comparaRub(T_Producto,Tcad);
int RetornaCant(T_Producto);
int retornastockMIN(T_Producto);
float retornaprecio(T_Producto);
float calcula_precioTo(T_Producto aux,int cant);
void actualizaStock(T_Producto *lis,int cant);
void RetornaRub(T_Producto,Tcad);
