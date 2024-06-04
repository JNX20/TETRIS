#include "Partida.h"
#include "InfoJoc.h"
#include<conio.h>
#include "GraphicManager.h"
#include<random>

Partida::Partida()
{
    m_temps = 0;
    //for (int i = 0; i < MIDA; i++)
      //  for (int j = 0; j < MIDA; j++)
        //    m_forma[i][j] = NO_COLOR;
    //m_forma[0][0] = COLOR_BLAUFOSC;
    //m_forma[1][0] = COLOR_BLAUFOSC;
    //m_forma[1][1] = COLOR_BLAUFOSC;
    //m_forma[1][2] = COLOR_BLAUFOSC;
    //m_fila = 1;
    //m_columna = 5;
    m_mode = false;
    m_puntuacio = 0;
    m_puntuacioTemporal = 0;
    m_partidaFinalitzada = false;
    m_nivell = 0;
}


bool Partida::comprovarFigura(int fila, int columna)
{
    if (m_joc.getFormaFigura(fila, columna) != 0)
        return true;

    else
        return false;
}
void Partida::actualitza(double deltaTime)
{ 
    int puntuacio = 0;
    if (m_puntuacio >= 0)
    {
        GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
        GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
        m_joc.dibuixaTauler();
        m_joc.dibuixaFigura();
    }


    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        m_joc.mouFigura(1);

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        m_joc.mouFigura(-1);

    if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        m_joc.giraFigura(GIR_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        m_joc.giraFigura(GIR_ANTI_HORARI);

    bool bloquejat = false;
    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
    {
        puntuacio = m_joc.baixaFiguraTotal();
    }

    m_temps += deltaTime;
    if (m_temps > (0.5 - (m_nivell/100)))
    {
        puntuacio = m_joc.baixaFigura();
        m_temps = 0;
    }

    if (puntuacio < 0)
        m_puntuacioTemporal = -1;

    if (m_puntuacioTemporal < 0)
    {
        GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
        string msg = " GAME OVER  Apreta ESC per reiniciar";
        m_partidaFinalitzada = true;
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 85, POS_Y_TAULER - 50, 1.0, msg);
    }

    m_puntuacio = m_joc.getPuntuacio();

    if (puntuacio > 0)
        m_nivell += puntuacio;


    if (m_puntuacioTemporal >= 0)
    {
        string msg = "Puntuacio: " + to_string(m_puntuacio) + "  Nivell: " + to_string(m_nivell);
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
    }    
    
}

bool Partida::actualitzaModeTest(queue<int>& figures, queue<int>& moviments)
{
    //Screen pantalla;

    TipusMoviment moviment = (TipusMoviment)moviments.front();
    moviments.pop();
    switch (moviment)
    {
    case (MOVIMENT_ESQUERRA):
        m_joc.mouFigura(-1);
        break;
    case (MOVIMENT_DRETA):
        m_joc.mouFigura(1);
        break;
    case (MOVIMENT_GIR_HORARI):
        m_joc.giraFigura(GIR_HORARI);
        break;
    case (MOVIMENT_GIR_ANTI_HORARI):
        m_joc.giraFigura(GIR_ANTI_HORARI);
        break;
    case (MOVIMENT_BAIXA):
    {
        Figura figura = m_joc.getFigura();
        m_joc.baixaFigura();
        if (figura != m_joc.getFigura())
            m_joc.setBloqueigFigura(true);
        break;
    }
        
    case (MOVIMENT_BAIXA_FINAL):
        m_joc.baixaFiguraTotal();
        m_joc.setBloqueigFigura(true);
        break;
    default:
        break;
    }

    if (m_joc.getBloqueigFigura())
    {
        int tipus, fila, columna, gir;
        tipus = figures.front();
        figures.pop();
        fila = figures.front();
        figures.pop();
        columna = figures.front();
        figures.pop();
        gir = figures.front();
        figures.pop();
        m_joc.setFigura((TipusFigura)tipus, fila, columna);
        {
            for (int i = 0; i < gir; i++)
            {
                m_joc.giraFigura(GIR_HORARI);
            }
        }
    }

    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            cout << m_joc.getTauler(i, j) << " ";
        cout << "\n";
    }

    cout << "\n" << "\n";

    //pantalla.update();
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    m_joc.dibuixaTauler();
    m_joc.dibuixaFigura();

    
    if (m_joc.getTaulerJoc().comprovarFiles() != -1)
        return true;
    else
        return false;
}


void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    if (mode == 0)
    {
        // Guarda les dades dels fitxers que contenen les figures i els moviments en dues cues
        std::queue<int> figures;
        std::queue<int> moviments;

        ifstream fitxer;
        int valor;
        fitxer.open(fitxerFigures); //nomFitxerFigures);
        if (fitxer.is_open())
        {
            while (!fitxer.eof())
            {
                fitxer >> valor;
                if (!fitxer.eof())
                    figures.push(valor);
            }
        }
        fitxer.close();

        fitxer.open(fitxerMoviments); //nomFitxerMoviments);
        if (fitxer.is_open())
        {
            while (!fitxer.eof())
            {
                fitxer >> valor;
                if (!fitxer.eof())
                    moviments.push(valor);
            }
        }
        fitxer.close();

        Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

        pantalla.show();
        m_joc.inicialitza(fitxerInicial);

        while (!moviments.empty())
        {
            for (int i = 0; i < 10000; i++)
                cout << "___" << "\n";
            actualitzaModeTest(figures, moviments);
            //GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
            //GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

            pantalla.update();
        }
    }

    else
    {
        m_joc.inicialitza(fitxerInicial);
        int figura = (rand() % 6) + 1;
        m_joc.setFigura((TipusFigura)figura, 1, 6);
    }
}

