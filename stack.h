#include <vector> 

class Stack {

	public:
		void addStackElement(const char *name, const char *type, int direc);
		StackElement getStackElement(const char *name);
		int size(void);
		void printStack(void);
		bool exists(const char *name);
		void addEntValue(int x, const char *name);
		int getEntValue(const char *name);
		void addCadValue(const char *name, const char *value);
		char* getCadValue(const char *name);

	private:
		std::vector<StackElement> stack;
		std::vector<EntValue> entStack;
		std::vector<CadValue> cadStack;

};


