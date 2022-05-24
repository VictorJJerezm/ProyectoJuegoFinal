#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "windows.h"

using namespace std;


int main()
{
    //Todas las funciones "system" dentro del main y de los metodos, afectan el funcionamiento del programa.

    //system("color 70"); //para cambiar el color del programa.
    gamemap map;
    player hero;
    map.drawPortada();

    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
      //system("cls"); //Para borrar la pantalla cada que se ingresa una opción.
        map.draw();
      } else
      {
        hero.resetToSafePosition();
        map.draw();
      }
    }


    return 0;
}
