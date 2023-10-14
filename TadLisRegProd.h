#include "TadRegProd.h"

typedef T_Producto Tvec[TamMax];

typedef struct{
	Tvec Lis;
	int tam;
}T_Lista;

void ModificaPrecio(T_Lista*,Tcad);//
T_Lista InicializarLista();//
void CargaLista(T_Lista*);//
void EliminaReg(T_Lista*);//
void ventas(T_Lista *vec);//
void Mostrarstock_min(T_Lista);//
void Mostrar_LisRub(T_Lista);//
