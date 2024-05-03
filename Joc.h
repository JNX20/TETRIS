#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <iostream>

using namespace std;

class Joc
{
public:
	Joc() {}
	void print();
	void print(int fila, int columna, int filaOrigi, int columnaOrigi);
	void printf(int fila, int columna, int filaOrigi, int columnaOrigi, ofstream& fitxer);
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(const int& dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	void afageixFitxa();

	int getTauler(int fila, int columna) { return m_tauler.getTauler(fila, columna); }

private:
	Figura m_figura;
	Tauler m_tauler;
};


#endif

