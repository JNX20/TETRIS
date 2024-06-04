#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include<fstream>
#include "InfoJoc.h"
#include"GraphicManager.h"
#include "Joc.h"
#include<queue>

using namespace std;

class Partida 
{
public:
    Partida();
    void actualitza(double deltaTime);
    bool actualitzaModeTest(queue<int>& figures, queue<int>& moviments);
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    bool comprovarFigura(int fila, int columna);
    void escriuFitxerPuntuacions();

    void setFigura(TipusFigura figura, int fila, int columna) { m_joc.setFigura(figura, fila, columna); }

    bool getFinalPartida() { return m_partidaFinalitzada;  }

private:
    double m_temps;
    // Atributs necessaris només pels exemples d'utilització de la llibreria. 
    // S'hauran d'eliminar per la implementació del projecte
    //static const int MIDA = 4;
    //ColorFigura m_forma[MIDA][MIDA];
    //int m_fila, m_columna;
    Joc m_joc;
    bool m_mode;
    bool m_partidaFinalitzada;
    int m_puntuacio;
    int m_puntuacioTemporal;
    int m_nivell;

};

#endif 
