#include "TadCadena.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void leecad(Tcad vec,int tam){
	int j=0; //j=0 Se comeinsa la lectura de carracteres del buffer
	char c;
	c=getchar();
	while (j<tam-1 && c!=EOF && c!='\n'){
		vec[j]=c;
		j++;
		c=getchar();
	}
	vec[j]='\0';
	while (c!=EOF && c!='\n') // Se vacia de caracteres el buffer
		c=getchar();
}

int comparaCad(Tcad a,Tcad b){
	return strcmp(a,b);
}
