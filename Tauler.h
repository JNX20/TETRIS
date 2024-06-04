#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 21;
const int MAX_COL = 11;

class Tauler
{
public:
    Tauler();

    int getTauler(int fila, int columna) { return m_tauler[fila][columna]; }
    int getImatge(int fila, int columna) { return (m_tauler[fila][columna] + 1); }
    void setTauler(int fila, int columna, int valor) { m_tauler[fila][columna] = valor; }
    int comprovarFiles();
    void eliminaFila(int fila);

private:
    int m_tauler[MAX_FILA][MAX_COL];

};
#endif
