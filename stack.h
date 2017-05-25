#include <vector> 

class Stack {

	public:
		void addVariable(const char *name, const char *type, const char* c, int amb, int direc, int s);
		Variable getVariable(const char *name);
		Variable getVariableWithContext(const char *name, int context);
		void addFuncion(const char *name, int etiqueta, int pila);
		Funcion getFuncion(const char *name);

		int size(void);
		void printStack(void);
		bool existsVariable(const char *name);
		bool existsFuncion(const char *name);
		void cleanDinamicStack(int context);
		int getLastPosition();

		void setPila(int p, int eti, char *name);

	private:
		std::vector<Variable> variableStack;
		std::vector<Funcion> funcionStack;

};

extern int numlin;

