#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// 1. LA MEMORIA (CACHÉ)
// Guardamos el resultado de cada coordenada aquí.
// -1 significa "no lo he calculado todavía".
// Usamos long long porque el número es gigante.
long long memo[150][200]; 
int width = 0; // Para saber el ancho y no salirnos

// 2. TU FUNCIÓN FINDEND (MODIFICADA)
unsigned long long findEnd(std::string lines[], int x, int y)
{
    // A) Caso Base: Si nos salimos por ABAJO, hemos completado 1 línea temporal.
    if (!lines[y][0]) return 1;

    // B) Caso Base: Si nos salimos por los LADOS, esa línea muere (0 caminos).
    if (x < 0 || x >= width) return 0;

    // C) CONSULTAR MEMORIA: ¿Ya he pasado por aquí antes?
    if (memo[y][x] != -1) return memo[y][x];

    unsigned long long paths = 0;
    
    // D) LÓGICA DE MOVIMIENTO
    // Miramos la casilla actual.
    // NOTA: Para evitar bucles infinitos, asumimos que tras dividirse, la gravedad actúa 
    // y bajamos a la siguiente fila (y + 1).
    
    if(lines[y][x] == '^')
    {
        // Se divide en dos: Izquierda-Abajo y Derecha-Abajo
        paths += findEnd(lines, x - 1, y + 1);
        paths += findEnd(lines, x + 1, y + 1);
    }
    else 
    {
        // Es '.' o 'S'. Cae recto hacia abajo.
        paths += findEnd(lines, x, y + 1);
    }

    // E) GUARDAR EN MEMORIA Y DEVOLVER
    return memo[y][x] = paths;
}

int main(void)
{
    std::ifstream infile("input.txt");
    std::string lines[142];
    int start = 0;
    
    for(int i=0; i<150; i++)
        for(int j=0; j<200; j++)
            memo[i][j] = -1;

    for(int i = 0; i < 141; i++)
    {
        std::getline(infile, lines[i]);
    }
    
    width = lines[0].size();

    for (start = 0; lines[0][start] && lines[0][start] != 'S'; start++);

    std::cout << "Start at: " << start << std::endl;

    unsigned long long totalTimelines = findEnd(lines, start, 0);

    std::cout << "Total Timelines: " << totalTimelines << std::endl;
    
    return 0;
}