#include <iostream>
using namespace std;


#ifndef Cellule_h
#define Cellule_h

class Cellule{
 private:
  bool statut;
  bool statutFutur;
  int posX;
  int posY;
  int nbVoisines;
  Cellule **voisines; //pour connaitre les voisines
  // int couleur; //pour futur
 public:
  // Constructeurs
  Cellule();
  Cellule(int x, int y);
  Cellule(int x, int y, bool s);
  ~Cellule();

  // Methodes
  void setNbVoisines(int nb);
  void setVoisines(Cellule **listeVoisines, int nb); // pour initialiser les voisines 
  bool getStatut(void) const;
  void setStatut(bool);
  int getPosX(void) const;
  int getPosY(void) const;
  void setPosX(int x);
  void setPosY(int y);
  void affiche(void) const; // pour afficher 'X' ou ' ' selon le statut
  void getVoisines(void) const;
  int getNbVoisines(void) const;
  void propagation(void); //verifier les voisines pour décider si la cellule va mourir ou non et mettre à jour statutFutur
  void effectuePropagation(void); // mettre à jour statut
};

#endif /* Cellule_h */


