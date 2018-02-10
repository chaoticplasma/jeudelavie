
#include <iostream>
#include "classCellule.h"
using namespace std;
int main(){
  int largeur, hauteur, i, j, k, m, n, p, nbV;
  Cellule *tabCell, **listeCellule;

  // Obtenir la taille de tableau
  cout << "Entrez la taille de Tableau" << endl;
  cout << "Largeur:";
  cin >> largeur;
  cout << endl << "Hauter:"; 
  cin >> hauteur;
  cout << endl;

  nbV = 5;
  tabCell = new Cellule[largeur*hauteur];

  k = 0;
  for (i=0; i<hauteur; i++){
    for(j=0; j <largeur; j++){
      (*(tabCell+k)).setPosX(j+1);
      (*(tabCell+k)).setPosY(i+1);      
      k++;
    }    
  }

  
  listeCellule = new Cellule*[nbV];
  for(i=0; i<nbV; i++){
      *(listeCellule+i) = tabCell+i*2;
      cout << (*(listeCellule+i))->getPosX();
      cout << (*(listeCellule+i))->getPosY() << endl;
  }
  tabCell->setVoisines(listeCellule, nbV);

  

}
