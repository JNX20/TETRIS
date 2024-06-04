#include "Figura.h"
#include <iostream>

using namespace std;

Figura::Figura()
{
    m_fila = 0;
    m_columna = 0;
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            m_forma[i][j] = 0;
        }
    }

    m_tipus = NO_FIGURA;
    m_color = NO_COLOR;
    m_gir = GIR_HORARI;
    m_imatge = GRAFIC_QUADRAT_GROC;
    m_bloquejat = false;
        
}

Figura::~Figura()
{
}


void Figura::setFigura(const TipusFigura& forma, const int& fila, const int& columna)
{
    m_fila = fila;
    m_columna = columna;
    m_bloquejat = false;

    switch (forma)
    {
    case NO_FIGURA:
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_tipus = NO_FIGURA;
        m_imatge = GRAFIC_QUADRAT_GROC;
        break;
    }
    case FIGURA_O:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }

        m_color = COLOR_GROC;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                m_forma[i][j] = m_color;
            }
        }
        m_tipus = FIGURA_O;
        m_imatge = GRAFIC_QUADRAT_GROC;
        break;
    }

    case FIGURA_I:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_BLAUCEL;
        for (int i = 0; i < 4; i++)
        {
            m_forma[1][i] = m_color;
        }
        m_tipus = FIGURA_I;
        m_imatge = GRAFIC_QUADRAT_BLAUCEL;
        break;
    }
    case FIGURA_T:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_MAGENTA;
        m_forma[0][1] = m_color;
        m_forma[1][0] = m_color;
        m_forma[1][1] = m_color;
        m_forma[1][2] = m_color;

        m_tipus = FIGURA_T;
        m_imatge = GRAFIC_QUADRAT_MAGENTA;
        break;
    }
    case FIGURA_L:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_TARONJA;
        m_forma[0][2] = m_color;
        m_forma[1][0] = m_color;
        m_forma[1][1] = m_color;
        m_forma[1][2] = m_color;

        m_tipus = FIGURA_L;
        m_imatge = GRAFIC_QUADRAT_TARONJA;
        break;
    }
    case FIGURA_J:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_BLAUFOSC;
        m_forma[0][0] = m_color;
        m_forma[1][0] = m_color;
        m_forma[1][1] = m_color;
        m_forma[1][2] = m_color;

        m_tipus = FIGURA_J;
        m_imatge = GRAFIC_QUADRAT_BLAUFOSC;
        break;
    }
    case FIGURA_S:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_VERD;
        m_forma[1][0] = m_color;
        m_forma[0][1] = m_color;
        m_forma[1][1] = m_color;
        m_forma[0][2] = m_color;

        m_tipus = FIGURA_S;
        m_imatge = GRAFIC_QUADRAT_VERD;
        break;
    }

    case FIGURA_Z:
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_forma[i][j] = 0;
            }
        }
        m_color = COLOR_VERMELL;
        m_forma[0][0] = m_color;
        m_forma[0][1] = m_color;
        m_forma[1][1] = m_color;
        m_forma[1][2] = m_color;

        m_tipus = FIGURA_Z;
        m_imatge = GRAFIC_QUADRAT_VERMELL;
        break;
    }

    default:
        break;

    }
}


void Figura::desplacarLateral(int sentit)
{
    m_columna += sentit;
}

void Figura::baixar()
{
    m_fila += 1;
}

void Figura::transposada()
{
    int forma[MAX_ALCADA][MAX_AMPLADA];
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            forma[i][j] = m_forma[i][j];
        }

    }

    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            m_forma[i][j] = forma[j][i];
        }
    }
}

void Figura::canviarFiles()
{
    int fila[MAX_AMPLADA], fila1[MAX_AMPLADA];

    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        fila[i] = m_forma[0][i];
        fila1[i] = m_forma[2][i];
    }

    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        m_forma[0][i] = fila1[i];
        m_forma[2][i] = fila[i];
    }
}

void Figura::canviarColumnes()
{
    int columna[MAX_ALCADA], columna1[MAX_ALCADA];

    for (int i = 0; i < MAX_ALCADA; i++)
    {
        columna[i] = m_forma[i][0];
        columna1[i] = m_forma[i][2];
    }

    for (int i = 0; i < MAX_ALCADA; i++)
    {
        m_forma[i][0] = columna1[i];
        m_forma[i][2] = columna[i];
    }
}

void Figura::girarFigura(DireccioGir gir)
{
    if (m_tipus != FIGURA_O && m_tipus != FIGURA_I)
    {
        transposada();

        if (gir == GIR_HORARI)
            canviarColumnes();

        else
            canviarFiles();
    }

    else
    {
        if (m_tipus == FIGURA_I)
        {
            transposada();
            if (gir == GIR_HORARI)
            {
                int columna[MAX_ALCADA], columna1[MAX_ALCADA];

                for (int i = 0; i < MAX_AMPLADA; i++)
                {
                    columna[i] = m_forma[i][1];
                    columna1[i] = m_forma[i][2];
                }

                for (int i = 0; i < MAX_AMPLADA; i++)
                {
                    m_forma[i][1] = columna1[i];
                    m_forma[i][2] = columna[i];
                }
            }

            else
            {
                int fila[MAX_ALCADA], fila1[MAX_ALCADA];

                for (int i = 0; i < MAX_AMPLADA; i++)
                {
                    fila[i] = m_forma[1][i];
                    fila1[i] = m_forma[2][i];
                }

                for (int i = 0; i < MAX_AMPLADA; i++)
                {
                    m_forma[1][i] = fila1[i];
                    m_forma[2][i] = fila[i];
                }
            }
        }
    }
}

bool Figura::operator!=(Figura figura)
{
    if (figura.getGir() != getGir())
        return true;
    if (figura.getFila() != getFila())
        return true;
    if (figura.getColumna() != getColumna())
        return true;
    if (figura.getColor() != getColor())
        return true;
    if (figura.getTipus() != getTipus())
        return true;
    if (figura.getBloqueig() != getBloqueig())
        return true;
    if (figura.getImatge() != getImatge())
        return true;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (figura.getForma(i, j) != getForma(i, j))
                return false;
        }
    }

    return true;
}
