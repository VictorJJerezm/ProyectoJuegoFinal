#include "gamemap.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

//Implementacion de toda la funcionabilidad del mapa del juego
using namespace std;
gamemap::gamemap()
{
    //ctor
    playerCell = NULL;
    loadMapFromFile();
    isGameOver = false;
}
void gamemap::draw(){
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemap::setPlayerCell(int playerX, int playerY)
{

    if (cell[playerX][playerY].isBlockedCell() == false)

        {
        if (cell[playerX][playerY].id == '$')

        {
            drawVictoria();

            isGameOver = true;
            return true;
            }


        else

            {
    if (cell[playerX][playerY].isBlockedCell() == false)

        {
        if (cell[playerX][playerY].id == '*')

            {
            drawDerrota();

            isGameOver = true;
            return true;
            }

                {
            if (playerCell != NULL)
                {
                playerCell->id=0;
                }

            playerCell = &cell[playerX][playerY];
            //Simbolo del jugador en el mapa "®"
            playerCell->id=169;
                }

        return true;
        }
    else
        {
        return false;
        }

            }

        }

}
void gamemap::loadMapFromFile()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("mapaG6.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                };
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
void gamemap::createMapToFile()
{
    ofstream myFile("mapaG6.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                if (i == 0 || i == 14)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 69)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}
void gamemap::drawPortada()
{
    string line;
    char userInput = ' ';
    ifstream myFile("PortadaG6.txt");

    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cout << "\t\t\t\t####################"<< endl;
        cout << "\t\t\t\t# 1. Iniciar juego #" << endl;
        cout << "\t\t\t\t# 2. Cerrar  juego #"<< endl;
        cout << "\t\t\t\t####################"<< endl;
        cin >> userInput;

        player hero;
        gamemap map;

        if(userInput == '1')
        {
            map.isGameOver == false;
        }
        else
        {
            exit(0);
        }

    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }

}
void gamemap::drawVictoria()
{
    system("color 2F");
    string line;
    char userInput = ' ';
    int choice;
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        system("cls");
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cout << " \t\t\tIngrese 1 salir: ";
        cin >> choice;
        player creditos;
        switch(choice)
            {

        case 1:
                exit(0);
                default:
                cout<<"\n\t\t\t -¡Opcion invalida!-";
            }
    }

    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}
void gamemap::drawDerrota()
{
    system("color 4F");
    string line;
    char userInput = ' ';
    int choice;
    ifstream myFile("derrota.txt");

    if(myFile.is_open())
    {

        //Se obtiene el mapa externo y se general el mapa de celdas

        system("cls");
        while( getline(myFile, line))

        {
            cout << line << endl;

        }
        myFile.close();

        cout << "" << endl;
        cout << " \t\t\tIngrese 1 salir: ";

        cin >> choice;
        gamemap map;

         switch(choice)
            {

        case 1:
                exit(0);
                default:
                cout<<"\n\t\t\t -¡Opcion invalida!-";
            }
    }
}

gamemap::~gamemap()
{
    //dtor
}
