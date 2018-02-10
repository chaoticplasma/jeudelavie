#include <iostream>
#include "classCellule.h"
using namespace std;

// Les constructeurs
Cellule::Cellule(){
  statut = 0;
  statutFutur = 0;
  posX = 0;
  posY = 0;
  nbVoisines = 0;
  voisines = NULL;
}

Cellule::Cellule(int x, int y){
  statut = 0;
  statutFutur = 0;
  posX = x;
  posY = y;
  nbVoisines = 0;
  voisines = NULL;
}

Cellule::Cellule(int x, int y, bool s){
  statut = s;
  statutFutur = 0;
  posX = x;
  posY = y;
  nbVoisines = 0;
  voisines = NULL;
}

// Destructeur
Cellule::~Cellule(){
  if(voisines != NULL)
    {
      delete [] voisines;
    }
}

bool Cellule::getStatut(void) const{
  return (statut);
}

void Cellule::setStatut(bool s){
  statut = s;
}

int Cellule::getPosX(void) const{
  return (posX);
}
int Cellule::getPosY(void) const{
  return (posY);
}

int Cellule::getNbVoisines(void) const{
  return (nbVoisines);
}
void Cellule::setPosX(int x){
  posX = x;
}
void Cellule::setPosY(int y){
  posY = y;
}

void Cellule::getVoisines(void) const{
  cout << "Voisines de (" << posX << "," << posY <<"):" << endl; 
  for(int i=0; i<nbVoisines; i++){
    cout<< "(" << (*(voisines+i))->getPosX() << "," << (*(voisines+i))->getPosY() << ")" << endl;
  }
}
void Cellule::setNbVoisines(int nb){
  nbVoisines = nb;
}

void Cellule::setVoisines(Cellule **listeVoisines, int nb){
  nbVoisines = nb;
  voisines = new Cellule*[nbVoisines];
  for(int i=0; i<nbVoisines; i++){
    *(voisines+i) = *(listeVoisines+i);
  }    
}

void Cellule::affiche(void) const{ // pour afficher 'X' ou ' ' selon le statut
  if(statut == 0)
    cout << "    -";
  else
    cout << "    O";
}

void Cellule::propagation(void){
  int voisinesVivants=0, i;
  for (i=0; i<nbVoisines; i++){
    if((*(voisines+i))->getStatut())
      voisinesVivants++;
  }
  if(statut){
    if(voisinesVivants < 2 || voisinesVivants > 3) // Actuellement vivant, mais il va mourir
      statutFutur = 0;
    else // rester vivant
      statutFutur = 1;
  }
  else{
    if(voisinesVivants == 3) // Actuellement mort, mais il va vivre
      statutFutur = 1;
    else // rester mourir
      statutFutur = 0;
  }
}

void Cellule::effectuePropagation(void){
  statut = statutFutur;
}
