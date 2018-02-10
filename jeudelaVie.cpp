#include <iostream>
#include "classCellule.h"
using namespace std;
void initVoisinesNormale(Cellule *, int x,int y, const int& h, const int& l);
void initVoisinesBordures(Cellule *, int x,int y, const int& h, const int& l);
void initVoisinesCoins(Cellule *, int x,int y, const int& h, const int& l);

int main(){
  int largeur, hauteur, i, j, k, m, n, p, nbV;
  Cellule *tabCell;

  // Obtenir la taille de tableau
  cout << "Entrez la taille de Tableau" << endl;
  cout << "Largeur:";
  cin >> largeur;
  cout << "Hauter:"; 
  cin >> hauteur;
  cout << endl;
  tabCell = new Cellule[largeur*hauteur];

  k = 0;
  for (i=0; i<hauteur; i++){
    for(j=0; j <largeur; j++){
      (*(tabCell+k)).setPosX(i);
      (*(tabCell+k)).setPosY(j);      
      k++;
    }    
  }
  
  // Initialiser les voisines de chaque Cellule
  for (i=0; i<hauteur; i++){
    for(j=0; j <largeur; j++){
      if((i>0) && (j>0) && (i<hauteur-1) && (j<largeur-1)){
	(tabCell+i*largeur+j)->setNbVoisines(8);
	initVoisinesNormale(tabCell, i, j, hauteur, largeur);
      }
      else if((i==0)&&(j==0) ||(i==hauteur-1)&&(j==largeur-1) ||(i==hauteur-1)&&(j==0) || (i==0)&&(j==largeur-1)){	
	//(tabCell+i*largeur+j)->setNbVoisines(3);
	initVoisinesCoins(tabCell, i, j, hauteur, largeur);
      }
      else{	
	//(tabCell+i*largeur+j)->setNbVoisines(5);
	initVoisinesBordures(tabCell, i, j, hauteur, largeur);
      }
    }    
  }

  // cout << endl;
  // k = 0;
  // for (i=0; i<hauteur; i++){
  //   for(j=0; j <largeur; j++){
  //     cout << (tabCell+k) -> getNbVoisines();
  //     k++;
  //   }
  //   cout << endl;
  //   } 

  
// Affichage des positions de la tableau
  cout << endl;
  k = 0;
  for (i=0; i<hauteur; i++){
    for(j=0; j <largeur; j++){
      cout << "(" <<(tabCell+k) -> getPosX() << "," << (tabCell+k) -> getPosY() << ") ";   
      k++;
    }
    cout << endl;
    }

  int nbCelluleInit;
  // Obtenir les cellules initialiser comme vivant
  cout << "Initialization: Entrez les cellules de tableau qui vont etre vivant au debut" << endl;
  cout << "Combien des cellules?:  ";
  cin >> nbCelluleInit;
  for(i=0; i<nbCelluleInit; i++)
    {
      cout << endl << "Entrez le posX de Cellule" << i+1 << ":  ";
      cin >> m;
      cout << "Entrez le posX de Cellule" << i+1 << ":  ";
      cin >> n;
      (tabCell+m*largeur+n)->setStatut(1);
    }
  
  // Affichage de la tableau
  cout << " ";
  for(i=0; i <6*largeur; i++)
    cout << "_";
  cout << endl << endl;
  for (i=0; i<hauteur; i++)
    {
      cout << "|";
      for(j=0; j <largeur; j++)
	{
	  (tabCell+i*largeur+j) -> affiche();    
	  k++;
	}
      cout << "    |" <<endl;
    }
  cout << " ";
  for(i=0; i <6*largeur; i++)
    cout << "_";

  int nbExecute = 1;
  while(nbExecute)
    {
      cout << endl << "On va commencer la jeu de la vie" << endl << "Combien de fois vous voulez exectuer? (0 pour arreter)";
      cin >> nbExecute;
      for (k=0; k<nbExecute; k++)
	{
	  for (i=0; i<hauteur; i++) // Propagation mais pas effectue
	    {
	      for(j=0; j <largeur; j++)
		(tabCell+i*largeur+j)->propagation();
	    }
	  for (i=0; i<hauteur; i++) // Propagation
	    {
	      for(j=0; j <largeur; j++)
		(tabCell+i*largeur+j)->effectuePropagation();
	    }      
	  // affichage
	  cout << " ";
	  for(i=0; i <6*largeur; i++)
	    cout << "_";
	  cout << endl;
	  for (i=0; i<hauteur; i++)
	    {
	      cout << "|";
	      for(j=0; j <largeur; j++)
		{
		  (tabCell+i*largeur+j) -> affiche();    
		  k++;
		}
	      cout << "    |" <<endl;
	    }
	  cout << " ";
	  for(i=0; i <6*largeur; i++)
	    cout << "_";

	  // for (i=0; i<hauteur; i++) // affiche
	  //   {
	  //     for(j=0; j <largeur; j++)
	  // 	{
	  // 	  (tabCell+i*largeur+j)->affiche();    	  
	  // 	}
	  //     cout << endl;
	  //   }
	  cout << endl << endl;
	}
    }
  
  delete [] tabCell;
  return(0);
}
