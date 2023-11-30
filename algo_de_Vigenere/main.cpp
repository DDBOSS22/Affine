#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int state = 0;

string chiffrer(string texte, int decalage) {
    string texte_chiffre = "";
    for (char& charact : texte) {
        if (isalpha(charact)) {
            if (isupper(charact)) {
                texte_chiffre += static_cast<char>((static_cast<int>(charact) + decalage - 'A') % 26 + 'A');
            } else {
                texte_chiffre += static_cast<char>((static_cast<int>(charact) + decalage - 'a') % 26 + 'a');
            }
        } else {
            texte_chiffre += charact;
        }
    }
    return texte_chiffre;
}

string dechiffrer(string texte_chiffre, int decalage) {
    string texte_dechiffre = "";
    for (char& charact : texte_chiffre) {
        if (isalpha(charact)) {
            if (isupper(charact)) {
                texte_dechiffre += static_cast<char>((static_cast<int>(charact) - decalage - 'A' + 26) % 26 + 'A');
            } else {
                texte_dechiffre += static_cast<char>((static_cast<int>(charact) - decalage - 'a' + 26) % 26 + 'a');
            }
        } else {
            texte_dechiffre += charact;
        }
    }
    return texte_dechiffre;
}

int main() {
    int choix;
    cout << "Choisissez l'opération :\n";
    cout << "1. Chiffrer\n";
    cout << "2. Déchiffrer\n";
    cin >> choix;

    string message;
    cout << "Saisissez le message : ";
    cin.ignore();  // Pour gérer les caractères en mémoire tampon après la saisie de choix.
    getline(cin, message);

    int cle;
    cout << "Saisissez la clé : ";
    cin >> cle;

    if (choix == 1) {
        string texte_chiffre = chiffrer(message, cle);
        cout << "Message chiffré : " << texte_chiffre << endl;
    } else if (choix == 2) {
        string texte_dechiffre = dechiffrer(message, cle);
        cout << "Message déchiffré : " << texte_dechiffre << endl;
    } else {
        cout << "Choix non valide.\n";
    }

    return 0;
}
