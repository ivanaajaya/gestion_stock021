#include "TadLisRegProd.h"
#include <stdio.h>

T_Lista InicializarLista(){
	T_Lista aux;
	
	aux.tam=0;
	
	return aux;
}

int busbinCodigo_rec(Tvec vec,int ini,int fin,long bus){
	int m=(ini+fin)/2;
	
	if (ini>fin)
		return -1;
	else
		if(RetornaCod(vec[m])==bus)
			return m;
		else
			if (bus > RetornaCod(vec[m]))
				return busbinCodigo_rec(vec,m+1,fin,bus);
			else
				return busbinCodigo_rec(vec,ini,m-1,bus);
}
void Ordenar_Uno_Baraja_rec(Tvec vec,int j){
	
	if (RetornaCod(vec[0]) >= RetornaCod(vec[j]))
		vec[j+1]=vec[0];
	else{
		vec[j+1]=vec[j];
		Ordenar_Uno_Baraja_rec(vec,j-1);
	}	
}
void cargar_vec_rec(Tvec v, int *tam,int ops){
	short op;
	long Cod;
	int res;
	
	//printf("\n1->Para Agregar \n0->Para Salir: ");
	//scanf("%hd",&op);
	
	
	if (ops!=0){
		
		printf("\nIngrese Codigo:");
		scanf ("%ld",&Cod);
		*tam=*tam+1;
		res=busbinCodigo_rec(v,1,*tam,Cod);
		
		if(res==-1){
			
			fflush(stdin);
			v[0]=Cargar_Registro(Cod);
			Ordenar_Uno_Baraja_rec(v,*tam-1);
			printf("\n1->Para Agregar \n0->Para Salir: ");
			scanf("%hd",&op);
			cargar_vec_rec(v,tam,op);
		}
		else{
		    *tam=*tam-1;
			cargar_vec_rec(v,tam,op);
		}
	}
}
void CargaLista(T_Lista *lis){
	int op=1;
	cargar_vec_rec(lis->Lis,&lis->tam,op);
}
//MODIFICA PRECIO DE CADA PRODUCTO QUE PERTENESCAN AL MISMO RUBRO- REALISADO POR FACUNDO MAMANI SAENZ
int busrubro_rec(Tvec v,int n,Tcad rub){
	if(n==0) return -1; 
	else
		if(comparaRub(v[n],rub)==0) return n; 
		else return busrubro_rec(v,n-1,rub); 
}

void ModificaPrecRec(Tvec v,int n,Tcad rub){//MODIFICA PRECIO
	int pos;
	
	pos=busrubro_rec(v,n,rub);
	
	if(pos!=-1){
		printf("\nProducto a Modificar el precio\n");
		Mostrar_Registro(v[pos]);
		Modif(&v[pos]);
		n=pos;
		ModificaPrecRec(v,n-1,rub);
	}
	else
	   printf("\nSE TERMINO DE BUSCAR\n");
}
	
void ModificaPrecio(T_Lista *lis,Tcad rub){
	ModificaPrecRec(lis->Lis,lis->tam,rub);
}
//----MODULO ELIMINA----------------------------
void CorrimientoEliminaRec(Tvec vec,int tam,int pos){
	if (pos!=tam){
		vec[pos]=vec[pos+1];
		CorrimientoEliminaRec(vec,tam,pos+1);
	}
}
int bus_cant0(Tvec v,int n){
	if(n==0) return -1; 
	else
		if(RetornaCant(v[n])==0) return n; 
		else return bus_cant0(v,n-1); 
}
void ElminaRegRec(Tvec vec,int *n){
	int pos;
	pos=bus_cant0(vec,*n);
	if(*n!=0 && pos>0){
		CorrimientoEliminaRec(vec,*n,pos);
		(*n)--;
		ElminaRegRec(vec,n);
	}
}
void EliminaReg(T_Lista *lis){
	if(lis->tam!=0){
		ElminaRegRec(lis->Lis,&(lis->tam));
		printf("ELIMINACION EXSITOSA");
	}
	else
		printf("\nLISTA VACIA\n");
}
//------MODULO VENTAS----------------------
void totalventasrec(Tvec vec, int tam,float *total){//int *tam
	long cod;
	int pos,cant;
	printf("Ingrese codigo del producto: \t\t0-SALIR :  ");
	scanf("%ld",&cod);
	
	if(cod!=0){
		pos=busbinCodigo_rec(vec,1,tam,cod);//*tam
		
		if (pos!=-1){
			printf("\nEn stock hay: %d\n", RetornaCant(vec[pos]));
			printf("Ingrese cantidad: "); 
			scanf("%d", &cant);
			(*total)=(*total) + calcula_precioTo(vec[pos],cant);
			actualizaStock(&vec[pos],cant);
			
			totalventasrec(vec,tam,total);
		}
		else{ //el codigo no esta
			printf("Codigo incorecto");
			totalventasrec(vec,tam,total);
		}
	}
}

void ventas(T_Lista *vec){
	float total=0.0;
	totalventasrec(vec->Lis,vec->tam,&total);//&vec->tam
	printf("Total a pagar es %.2f",total);
}
//----------------------------------------
//----MOSTRAR PRODUCTOS QUE TENGAN ESTEN POR DEBAJO DEL STOCK MIN
void Mostrarstock_minrec(Tvec vec, int tam){
	
	if(tam!=0){
		Mostrarstock_minrec(vec,tam-1);
		if (retornastockMIN(vec[tam]) > RetornaCant(vec[tam]))
			Mostrar_Registro(vec[tam]);
	}
}

void Mostrarstock_min(T_Lista aux){
	printf("Productos que estan por debajo del stock minimo:");
	Mostrarstock_minrec(aux.Lis, aux.tam);
}
//---------ORDENA AGRUPDOS POR RUBRO---------------
void MostrarRec(Tvec v,int tam){
	if(tam!=0){
		MostrarRec(v,tam-1);
		Mostrar_Registro(v[tam]);
	}
}

void Ordenar_Alfabeticaente_qsort(Tvec a, int ini, int fin) { 
	int izq, der, med;
	Tcad nom1,nom2;
	T_Producto piv;
	
	if (ini<fin){ 
		piv = a[ini];
		izq = ini; 
		der = fin; 
		
		while(izq<der){
			RetornaRub(a[der],nom1);
			RetornaRub(piv,nom2);
			while(der>izq && (comparaCad(nom1,nom2))>0){ 
				der--;
				RetornaRub(a[der],nom1);
			}
			if(der>izq){ 
				a[izq]= a[der]; 
				izq++; 
			}	
			RetornaRub(a[izq],nom1);
			while(izq<der && (comparaCad(nom1,nom2))<0){ 
				izq++;
				RetornaRub(a[izq],nom1);
			} 
			if(izq<der){ 
				a[der]= a[izq]; 
				der--; 
			} 
		} 
		a[der]=piv;
		med = der;
		Ordenar_Alfabeticaente_qsort(a,ini, med-1); 
		Ordenar_Alfabeticaente_qsort(a, med+1, fin); 
	} /*fin de if (ini<fin)*/ 
} /*fin de quicksort */ 

void copia_lis(Tvec lis,int tam,T_Lista *nue){
	int i;
	for(i=1;i<=tam;i++){
		nue->tam=nue->tam+1;
		nue->Lis[nue->tam]=lis[i];
	}
}
	
void Mostrar_LisRub(T_Lista lis){
	T_Lista lisrub;
	lisrub=InicializarLista();
	
	copia_lis(lis.Lis,lis.tam,&lisrub);
	Ordenar_Alfabeticaente_qsort(lisrub.Lis,1,lisrub.tam);
	MostrarRec(lisrub.Lis,lisrub.tam);
}
