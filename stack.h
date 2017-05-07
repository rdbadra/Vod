#include <vector> 

class Stack {

	public:
		void addStackElement(const char *name, const char *type);
		StackElement getStackElement(const char *name);
		int size(void);
		void printStack(void);
		bool exists(const char *name);
		void goToGlobal();
		void goToLocal();
		void addEntValue(int x, const char *name);
		int getEntValue(const char *name);

	private:
		std::vector<StackElement> stack;
		std::vector<EntValue> entStack;

};


