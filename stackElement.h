class StackElement {
  	public:
		char* getName(void);
		char* getType(void);
		StackElement(const char *nombre, const char *tipo);

	private:
		char name[20];
		//func cad ent bool
		char type[20];
		char ambito[20];
		char direccion[10];
		int entValue;
		char cadValue[20];

};

