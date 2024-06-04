#include "Tauler.h"
#include <fstream>
#include <iostream>

using namespace std;

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = 0;
        }
    }
}

int Tauler::comprovarFiles()
{
    for (int i = 0; i < MAX_COL; i++)
    {
        if (m_tauler[0][i] != 0)
            return -1;
    }

    int filesEliminades = 0;
    int contador = 0;

    for (int i = 0; i < MAX_FILA; i++)
    {
        contador = 0;
        for (int j = 0; j < MAX_COL; j++)
        {
            if (m_tauler[i][j] != 0)
            {
                contador++;
            }

            if (contador == MAX_COL)
            {
                filesEliminades++;
                eliminaFila(i);
            }

        }
        contador = 0;
    }
    return filesEliminades;

}

void Tauler::eliminaFila(int index)
{

    for (int i = index; i > 0; i--)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = m_tauler[i - 1][j];
        }
    }

    for (int i = 0; i < MAX_COL; i++)
    {
        m_tauler[0][i] = 0;
    }

}
