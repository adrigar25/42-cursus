#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string lines[5];
    // Usamos static para evitar desbordar la pila (stack overflow)
    static long long nums[10000][10000] = {0}; // CAMBIO: long long para el resultado final grande
    long long total = 0; // CAMBIO: long long
    int index = 0;
    int begin = 0;
    int end = 0;
    
    for(int i = 0; i < 5; ++i) {
        std::getline(infile, lines[i]);
    }

    int j = 0;
    while(j < lines[0].size()) 
    {
        // Saltar espacios
        while (j < lines[0].size() && lines[0][j] == ' ' && lines[1][j] == ' ' && 
               lines[2][j] == ' ' && lines[3][j] == ' ')
        {
            j++;
        }
        
        if(j >= lines[0].size()) break;
        
        begin = j;
        end = begin;
        while (end < lines[0].size() && 
               (lines[0][end] != ' ' || lines[1][end] != ' ' || 
                lines[2][end] != ' ' || lines[3][end] != ' '))
        {
            end++;
        }
        j = end;
        
        int numCount = end - begin;
        int numIndex = 0;
        
        for(int k = begin; k < end; k++) 
        {
            long long num = 0;
            // ARREGLO 1: Leer de Arriba (0) a Abajo (3)
            for(int l = 0; l < 4; l++) 
            {   
                if(isdigit(lines[l][k])) // Asegurarse que es digito
                {
                    num = num * 10 + (lines[l][k] - '0');
                }
            }
            // Guardamos el numero
            nums[index][numCount - 1 - numIndex] = num;
            numIndex++;
        }

        // ARREGLO 2: Buscar el signo en todo el ancho del bloque
        char op = ' ';
        for(int s = begin; s < end; s++) {
            if(lines[4][s] == '*' || lines[4][s] == '+') {
                op = lines[4][s];
                break;
            }
        }
        
        if(op == '+') nums[index][9999] = 0;
        else nums[index][9999] = -1;

        // ARREGLO 3: Guardar CUANTOS números tiene este problema
        nums[index][9998] = numCount; 

        index++;
    }

    // Procesar sumas
    for(int col = 0; col < index; col++) 
    {
        long long result = 0;
        int count = nums[col][9998]; // Recuperamos la cantidad real de números

        if(nums[col][9999] == 0) // suma
        {
            result = 0;
            for(int row = 0; row < count; row++) // Usamos 'count', no 3 fijo
            {
                result += nums[col][row];
            }
        }
        else 
        {
            result = 1;
            for(int row = 0; row < count; row++) 
            {
                result *= nums[col][row];
            }
        }
        total += result;
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}
