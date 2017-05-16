class GestorDeMemoria {

	public:
		int devuelveRegistroLibre();
		void liberaRegistro(int id);
		bool estaLibre(int id);
		int cogerDireccionDeMemoriaEnt();
		int cogerDireccionDeMemoriaCad(int num);
		int getStat();
		int getCode();
		void incrementStat();
		void incrementCode();
};


