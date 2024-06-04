#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <iostream>
#include "GraphicManager.h"
#include "InfoJoc.h"
#include<queue>

using namespace std;

class Joc
{
public:
	Joc() { m_puntuacio = 0; }
	//void actualitza(double deltaTime);
	void print(int fila, int columna, int filaOrigi, int columnaOrigi);
	void printf(int fila, int columna, int filaOrigi, int columnaOrigi, ofstream& fitxer);

	void inicialitza(const string& nomFitxer);
	void dibuixaTauler();
	void dibuixaFigura();

	bool giraFigura(DireccioGir direccio);
	bool mouFigura(const int& dirX);
	int baixaFigura();
	bool baixaFigura(int& caselles);
	int baixaFiguraTotal();

	void escriuTauler(const string& nomFitxer);
	void afageixFitxa();

	int getTauler(int fila, int columna) { return m_tauler.getTauler(fila, columna); }
	int getFilaFigura() { return m_figura.getFila(); }
	int getColumnaFigura() { return m_figura.getColumna(); }
	int getFormaFigura(int fila, int columna) { return m_figura.getForma(fila, columna); }
	int getPuntuacio() { return m_puntuacio; }
	bool getBloqueigFigura() { return m_figura.getBloqueig(); }
	Figura getFigura() { return m_figura; }
	ColorFigura getColorFigura() { return m_figura.getColor(); }
	TipusFigura getTipusFigura() {	return m_figura.getTipus();	}
	IMAGE_NAME getImatgeFigura() { return m_figura.getImatge(); }
	int getImatgeTauler(int fila, int columna) { return m_tauler.getImatge(fila, columna); }
	Tauler getTaulerJoc() { return m_tauler; }

	void setFigura(TipusFigura figura, int fila, int columna) { m_figura.setFigura(figura, fila, columna); }
	void setBloqueigFigura(bool bloqueig) { m_figura.setBloqueig(bloqueig); }

	void operator=(Figura figura);



private:
	Figura m_figura;
	Tauler m_tauler;
	int m_puntuacio;
};


#endif
