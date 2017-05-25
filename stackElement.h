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
		Funcion(const char* n, int etiqueta, int p);
		int getPila();

	private:
		char name[20];
		int pila;
		int etiqueta;
};

