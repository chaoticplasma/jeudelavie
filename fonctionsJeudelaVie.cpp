#include <iostream>
#include "classCellule.h"
using namespace std;

void initVoisinesNormale(Cellule *tabCell, int i, int j, const int& hauteur, const int& largeur){
  int nbV = 8;
  Cellule ** listeVoisines = new Cellule*[nbV];
  *(listeVoisines+0) = (tabCell+(i-1)*largeur+(j-1));
  *(listeVoisines+1) = (tabCell+(i-1)*largeur+(j));
  *(listeVoisines+2) = (tabCell+(i-1)*largeur+(j+1));
  *(listeVoisines+3) = (tabCell+(i)*largeur+(j-1));
  *(listeVoisines+4) = (tabCell+(i)*largeur+(j+1));
  *(listeVoisines+5) = (tabCell+(i+1)*largeur+(j-1));
  *(listeVoisines+6) = (tabCell+(i+1)*largeur+(j));
  *(listeVoisines+7) = (tabCell+(i+1)*largeur+(j+1));
  (tabCell+i*largeur+j)->setVoisines(listeVoisines, nbV);
  delete [] listeVoisines;
}

void initVoisinesBordures(Cellule *tabCell, int i, int j, const int& hauteur, const int& largeur){
  int nbV = 5;
  Cellule ** listeVoisines = new Cellule*[nbV];  
  if((i==0)&&(j>0)&&(j<largeur-1)){ // bordure à gauche sauf les coins
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j-1));
    *(listeVoisines+1) = (tabCell+(i)*largeur+(j+1));
    *(listeVoisines+2) = (tabCell+(i+1)*largeur+(j-1));
    *(listeVoisines+3) = (tabCell+(i+1)*largeur+(j));
    *(listeVoisines+4) = (tabCell+(i+1)*largeur+(j+1));	  	  
  }
  else if((i==hauteur-1)&&(j>0)&&(j<largeur-1)){ // bordure à droite sauf les coins
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j-1));
    *(listeVoisines+1) = (tabCell+(i)*largeur+(j+1));
    *(listeVoisines+2) = (tabCell+(i-1)*largeur+(j-1));
    *(listeVoisines+3) = (tabCell+(i-1)*largeur+(j));
    *(listeVoisines+4) = (tabCell+(i-1)*largeur+(j+1));	  	  
  }	
  else if((j==0)&&(i>0)&&(i<hauteur-1)){ //bordure en haut sauf les coins
    *(listeVoisines+0) = (tabCell+(i-1)*largeur+(j));
    *(listeVoisines+1) = (tabCell+(i-1)*largeur+(j+1));
    *(listeVoisines+2) = (tabCell+(i)*largeur+(j+1));
    *(listeVoisines+3) = (tabCell+(i+1)*largeur+(j));
    *(listeVoisines+4) = (tabCell+(i+1)*largeur+(j+1));	  
  }
  else if((j==largeur-1)&&(i>0)&&(i<hauteur-1)){ // bordure en bas sauf les coins
    *(listeVoisines+0) = (tabCell+(i-1)*largeur+(j));
    *(listeVoisines+1) = (tabCell+(i-1)*largeur+(j-1));
    *(listeVoisines+2) = (tabCell+(i)*largeur+(j-1));
    *(listeVoisines+3) = (tabCell+(i+1)*largeur+(j));
    *(listeVoisines+4) = (tabCell+(i+1)*largeur+(j-1));	  
  }
  (tabCell+i*largeur+j)->setVoisines(listeVoisines, nbV);
  delete [] listeVoisines;
}

void initVoisinesCoins(Cellule *tabCell, int i, int j, const int& hauteur, const int& largeur){
  int nbV = 3;
  Cellule ** listeVoisines = new Cellule*[nbV];  
  if((i==0)&&(j==0)){
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j+1));
    *(listeVoisines+1) = (tabCell+(i+1)*largeur+(j));
    *(listeVoisines+2) = (tabCell+(i+1)*largeur+(j+1));
  }
  else if((i==0)&&(j==largeur-1)){
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j-1));	  
    *(listeVoisines+1) = (tabCell+(i+1)*largeur+(j));
    *(listeVoisines+2) = (tabCell+(i+1)*largeur+(j-1));	  
  }
  else if((i==hauteur-1)&&(j==largeur-1)){
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j-1));	  
    *(listeVoisines+1) = (tabCell+(i-1)*largeur+(j));
    *(listeVoisines+2) = (tabCell+(i-1)*largeur+(j-1));	  
  }	
  else if((i==hauteur-1)&&(j==0)){
    *(listeVoisines+0) = (tabCell+(i)*largeur+(j+1));	  
    *(listeVoisines+1) = (tabCell+(i-1)*largeur+(j));
    *(listeVoisines+2) = (tabCell+(i-1)*largeur+(j+1));	  
  }
  (tabCell+i*largeur+j)->setVoisines(listeVoisines, nbV);
  delete [] listeVoisines;  

}
