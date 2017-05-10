#include <vector> 

class Stack {

	public:
		void addVariable(const char *name, const char *type, const char* c, int direc);
		Variable getVariable(const char *name);
		void addFuncion(const char *name, int etiqueta);
		Funcion getFuncion(const char *name);

		int size(void);
		void printStack(void);
		bool existsVariable(const char *name);
		bool existsFuncion(const char *name);

	private:
		std::vector<Variable> variableStack;
		std::vector<Funcion> funcionStack;

};


