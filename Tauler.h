#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    Tauler();

    int getTauler(int fila, int columna) { return m_tauler[fila][columna]; }
    void setTauler(int fila, int columna, int valor) { m_tauler[fila][columna] = valor; }
    int comprovarFiles();
    void eliminaFila(int fila);

private:
    int m_tauler[MAX_FILA][MAX_COL];

};
#endif
