#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QMap>
#include <QTextStream>

QMap<QChar, QString> creerGrillePolybeAvecCle(const QString& cle) {
    QMap<QChar, QString> grillePolybe;
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString cleEnMajuscules = cle.toUpper();
    int ligne = 1;
    int colonne = 1;

    for (QChar lettre : cleEnMajuscules) {
        if (lettre.isLetter() && !grillePolybe.contains(lettre)) {
            grillePolybe[lettre] = QString::number(ligne) + QString::number(colonne);
            colonne++;
            if (colonne > 5) {
                colonne = 1;
                ligne++;
            }
        }
    }

    for (QChar lettre : alphabet) {
        if (!grillePolybe.contains(lettre)) {
            grillePolybe[lettre] = QString::number(ligne) + QString::number(colonne);
            colonne++;
            if (colonne > 5) {
                colonne = 1;
                ligne++;
            }
        }
    }

    return grillePolybe;
}

QString polybeCrypter(const QString& message, const QMap<QChar, QString>& grillePolybe) {
    QString messageCrypte;

    for (QChar lettre : message) {
        if (lettre.isLetter()) {
            QChar base = lettre.isUpper() ? 'A' : 'a';
            messageCrypte += grillePolybe.value(lettre.toUpper(), "") + " ";
        } else if (lettre == ' ') {
            messageCrypte += "0";
        }
    }

    return messageCrypte.trimmed();
}

QString polybeDecrypter(const QString& messageCrypte, const QMap<QChar, QString>& grillePolybe) {
    QString messageDecrypte;
    QStringList paires = messageCrypte.split(' ', QString::SkipEmptyParts);

    for (const QString& paire : paires) {
        if (paire == "0") {
            messageDecrypte += " ";
        } else {
            for (auto it = grillePolybe.begin(); it != grillePolybe.end(); ++it) {
                if (it.value() == paire) {
                    messageDecrypte += it.key();
                    break;
                }
            }
        }
    }

    return messageDecrypte;
}

int main() {
    int choix;
    QString cle;

    do {
        do {
            std::cout << "1- Chiffrement\n2- Déchiffrement\n3- Quitter\n";
            std::cout << "Entrez votre choix : ";
            std::cin >> choix;
        } while (choix < 1 || choix > 3);

        if (choix == 1) {
            QTextStream entree(stdin);
            std::cout << "Entrez le message à chiffrer : ";
            QString messageAChiffrer = entree.readLine();

            std::cout << "Entrez la cle de chiffrement : ";
            entree >> cle;

            QMap<QChar, QString> grillePolybe = creerGrillePolybeAvecCle(cle);

            QString messageChiffre = polybeCrypter(messageAChiffrer, grillePolybe);
            std::cout << "Message chiffre : " << messageChiffre.toStdString() << std::endl << std::endl;

        } else if (choix == 2) {
            QTextStream entree(stdin);
            std::cout << "Entrez le message à déchiffrer : ";
            QString messageADechiffrer = entree.readLine();

            std::cout << "Entrez la cle de chiffrement : ";
            entree >> cle;

            QMap<QChar, QString> grillePolybe = creerGrillePolybeAvecCle(cle);

            QString messageDechiffre = polybeDecrypter(messageADechiffrer, grillePolybe);
            std::cout << "Message dechiffre : " << messageDechiffre.toStdString() << std::endl << std::endl;
        }

    } while (choix != 3);

    return 0;
}
