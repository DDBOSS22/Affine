#include<iostream>
using namespace std;

// Fonction pour le chiffrement affine
string chiffrementAffine(string message, int coefficientA, int coefficientB)
{
    string messageChiffre = "";
    for (int i = 0; i < message.length(); i++)
    {
        if(message[i]!=' ')
            /* Chiffrement affine c = (a*x + b) % 26 */
            messageChiffre = messageChiffre + (char) ((((coefficientA * (message[i]-'A') ) + coefficientB) % 26) + 'A');
        else
            // Ajouter l'espace
            messageChiffre += message[i];
    }
    return messageChiffre;
}

int main(void)
{
    string message;
    int coefficientA, coefficientB;
    cout << "Entrez le message à chiffrer: ";
    getline(cin, message);
    cout << "Entrez la valeur du coefficient A: ";
    cin >> coefficientA;
    cout << "Entrez la valeur du coefficient B: ";
    cin >> coefficientB;
    string texteChiffre = chiffrementAffine(message, coefficientA, coefficientB);
    cout << "Texte chiffré: " << texteChiffre << endl;
    return 0;
}
