class Variable {
	public:
		char* getName();
		char* getTipo();
		char* getContext();
		int getDireccion();
		int getSize();
		int getAmbito();
		Variable(const char* n, const char* t, const char* c, int amb, int d, int s);

	private:
		char name[20];
		char tipo[10];
		char context[20];
		int ambito;
		int direccion;
		int size;
};

class Funcion {
  	public:
		char* getName(void);
		int getEtiqueta();
		int getEspacioParaLasVariables();
		void setEspacioParaLasVariables(int espacio);
		Funcion(const char* n, int etiqueta);

	private:
		char name[20];
		int etiqueta;
		int espacioParaLasVariables;
};

