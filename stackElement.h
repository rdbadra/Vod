class EntValue {
	public:
		int getValue();
		char* getName();
		EntValue(int val, const char* n);
	private:
		int value;
		char name[20];
};

class CadValue {
	public:
		char* getValue();
		char* getName();
		CadValue(const char* a, const char* n);
	private:
		char value[20];
		char name[20];
};

class StackElement {
  	public:
		char* getName(void);
		char* getType(void);
		StackElement(const char*, const char*, int direc);
		int getAddress(void);

	private:
		char name[20];
		//func cad ent bool
		char type[20];
		char ambito[20];
		int direccion;


};

