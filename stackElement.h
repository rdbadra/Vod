class EntValue {
	public:
		int getValue();
		char* getName();
		EntValue(int val, const char* n);
	private:
		int value;
		char name[20];
};

class StackElement {
  	public:
		char* getName(void);
		char* getType(void);
		StackElement(const char*, const char*);
		void addEntValue(int);
		void addCadValue(const char*);
		int getEntValue(void);
		char* getCadValue(void);

	private:
		char name[20];
		//func cad ent bool
		char type[20];
		char ambito[20];
		char direccion[10];
		int entValue;
		char cadValue[20];

};

