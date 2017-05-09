//hay que crear el interfaz
//#include "GestorDeMemoria.h"
#include <stdio.h>  
#include <math.h>
#include <string.h>
#include <iostream>
#include "GestorDeMemoria.h"
#include <sstream>   

using namespace std;

/*map<yytokentype, char> letra = {
	{INT, 'I'},
	{CHAR, 'U'},
	{TUPLE, 'I'}
};

map<yytokentye, int> tamano = {
	{INT, 4},
	{CHAR, 1},
	{TUPLE, 4}
};

map<int, char *> regNombres = {
	{RO, "RO"},
	{R1, "R1"},
	{R2, "R2"},
	{R3, "R3"},
	{R4, "R4"},
	{R5, "R5"},
	{R6, "R6"},
	{R7, "R7"}
};*/

char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int contenidoRegistros[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
//int tamanoDireccion = 7;
//const char* basePila = "0x13000";
//const char* stackCounter = basePila;

//metodos utiles


//vuelve el id de un registro libre
const char* direccionDeMemoria = "12000";

int hexToDec(const char* hex){
	std::stringstream ss;
	int decimal_value;
	ss  << hex ; // std::string hex_value
	ss >> std::hex >> decimal_value ; //int decimal_value
	return decimal_value;
}

char* decToHex(int decimal_value){

	std::stringstream ss;
	ss<< std::hex << decimal_value; // int decimal_value
	std::string res ( ss.str() );
	char * writable = new char[res.size() + 1];
	std::copy(res.begin(), res.end(), writable);
	writable[res.size()] = '\0'; 
	return writable;
}

char* GestorDeMemoria::cogerDireccionDeMemoria(){
	int actual = hexToDec(direccionDeMemoria);
	actual = actual - 1;
	return decToHex(actual);

}

int GestorDeMemoria::devuelveRegistroLibre(){
	for (int i = 0; i< 8;i++){
		if (estaLibre(i)){
			contenidoRegistros[i] = 1;
			return i;
		}
	}

	printf("ERROR: NO QUEDA NINGUN REGISTRO LIBRE\n");
}


//verifica si el registro está libre
bool GestorDeMemoria::estaLibre(int id){
	if (contenidoRegistros[id]==-1){
		return true;
	}

	return false;
}

//libera el registro numero *id
void GestorDeMemoria::liberaRegistro(int id){
	contenidoRegistros[id]=-1;
}

/*int convertHexadecimalADecimal(const char* hexa){
	
	char numero[6];
	int numeroDecimal=0;
	int potencia = 0;
	int i;
	
	for (i = 2; i<strlen(hexa); i++){
		numero[i-2]=hexa[i];
	}
	numero[i-2]='\0';

	for(i=strlen(numero); i >= 0; i--) {		

		for(int j=0; j<16; j++){
		    if(numero[i] == hexDigits[j]){
		        numeroDecimal = numeroDecimal + (j)*pow(16, potencia);
		    }
		}
		if(i!=(strlen(numero)))potencia++;
    	}  
	
	return numeroDecimal;	
}*/



/*char* convertDecimalToHexadecimal(int decimal){
	char esadecimal[8];
	esadecimal[0]='0';
	esadecimal[1]='x';
	esadecimal[7] = '\0';

	int cociente = decimal;
	int temp;
	int i =0;
	char numeroEsadecimal[5];

	while(cociente!=0){
	       	temp = cociente % 16;

		//To convert integer into character
	      	if(temp < 10)
			 temp =temp + 48;
	      	else
			 temp = temp + 55;

		numeroEsadecimal[i]= temp;
		i++;
		cociente = cociente / 16;
	}

	for (i=0; i<5;i++){
		esadecimal[i+2]=numeroEsadecimal[4-i];
	}

	return esadecimal;
}*/

/*void insertaNumero(int numero){
	int direccion = convertEsadecimalADecimal(stackCounter);
	direccion = direccion +4;
	char* direccionHexadecimal = convertDecimalToHexadecimal(direccion);

	//escribir el numero en la estructura de memoria
}

void insertaTupla(char* cadena){
	int tamano = strlen(cadena);

	int direccion = convertEsadecimalADecimal(stackCounter);
	direccion = direccion + tamano*1;
	char* direccionHexadecimal = convertDecimalToHexadecimal(direccion);

	//escribir la cadena en la estructura de memoria
}*/
