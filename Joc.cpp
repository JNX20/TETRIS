#include "Joc.h"
#include <fstream>
#include "Partida.h"



void Joc::print(int fila, int columna, int filaOrigi, int columnaOrigi)
{
    if (m_figura.getForma(fila, columna) == m_figura.getColor())
        cout << m_figura.getForma(fila, columna) << " ";

    else
        cout << m_tauler.getTauler(filaOrigi, columnaOrigi) << " ";
}

int Joc::baixaFigura()
{
    int fila = m_figura.getFila(), columna = m_figura.getColumna(), contadorFila = 0, contadorColumna = 0, iniciColumna = 0;
    int finalColumna = 0;
    bool colisiona = false;
    bool potSeguir = true;

    if (m_figura.getBloqueig() == true)
        return m_tauler.comprovarFiles();

    bool columnaEsquerraForaTauler = false, columnaDretaForaTauler = false;

    if (columna - 1 < 0)
    {
        columnaEsquerraForaTauler = true;
        iniciColumna++;

        if (columna < 0)
            iniciColumna++;
    }
    if (columna + 2 >= MAX_COL)
    {
        columnaDretaForaTauler = true;
        finalColumna++;

        if (columna + 1 >= MAX_COL)
            finalColumna++;
    }


    bool filaInferiorForaTauler = false, filaSuperiorForaTauler = false;

    if (fila - 1 < 0)
    {
        filaSuperiorForaTauler = true;
        contadorFila++;
        if (fila < 0)
            contadorFila++;
    }

    for (int i = 0; i < MAX_FILA; i++)
    {
        if (columnaEsquerraForaTauler)
            contadorColumna = iniciColumna;
        else
            contadorColumna = 0;
        for (int j = 0; j < MAX_COL; j++)
        {
            if (i >= fila - 1 && i <= fila + 2 && j >= columna - 1 && j <= columna + 2)
            {
                if (m_figura.getForma(contadorFila, contadorColumna) != 0)
                {
                    if (m_tauler.getTauler(i + 1, j) != 0 || i + 1 >= MAX_FILA)
                    {
                        colisiona = true;
                        m_figura.setBloqueig(true);
                        afageixFitxa();
                        return m_tauler.comprovarFiles();
                    }

                    if (m_tauler.getTauler(i + 2, j) != 0 || i + 2 >= MAX_FILA)
                    {
                        potSeguir = false;
                        m_figura.baixar();
                        m_figura.setBloqueig(true);
                        afageixFitxa();
                        return m_tauler.comprovarFiles();
                    }
                }

                contadorColumna++;

                if (columnaDretaForaTauler)
                {
                    if (contadorColumna == 4 - finalColumna)
                    {
                        contadorColumna = 0;
                        contadorFila++;
                    }
                }

                else
                {
                    if (contadorColumna == 4)
                    {
                        contadorColumna = 0;
                        contadorFila++;
                    }
                }
            }
        }
    }

    if (!colisiona && potSeguir)
        m_figura.baixar();

    return 0;
}
bool Joc::baixaFigura(int& caselles)
{
    int fila = m_figura.getFila(), columna = m_figura.getColumna(), contadorFila = 0, contadorColumna = 0, iniciColumna = 0;
    int finalColumna = 0;
    bool colisiona = false;
    bool potSeguir = true;

    if (m_figura.getBloqueig() == true)
    {
        caselles = m_tauler.comprovarFiles();
        return false;
    }
        

    bool columnaEsquerraForaTauler = false, columnaDretaForaTauler = false;

    if (columna - 1 < 0)
    {
        columnaEsquerraForaTauler = true;
        iniciColumna++;

        if (columna < 0)
            iniciColumna++;
    }
    if (columna + 2 >= MAX_COL)
    {
        columnaDretaForaTauler = true;
        finalColumna++;

        if (columna + 1 >= MAX_COL)
            finalColumna++;
    }


    bool filaInferiorForaTauler = false, filaSuperiorForaTauler = false;

    if (fila - 1 < 0)
    {
        filaSuperiorForaTauler = true;
        contadorFila++;
        if (fila < 0)
            contadorFila++;
    }

    for (int i = 0; i < MAX_FILA; i++)
    {
        if (columnaEsquerraForaTauler)
            contadorColumna = iniciColumna;
        else
            contadorColumna = 0;
        for (int j = 0; j < MAX_COL; j++)
        {
            if (i >= fila - 1 && i <= fila + 2 && j >= columna - 1 && j <= columna + 2)
            {
                if (m_figura.getForma(contadorFila, contadorColumna) != 0)
                {
                    if (m_tauler.getTauler(i + 1, j) != 0 || i + 1 >= MAX_FILA)
                    {
                        colisiona = true;
                        m_figura.setBloqueig(true);
                        afageixFitxa();
                        caselles = m_tauler.comprovarFiles();
                        return false;
                    }

                    if (m_tauler.getTauler(i + 2, j) != 0 || i + 2 >= MAX_FILA)
                    {
                        potSeguir = false;
                        m_figura.baixar();
                        m_figura.setBloqueig(true);
                        afageixFitxa();
                        caselles = m_tauler.comprovarFiles();
                        return false;
                    }
                }

                contadorColumna++;

                if (columnaDretaForaTauler)
                {
                    if (contadorColumna == 4 - finalColumna)
                    {
                        contadorColumna = 0;
                        contadorFila++;
                    }
                }

                else
                {
                    if (contadorColumna == 4)
                    {
                        contadorColumna = 0;
                        contadorFila++;
                    }
                }
            }
        }
    }

    if (!colisiona && potSeguir)
    {
        m_figura.baixar();
        caselles = 0;

        return true;
    }
        
    caselles = 0;
    return false;
}

int Joc::baixaFiguraTotal()
{
    int casellaAEliminar;
    bool seguir = true;
    do
    {
        seguir = baixaFigura(casellaAEliminar);
    } while (seguir);

    return casellaAEliminar;

}

bool Joc::mouFigura(const int& dirx)
{
    int fila = m_figura.getFila(), columna = m_figura.getColumna(), contadorFila = 0, contadorColumna = 0;
    bool colisiona = false;

    for (int i = fila - 1; i <= fila + 2; i++)
    {
        contadorColumna = 0;
        for (int j = columna - 1; j <= columna + 2; j++)
        {
            if (m_figura.getForma(contadorFila, contadorColumna) != 0)
            {
                //cout << "CASELLA TROBADA" << "\n" << "\n";
                if (m_tauler.getTauler(i, j + dirx) != 0 || j + dirx < 0 || j + dirx >= MAX_COL)
                {
                    //cout << "\n" << "COLISIONA" << "\n" << "\n";
                    colisiona = true;
                    return false;
                }
            }
            contadorColumna++;
        }
        contadorFila++;
    }
    if (!colisiona)
    {
        //cout << "\n" << "NO COLISIONA" << "\n" << "\n";
        m_figura.desplacarLateral(dirx);
        return true;
    }

    else
        return false;
}

void Joc::inicialitza(const string& nomFitxer)
{
    int valorCasella, fila, columna, mtipus, mgir;
    ifstream fitxer;
    m_figura.setFigura(NO_FIGURA, 0, 0);

    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        fitxer >> mtipus >> fila >> columna >> mgir;


        TipusFigura tipus;

        tipus = (TipusFigura)mtipus;


        m_figura.setFigura(tipus, fila, columna);
        for (int i = 0; i < mgir; i++)
        {
            m_figura.girarFigura(GIR_HORARI);
        }


        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer >> valorCasella;
                m_tauler.setTauler(i, j, valorCasella);
            }
        }
    }

    fitxer.close();
}

void Joc::afageixFitxa()
{
    int fila = m_figura.getFila(), columna = m_figura.getColumna(), color = m_figura.getColor(), contadorFila = 0, contadorColumna = 0;


    for (int i = 0; i < 4; i++)
    {
        contadorColumna = 0;
        for (int j = 0; j < 4; j++)
        {
            if (m_figura.getForma(i, j) != 0)
                m_tauler.setTauler(fila + (i - 1), columna + (j - 1), color);

            contadorColumna++;
        }
        contadorFila++;
    }
    m_figura.setBloqueig(true);

    int figura = (rand() % 6) + 1;
    m_figura.setFigura((TipusFigura)figura, 1, 6);

    m_puntuacio += 10;
}

void Joc::printf(int fila, int columna, int filaOrigi, int columnaOrigi, ofstream& fitxer)
{
    if (m_figura.getForma(fila, columna) == m_figura.getColor() && m_figura.getBloqueig() == false)
        fitxer << m_figura.getForma(fila, columna);

    else
        fitxer << m_tauler.getTauler(filaOrigi, columnaOrigi);
}


void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;

    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        int fila = m_figura.getFila(), columna = m_figura.getColumna(), contadorFila = 0, contadorColumna = 0, iniciColumna = 0;
        int finalColumna = 0;
        bool columnaEsquerraForaTauler = false, columnaDretaForaTauler = false;

        if (columna - 1 < 0)
        {
            columnaEsquerraForaTauler = true;
            iniciColumna++;

            if (columna < 0)
                iniciColumna++;
        }
        if (columna + 2 >= 8)
        {
            columnaDretaForaTauler = true;
            finalColumna++;

            if (columna + 1 >= 8)
                finalColumna++;

        }


        bool filaInferiorForaTauler = false, filaSuperiorForaTauler = false;

        if (fila - 1 < 0)
        {
            filaSuperiorForaTauler = true;
            contadorFila++;
            if (fila < 0)
                contadorFila++;
        }

        for (int i = 0; i < MAX_FILA; i++)
        {
            if (columnaEsquerraForaTauler)
                contadorColumna = iniciColumna;

            for (int j = 0; j < MAX_COL; j++)
            {
                if (i >= fila - 1 && i <= fila + 2)
                {
                    if (j >= columna - 1 && j <= columna + 2)
                    {
                        printf(contadorFila, contadorColumna, i, j, fitxer);
                        contadorColumna++;

                        if (columnaDretaForaTauler)
                        {
                            if (contadorColumna == 4 - finalColumna)
                            {
                                contadorColumna = 0;
                                contadorFila++;
                            }
                        }

                        else
                        {
                            if (contadorColumna == 4)
                            {
                                contadorColumna = 0;
                                contadorFila++;
                            }
                        }

                    }
                    else
                        fitxer << m_tauler.getTauler(i, j) << " ";
                }
                else
                    fitxer << m_tauler.getTauler(i, j) << " ";
            }
            //cout << "\n";
        }

        //cout << "\n" << "\n" << "\n";

        fitxer.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio)
{
    bool colisiona = false;
    Figura figura;

    figura.setFila(m_figura.getFila());
    figura.setColumna(m_figura.getColumna());
    figura.setTipus(m_figura.getTipus());
    figura.setColor(m_figura.getColor());
    figura.setGir(m_figura.getGir());

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            figura.setForma(i, j, m_figura.getForma(i, j));
        }
    }


    figura.girarFigura(direccio);
    int fila = m_figura.getFila();
    int columna = m_figura.getColumna();
    int contadorFila = 0, contadorColumna = 0;

    if (columna - 1 < 0)
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            if (figura.getForma(i, 0) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Columna - 1 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }

        }
    }

    if (columna < 0)
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            if (figura.getForma(i, 1) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Columna fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (columna + 1 >= MAX_COL)
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            if (figura.getForma(i, 2) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Columna + 1 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (columna + 2 >= MAX_COL)
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            if (figura.getForma(i, 3) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Columna + 2 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (fila - 1 < 0)
    {
        for (int i = 0; i < MAX_COL; i++)
        {
            if (figura.getForma(0, i) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Fila - 1 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (fila < 0)
    {
        for (int i = 0; i < MAX_COL; i++)
        {
            if (figura.getForma(1, i) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Fila fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (fila + 1 >= MAX_FILA)
    {
        for (int i = 0; i < MAX_COL; i++)
        {
            if (figura.getForma(2, i) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Fila + 1 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }

    if (fila + 2 >= MAX_FILA)
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            if (figura.getForma(3, i) == (int)figura.getColor())
            {
                //cout << "\n" << "\n" << "\n" << "Fila + 2 fora i plena" << "\n" << "\n" << "\n";
                return false;
            }
        }
    }


    for (int i = fila - 1; i <= fila + 2; i++)
    {
        contadorColumna = 0;
        for (int j = columna - 1; j <= columna + 2; j++)
        {
            if (figura.getForma(contadorFila, contadorColumna) != 0)
            {
                if (m_tauler.getTauler(i, j) != 0)
                    return false;
            }
            contadorColumna++;
        }
        contadorFila++;
    }

    m_figura.girarFigura(direccio);
    return true;
}


void Joc::dibuixaTauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            if (m_tauler.getTauler(i, j) != 0)
            {
                GraphicManager::getInstance()->drawSprite((IMAGE_NAME)m_tauler.getImatge(i, j), POS_X_TAULER + ((j + 1) * MIDA_QUADRAT),
                    POS_Y_TAULER + ((i) * MIDA_QUADRAT), false);
            }
        }
    }
}

void Joc::dibuixaFigura()
{
    int fila = m_figura.getFila();
    int columna = m_figura.getColumna();

    int filaTauler, columnaTauler;
    for (int i = 0 ; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (m_figura.getForma(i, j) != 0)
            {
                filaTauler = fila + (i - 1);
                columnaTauler = columna + (j - 1);
                GraphicManager::getInstance()->drawSprite(m_figura.getImatge(), POS_X_TAULER + (columnaTauler + 1) * MIDA_QUADRAT,
                    POS_Y_TAULER + ((filaTauler)*MIDA_QUADRAT), false);
            }
        }
    }
}


void Joc::operator=(Figura figura)
{
    figura.setGir(m_figura.getGir());
    figura.setFila(m_figura.getFila());
    figura.setColumna(m_figura.getColumna());
    figura.setColor(m_figura.getColor());
    figura.setTipus(m_figura.getTipus());
    figura.setBloqueig(m_figura.getBloqueig());
    figura.setImatge(m_figura.getImatge());

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            figura.setForma(i, j, m_figura.getForma(i, j));
        }
    }
}

