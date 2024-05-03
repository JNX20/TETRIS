#ifndef FIGURA_H
#define FIGURA_H


typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    ~Figura();
    DireccioGir getGir() { return m_gir; }
    int getFila() const { return m_fila; }
    int getColumna() const { return m_columna; }
    int getForma(int fila, int columna) const { return m_forma[fila][columna]; }
    ColorFigura getColor() const { return m_color; }
    TipusFigura getTipus() const { return m_tipus; }
    bool getBloqueig() const { return m_bloquejat; }

    void setFigura(const TipusFigura& forma, const int& fila, const int& columna);
    void setColor(const ColorFigura& color) { m_color = color; }
    void setGir(const DireccioGir& gir) { m_gir = gir; }
    void setFila(const int& fila) { m_fila = fila; }
    void setColumna(const int& columna) { m_columna = columna; }
    void setTipus(const TipusFigura& tipus) { m_tipus = tipus; }
    void setForma(const int& fila, const int& columna, const int& valorCasella) { m_forma[fila][columna] = valorCasella; }
    void setBloqueig(const bool& bloqueig) { m_bloquejat = bloqueig; }


    void girarFigura(DireccioGir gir);
    void desplacarLateral(int sentit);
    void baixar();


private:
    void transposada();
    void canviarFiles();
    void canviarColumnes();
    int m_fila;
    int m_columna;
    int m_forma[MAX_ALCADA][MAX_AMPLADA];
    TipusFigura m_tipus;
    ColorFigura m_color;
    DireccioGir m_gir;
    bool m_bloquejat;
};


#endif

