//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*; //Importe la bibliothèque

//declare
PrintWriter output;
Serial udSerial;

void setup() { // Crée un nouveau fichier dans le répertoire sketch
     udSerial = new Serial(this, "COM7", 19200); //Ouvre le port souhaité, en l'occurence COM3
     output = createWriter ("Battements.csv"); //Chaîne de caractères du nom du fichier 
}

 void draw() { //Boucle jusqu'à ce qu'elle soit arrêtée, en l'occurrence par la ligne 19
     if (udSerial.available() > 0) { //Fait le programme s'il y a des données sur la broche
         String SenVal = udSerial.readStringUntil('\n'); //Récupère les données qui arrivent en s'arrêtant au premier retour à la ligne.
         if (SenVal != null) { //Si la variable n'est pas nulle
           output.print(SenVal); //Écrit la donnée dans un fichier
         }
     }
 }
 void keyPressed(){ // Attend que l'utilisateur appuie sur le clavier
      output.flush(); // Écrit les données restantes dans le fichier
      output.close(); // Termine le fichier
      exit(); // Arrête le programme
 }
