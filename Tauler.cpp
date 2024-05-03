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
    int filesEliminades = 0;
    int contador = 1;

    int i = 0, j = 0;

    while (i < MAX_FILA)
    {
        j = 0;
        while (j < MAX_COL)
        {
            if (m_tauler[i][j] == 0)
            {
                j = 0;
                if (i < MAX_FILA - 1)
                {
                    i++;
                }
                else
                    return filesEliminades;
            }
            j++;
        }

        if (j == MAX_COL)
        {
            //cout << endl << endl << "DETECTO FILA" << endl << endl;
            eliminaFila(i);
            filesEliminades++;
        }
    }
    return filesEliminades;

}

void Tauler::eliminaFila(int index)
{

    for (int i = index; i > 1; i--)
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