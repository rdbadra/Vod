//hay que crear el interfaz
//#include "GestorDeMemoria.h"
#include <stdio.h>  
#include <math.h>
#include <string.h>
#include <iostream>
#include "GestorDeMemoria.h"
#include <sstream>   

using namespace std;

char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int contenidoRegistros[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int memory = 0x12000;
int stat = 0;
int code = 0;

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

int GestorDeMemoria::getStat(){
	int res = stat;
	stat++;
	return res;
}

int GestorDeMemoria::getCode(){
	int res = code;
	code++;
	return res;
}

int GestorDeMemoria::cogerDireccionDeMemoriaEnt(){
	memory = memory - 4;
	return memory;

}

int GestorDeMemoria::cogerDireccionDeMemoriaCad(){
	memory = memory - 20;
	return memory;

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

